/********************************************************************************
** Form generated from reading UI file 'videowindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOWINDOW_H
#define UI_VIDEOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btn_play;
    QLabel *label_currentTime;
    QSlider *volumeSlider;
    QTabWidget *tabWidget;
    QWidget *tab_local_2;
    QListWidget *list_local_2;
    QWidget *tab_online_2;
    QListWidget *list_online_2;
    QSlider *progressSlider;
    QPushButton *btn_volume;
    QPushButton *btn_file;
    QPushButton *btn_pre;
    QLabel *label_totalTime;
    QPushButton *btn_quit;
    QPushButton *btn_next;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_fullScreen;

    void setupUi(QMainWindow *VideoWindow)
    {
        if (VideoWindow->objectName().isEmpty())
            VideoWindow->setObjectName("VideoWindow");
        VideoWindow->resize(1000, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VideoWindow->sizePolicy().hasHeightForWidth());
        VideoWindow->setSizePolicy(sizePolicy);
        VideoWindow->setMaximumSize(QSize(1000, 600));
        centralwidget = new QWidget(VideoWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("#centralwidget{\n"
"	background-color: qlineargradient(\n"
"    spread:pad, \n"
"    x1:0, y1:0, x2:0, y2:1,  /* \345\236\202\347\233\264\346\270\220\345\217\230\346\226\271\345\220\221 */\n"
"    stop:0 #789ABD,           /* \350\265\267\345\247\213\351\242\234\350\211\262\357\274\210\346\265\205\350\223\235\350\211\262\357\274\211 */\n"
"    stop:1 #E1B698             /* \347\273\223\346\235\237\351\242\234\350\211\262\357\274\210\346\267\261\347\201\260\350\211\262\357\274\211 */\n"
");\n"
"}\n"
"/* \344\270\273\345\256\271\345\231\250\351\200\217\346\230\216 */\n"
"QTabWidget {\n"
"    background: transparent;\n"
"    border: none;\n"
"}\n"
"/* \346\240\207\347\255\276\351\241\265\351\235\242\346\235\277\351\200\217\346\230\216 */\n"
"QTabWidget::pane {\n"
"    border: 0;\n"
"    background: transparent;\n"
"    margin: 0;\n"
"}\n"
"/* \346\240\207\347\255\276\346\240\217\351\200\217\346\230\216 */\n"
"QTabWidget::tab-bar {\n"
"    background: transparent;\n"
"    left: 5px; /* \350\260\203\346\225\264\346"
                        "\240\207\347\255\276\346\240\217\344\275\215\347\275\256 */\n"
"}\n"
"/* \345\215\225\344\270\252\346\240\207\347\255\276\351\241\265\346\240\267\345\274\217 */\n"
"QTabBar::tab {\n"
"    background: rgba(70, 70, 70, 150); /* \345\215\212\351\200\217\346\230\216\347\201\260\350\211\262 */\n"
"    color: white;\n"
"    border: 1px solid rgba(100, 100, 100, 100);\n"
"    border-bottom: none;\n"
"    padding: 5px 15px;\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"}\n"
"/* \351\200\211\344\270\255\347\232\204\346\240\207\347\255\276\351\241\265 */\n"
"QTabBar::tab:selected {\n"
"    background: rgba(120, 120, 120, 180); /* \346\233\264\344\270\215\351\200\217\346\230\216\347\232\204\351\200\211\344\270\255\347\212\266\346\200\201 */\n"
"    border-color: rgba(150, 150, 150, 150);\n"
"}\n"
"/* \346\240\207\347\255\276\351\241\265\345\206\205\345\256\271\345\214\272\345\237\237 */\n"
"QTabWidget > QStackedWidget {\n"
"    background: transparent;\n"
"}\n"
"/* \347\241\256\344\277\235"
                        "\346\211\200\346\234\211\345\255\220\351\203\250\344\273\266\347\273\247\346\211\277\351\200\217\346\230\216 */\n"
"QTabWidget QWidget {\n"
"    background: transparent;\n"
"}\n"
"\n"
"/* \351\200\217\346\230\216\350\203\214\346\231\257\350\275\250\351\201\223 */\n"
"QSlider::groove:horizontal {\n"
"    background: transparent;\n"
"    height: 4px;  /* \350\277\233\345\272\246\346\235\241\351\253\230\345\272\246 */\n"
"}\n"
"/* \345\267\262\350\277\233\345\272\246\351\203\250\345\210\206\351\242\234\350\211\262\357\274\210\347\244\272\344\276\213\346\251\231\350\211\262\357\274\211 */\n"
"QSlider::sub-page:horizontal {\n"
"    background: rgba(255, 123, 37, 0.5); \n"
"    border-radius: 2px;\n"
"}\n"
"/* \346\234\252\350\277\233\345\272\246\351\203\250\345\210\206\351\242\234\350\211\262\357\274\210\347\244\272\344\276\213\345\215\212\351\200\217\346\230\216\347\201\260\357\274\211 */\n"
"QSlider::add-page:horizontal {\n"
"    background: rgba(200, 200, 200, 50);\n"
"    border-radius: 2px;\n"
"}\n"
"/* \345\234"
                        "\206\345\275\242\346\273\221\345\235\227 */\n"
"QSlider::handle:horizontal {\n"
"    background: white;\n"
"    width: 10px;\n"
"    height: 10px;\n"
"    margin: -5px 0;  /* \345\236\202\347\233\264\345\261\205\344\270\255 */\n"
"    border-radius: 6px;\n"
"    border: 1px solid #E0E0E0;  /* \345\217\257\351\200\211\346\217\217\350\276\271 */\n"
"}\n"
"/*\351\200\200\345\207\272\346\240\267\345\274\217*/\n"
"#btn_quit{\n"
"	border-image: url(:/images/music/btn_quit_normal.png);\n"
"}\n"
"#btn_quit:hover{\n"
"	border-image: url(:/images/music/btn_quit_hover.png);\n"
"}\n"
"/*\346\267\273\345\212\240\346\226\207\344\273\266*/\n"
"#btn_file{\n"
"	border-image: url(:/images/music/btn_file_normal.png);\n"
"}\n"
"#btn_file:hover{\n"
"	border-image: url(:/images/music/btn_file_hover.png);\n"
"}\n"
"/* \344\270\212\344\270\200\351\246\226 */\n"
"#btn_pre{\n"
"	border-image: url(:/images/music/btn_pre_normal.png);\n"
"}\n"
"#btn_pre:hover{\n"
"	border-image: url(:/images/music/btn_pre_hover.png);\n"
"}\n"
"\n"
"/* \344"
                        "\270\213\344\270\200\351\246\226 */\n"
"#btn_next{\n"
"	border-image: url(:/images/music/btn_next_normal.png);\n"
"}\n"
"#btn_next:hover{\n"
"	border-image: url(:/images/music/btn_next_hover.png);\n"
"}\n"
"\n"
"/*\345\243\260\351\237\263*/\n"
"#btn_volume{\n"
"	border-image: url(:/images/music/btn_volume.png);\n"
"}\n"
"\n"
"/*\346\222\255\346\224\276\346\214\211\351\222\256*/\n"
"QPushButton#btn_play[mode='pause']{\n"
"   border-image: url(:/images/music/btn_pause_normal.png);\n"
"}\n"
"QPushButton#btn_play[mode='pause']:hover{  \n"
"   border-image: url(:/images/music/btn_pause_hover.png);\n"
"}\n"
"\n"
"QPushButton#btn_play[mode='play']{\n"
"   border-image: url(:/images/music/btn_play_normal.png);\n"
"}\n"
"QPushButton#btn_play[mode='play']:hover{\n"
"   border-image: url(:/images/music/btn_play_hover.png);\n"
"}\n"
"\n"
"/*\345\243\260\351\237\263\345\233\276\346\240\207*/\n"
"QPushButton#btn_volume[mode='unmute']{  \n"
"	border-image: url(:/images/music/btn_volume.png);\n"
"}\n"
"QPushButton#btn_volume["
                        "mode='mute']{  \n"
"	border-image: url(:/images/music/btn_mute.png);\n"
"}\n"
"#btn_fullScreen{\n"
"	border-image: url(:/images/music/fullScreen.png);\n"
"}\n"
""));
        btn_play = new QPushButton(centralwidget);
        btn_play->setObjectName("btn_play");
        btn_play->setGeometry(QRect(473, 557, 30, 30));
        label_currentTime = new QLabel(centralwidget);
        label_currentTime->setObjectName("label_currentTime");
        label_currentTime->setGeometry(QRect(77, 564, 50, 20));
        label_currentTime->setAlignment(Qt::AlignmentFlag::AlignCenter);
        volumeSlider = new QSlider(centralwidget);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setGeometry(QRect(591, 560, 101, 22));
        volumeSlider->setPageStep(1);
        volumeSlider->setValue(50);
        volumeSlider->setOrientation(Qt::Orientation::Horizontal);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(17, 10, 191, 501));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        tabWidget->setFont(font);
        tabWidget->setAcceptDrops(false);
        tabWidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabWidget->setTabPosition(QTabWidget::TabPosition::North);
        tabWidget->setTabShape(QTabWidget::TabShape::Triangular);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tab_local_2 = new QWidget();
        tab_local_2->setObjectName("tab_local_2");
        list_local_2 = new QListWidget(tab_local_2);
        list_local_2->setObjectName("list_local_2");
        list_local_2->setGeometry(QRect(0, 0, 191, 471));
        tabWidget->addTab(tab_local_2, QString());
        tab_online_2 = new QWidget();
        tab_online_2->setObjectName("tab_online_2");
        tab_online_2->setStyleSheet(QString::fromUtf8(""));
        list_online_2 = new QListWidget(tab_online_2);
        list_online_2->setObjectName("list_online_2");
        list_online_2->setGeometry(QRect(0, 0, 191, 471));
        tabWidget->addTab(tab_online_2, QString());
        progressSlider = new QSlider(centralwidget);
        progressSlider->setObjectName("progressSlider");
        progressSlider->setGeometry(QRect(17, 522, 931, 22));
        progressSlider->setMaximum(99);
        progressSlider->setSingleStep(0);
        progressSlider->setPageStep(1);
        progressSlider->setOrientation(Qt::Orientation::Horizontal);
        btn_volume = new QPushButton(centralwidget);
        btn_volume->setObjectName("btn_volume");
        btn_volume->setGeometry(QRect(564, 559, 24, 24));
        btn_file = new QPushButton(centralwidget);
        btn_file->setObjectName("btn_file");
        btn_file->setGeometry(QRect(37, 558, 26, 26));
        btn_file->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        btn_pre = new QPushButton(centralwidget);
        btn_pre->setObjectName("btn_pre");
        btn_pre->setGeometry(QRect(425, 557, 30, 30));
        label_totalTime = new QLabel(centralwidget);
        label_totalTime->setObjectName("label_totalTime");
        label_totalTime->setGeometry(QRect(109, 564, 50, 20));
        label_totalTime->setAlignment(Qt::AlignmentFlag::AlignCenter);
        btn_quit = new QPushButton(centralwidget);
        btn_quit->setObjectName("btn_quit");
        btn_quit->setGeometry(QRect(960, 20, 24, 24));
        btn_quit->setIconSize(QSize(18, 18));
        btn_next = new QPushButton(centralwidget);
        btn_next->setObjectName("btn_next");
        btn_next->setGeometry(QRect(520, 557, 30, 30));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(219, 39, 731, 471));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_fullScreen = new QPushButton(centralwidget);
        btn_fullScreen->setObjectName("btn_fullScreen");
        btn_fullScreen->setGeometry(QRect(920, 558, 26, 26));
        VideoWindow->setCentralWidget(centralwidget);

        retranslateUi(VideoWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(VideoWindow);
    } // setupUi

    void retranslateUi(QMainWindow *VideoWindow)
    {
        VideoWindow->setWindowTitle(QCoreApplication::translate("VideoWindow", "\350\275\246\350\275\275\345\244\232\345\252\222\344\275\223-\350\247\206\351\242\221", nullptr));
        btn_play->setText(QString());
        label_currentTime->setText(QCoreApplication::translate("VideoWindow", "00:00", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_local_2), QCoreApplication::translate("VideoWindow", "\346\234\254\345\234\260\345\210\227\350\241\250", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_online_2), QCoreApplication::translate("VideoWindow", "\345\234\250\347\272\277\345\210\227\350\241\250", nullptr));
        btn_volume->setText(QString());
        btn_file->setText(QString());
        btn_pre->setText(QString());
        label_totalTime->setText(QCoreApplication::translate("VideoWindow", "00:00", nullptr));
        btn_quit->setText(QString());
        btn_next->setText(QString());
        btn_fullScreen->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VideoWindow: public Ui_VideoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOWINDOW_H
