#include "photowindow.h"
#include "ui_photowindow.h"
#include <QMenu>
#include <QDebug>
#include <QFileDialog>
#include "common/common.h"
#include <QPixmap>
#include <QFileInfo>
#include <QListWidget>
#include <QListWidgetItem>
#include <QTransform>
#include <QMessageBox>

// 照片窗口类：实现照片浏览、缩放、旋转、文件管理等功能
PhotoWindow::PhotoWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PhotoWindow)
{
    ui->setupUi(this);

    this->initPhotoWin();
}

PhotoWindow::~PhotoWindow()
{
    delete ui; // 释放UI资源
}

void PhotoWindow::initPhotoWin()
{
    // 创建文件操作菜单（单张/多张图片打开）
    QMenu *menu=new QMenu();
    menu->addAction("打开单张图片");
    menu->addAction("打开多张图片");
    ui->btn_files->setMenu(menu); // 绑定菜单到工具按钮
}

// 显示图片核心函数：加载图片并计算自适应显示尺寸
void PhotoWindow::showImage(QString filePath)
{
    // 加载原始图片并重置缩放状态
    originalPixmap.load(filePath);       // 保存原始图片数据（用于高质量缩放）
    currentScale = 1.0;                  // 初始化缩放比例为100%

    // 记录原始图片尺寸并计算自适应显示尺寸（保持宽高比）
    adaptiveHeight = originalPixmap.height();
    adaptiveWidth = originalPixmap.width();
    double scale = (double)adaptiveHeight / adaptiveWidth; // 计算宽高比

    // 限制图片最大显示尺寸为标签控件大小
    if (adaptiveHeight > ui->label_img->height()) {
        adaptiveHeight = ui->label_img->height();
        adaptiveWidth = adaptiveHeight / scale; // 按比例计算宽度
    }
    if (adaptiveWidth > ui->label_img->width()) {
        adaptiveWidth = ui->label_img->width();
        adaptiveHeight = scale * adaptiveWidth; // 按比例计算高度
    }

    // 高质量缩放图片并显示（抗锯齿处理）
    QPixmap scaledPixmap = originalPixmap.scaled(
        adaptiveWidth, adaptiveHeight,
        Qt::KeepAspectRatio,       // 保持原始宽高比
        Qt::SmoothTransformation   // 启用高质量抗锯齿
        );
    ui->label_img->setPixmap(scaledPixmap);

    // 设置窗口标题为当前图片文件名
    this->setWindowTitle(ui->list_files->currentItem()->text());
}

// 检查文件是否已存在于列表（通过文件路径唯一标识）
bool PhotoWindow::isFileExistInList(const QString &filePath) {
    for (int i=0; i<ui->list_files->count(); ++i) {
        // 比较列表中已有文件的路径（UserRole存储完整路径）
        if (ui->list_files->item(i)->data(Qt::UserRole).toString() == filePath) {
            return true;
        }
    }
    return false;
}

// 点击文件按钮时显示菜单（触发菜单弹出）
void PhotoWindow::on_btn_files_clicked()
{
    ui->btn_files->showMenu(); // 显示关联的文件操作菜单
}

// 退出按钮逻辑：返回上级窗口（隐藏当前窗口）
void PhotoWindow::on_btn_quit_clicked()
{
    this->parentWidget()->show(); // 显示父窗口
    this->hide();                 // 隐藏当前窗口
}

// 处理文件菜单选择（打开单张/多张图片）
void PhotoWindow::on_btn_files_triggered(QAction *action)
{
    QString menuName = action->text(); // 获取点击的菜单项名称

    // 处理单张图片打开
    if (menuName == "打开单张图片") {
        // 打开文件对话框（限制图片格式）
        QString filePath = QFileDialog::getOpenFileName(this, tr("打开单张图片"),
                                                        FILES_OPEN_PATH,
                                                        tr("Images (*.png *.jpg *.jpeg)"));
        QFileInfo fileInfo(filePath);

        // 检查重复添加（避免同一文件多次加入列表）
        if (isFileExistInList(filePath)) {
            QMessageBox::information(this, "消息", "不能重复添加", QMessageBox::Ok);
            return;
        }

        // 创建列表项并添加到文件列表（显示文件名，存储完整路径）
        QListWidgetItem *item = new QListWidgetItem();
        item->setText(fileInfo.fileName());       // 显示文件名
        item->setData(Qt::UserRole, filePath);    // 存储文件完整路径
        ui->list_files->addItem(item);

        // 首次添加文件时自动显示
        if (ui->list_files->count() == 1) {
            ui->list_files->setCurrentRow(0); // 选中第一个文件
            this->showImage(filePath);        // 显示图片
        }
    }
    // 处理多张图片打开（逻辑与单张类似，循环添加）
    else if (menuName == "打开多张图片") {
        QStringList filePaths = QFileDialog::getOpenFileNames(this, tr("打开单张图片"),
                                                              FILES_OPEN_PATH,
                                                              tr("Images (*.png *.jpg *.jpeg)"));

        // 逐个检查并添加文件（防止重复）
        for (QString filePath : filePaths) {
            QFileInfo fileInfo(filePath);
            if (isFileExistInList(filePath)) {
                QMessageBox::information(this, "消息", "不能重复添加", QMessageBox::Ok);
                return;
            }
            QListWidgetItem *item = new QListWidgetItem();
            item->setText(fileInfo.fileName());
            item->setData(Qt::UserRole, filePath);
            ui->list_files->addItem(item);
        }

        // 全部添加成功后显示第一张图片
        if (filePaths.size() == ui->list_files->count()) {
            ui->list_files->setCurrentRow(0);
            this->showImage(filePaths.at(0));
        }
    }
}

// 双击列表项时显示对应图片（快速切换图片）
void PhotoWindow::on_list_files_itemDoubleClicked(QListWidgetItem *item)
{
    QString filePath = item->data(Qt::UserRole).toString(); // 获取存储的文件路径
    this->showImage(filePath); // 调用图片显示函数
}

// 上一张图片按钮逻辑：循环切换文件列表（支持首尾相连）
void PhotoWindow::on_btn_pre_clicked()
{
    if (ui->list_files->count() == 0) return; // 列表为空时返回

    int index = ui->list_files->currentRow();
    // 循环索引计算：负数索引转换为正数（例如-1转为最后一个索引）
    index = (index - 1 + ui->list_files->count()) % ui->list_files->count();
    ui->list_files->setCurrentRow(index); // 选中目标行

    QString filePath = ui->list_files->currentItem()->data(Qt::UserRole).toString();
    this->showImage(filePath); // 显示目标图片
}

// 下一张图片按钮逻辑：循环切换文件列表（支持首尾相连）
void PhotoWindow::on_btn_next_clicked()
{
    if (ui->list_files->count() == 0) return; // 列表为空时返回

    int index = ui->list_files->currentRow();
    // 循环索引计算：超过末尾时回到开头（例如n+1转为0）
    index = (index + 1) % ui->list_files->count();
    ui->list_files->setCurrentRow(index); // 选中目标行

    QString filePath = ui->list_files->currentItem()->data(Qt::UserRole).toString();
    this->showImage(filePath); // 显示目标图片
}

// 放大图片按钮逻辑：按比例放大（基于初始自适应尺寸）
void PhotoWindow::on_btn_enlarge_clicked()
{
    if (originalPixmap.isNull()) return; // 图片未加载时返回

    currentScale *= 1.1; // 每次放大10%（当前比例=原始比例*1.1）

    // 限制最大放大倍数（防止图片过大）
    if (currentScale > 10) {
        currentScale = 10;
        QMessageBox::information(this, "提示", "图片已达到最大尺寸");
        return;
    }
    qDebug()<<currentScale; // 打印当前缩放比例（调试用）
    // 基于初始自适应尺寸计算新尺寸（保持宽高比）
    double w = adaptiveWidth * currentScale;
    double h = adaptiveHeight * currentScale;

    // 高质量缩放并显示（使用原始图片数据保证清晰度）
    QPixmap scaledPixmap = originalPixmap.scaled(
        w, h,
        Qt::KeepAspectRatio,
        Qt::SmoothTransformation
        );
    ui->label_img->setPixmap(scaledPixmap);
}

// 缩小图片按钮逻辑：按比例缩小（基于初始自适应尺寸）
void PhotoWindow::on_btn_shrink_clicked()
{
    if (originalPixmap.isNull()) return; // 图片未加载时返回

    currentScale *= 0.9; // 每次缩小10%（当前比例=原始比例*0.9）

    // 限制最小缩小倍数（防止图片过小）
    if (currentScale < 0.1) {
        currentScale = 0.1;
        QMessageBox::information(this, "提示", "图片已达到最小尺寸");
        return;
    }
    qDebug()<<currentScale; // 打印当前缩放比例（调试用）
    // 基于初始自适应尺寸计算新尺寸（保持宽高比）
    double w = adaptiveWidth * currentScale;
    double h = adaptiveHeight * currentScale;

    // 高质量缩放并显示（使用原始图片数据保证清晰度）
    QPixmap scaledPixmap = originalPixmap.scaled(
        w, h,
        Qt::KeepAspectRatio,
        Qt::SmoothTransformation
        );
    ui->label_img->setPixmap(scaledPixmap);
}

// 向左旋转按钮逻辑：逆时针旋转90度（基于当前显示图片）
void PhotoWindow::on_btn_left_clicked()
{
    QPixmap pixmap = ui->label_img->pixmap(); // 获取当前显示的图片
    QTransform transform;
    transform.rotate(90); // 创建旋转90度的变换矩阵

    // 应用旋转变换（保持图像平滑）
    QPixmap map = pixmap.transformed(transform, Qt::SmoothTransformation);
    ui->label_img->setPixmap(map); // 显示旋转后的图片
}

// 向右旋转按钮逻辑：顺时针旋转90度（基于当前显示图片）
void PhotoWindow::on_btn_right_clicked()
{
    QPixmap pixmap = ui->label_img->pixmap(); // 获取当前显示的图片
    QTransform transform;
    transform.rotate(-90); // 创建旋转-90度的变换矩阵

    // 应用旋转变换（保持图像平滑）
    QPixmap map = pixmap.transformed(transform, Qt::SmoothTransformation);
    ui->label_img->setPixmap(map); // 显示旋转后的图片
}

// 删除当前选中图片按钮逻辑：从列表中移除并更新显示
void PhotoWindow::on_btn_del_clicked()
{
    int count = ui->list_files->count();
    if (count == 0) {
        ui->label_img->clear(); // 列表为空时清空显示
        return;
    }

    int row = ui->list_files->currentRow();
    ui->list_files->takeItem(row); // 从列表中移除当前项

    count = ui->list_files->count();
    if (count == 0) {
        ui->label_img->clear(); // 移除后列表为空时清空显示
        return;
    }

    // 显示删除后的当前项（自动选中下一项）
    QString filePath = ui->list_files->currentItem()->data(Qt::UserRole).toString();
    this->showImage(filePath);
}
