#ifndef PHOTOWINDOW_H
#define PHOTOWINDOW_H

#include <QMainWindow>
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
namespace Ui {
class PhotoWindow;
}

class PhotoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PhotoWindow(QWidget *parent = nullptr);
    ~PhotoWindow();
    void initPhotoWin();

    void showImage(QString filePath);
    bool isFileExistInList(const QString &filePath);
    void applyScaledImage();
private slots:
    void on_btn_quit_clicked();


    void on_btn_files_clicked();

    void on_btn_files_triggered(QAction *arg1);

    void on_list_files_itemDoubleClicked(QListWidgetItem *item);

    void on_btn_pre_clicked();

    void on_btn_next_clicked();

    void on_btn_enlarge_clicked();

    void on_btn_shrink_clicked();

    void on_btn_left_clicked();

    void on_btn_right_clicked();

    void on_btn_del_clicked();

private:
    Ui::PhotoWindow *ui;
    QPixmap originalPixmap;  // 用于保存原始图片
    double currentScale = 1.0;  // 当前缩放比例
    double adaptiveHeight;   //自适应后的高宽
    double adaptiveWidth;
};

#endif // PHOTOWINDOW_H
