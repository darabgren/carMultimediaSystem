/********************************************************************************
** Form generated from reading UI file 'musicwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICWINDOW_H
#define UI_MUSICWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <music/lyriccontainer.h>

QT_BEGIN_NAMESPACE

class Ui_MusicWindow
{
public:
    QWidget *centralwidget;
    QSlider *progressSlider;
    QPushButton *btn_play;
    QPushButton *btn_pre;
    QPushButton *btn_next;
    QPushButton *btn_volume;
    QPushButton *btn_file;
    QTabWidget *tabWidget;
    QWidget *tab_local;
    QListWidget *list_local;
    QWidget *tab_online;
    QListWidget *list_online;
    QPushButton *btn_quit;
    QSlider *volumeSlider;
    QLabel *label_currentTime;
    QLabel *label_totalTime;
    LyricContainer *lyricContainer;
    QLabel *lyricLine0;
    QLabel *lyricLine1;
    QLabel *lyricLine2;
    QLabel *lyricLine3;
    QLabel *lyricLine4;

    void setupUi(QMainWindow *MusicWindow)
    {
        if (MusicWindow->objectName().isEmpty())
            MusicWindow->setObjectName("MusicWindow");
        MusicWindow->resize(1000, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MusicWindow->sizePolicy().hasHeightForWidth());
        MusicWindow->setSizePolicy(sizePolicy);
        MusicWindow->setMinimumSize(QSize(800, 500));
        MusicWindow->setMaximumSize(QSize(1000, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/winIcon.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MusicWindow->setWindowIcon(icon);
        MusicWindow->setAutoFillBackground(false);
        MusicWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MusicWindow);
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
"\n"
"/*\346\255\214\350\257\215\345\256\271\345\231\250*/\n"
"QFrame#lyricContainer {\n"
"	\n"
"	background-image: url(:/images/background.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-size: cover; /*cover \350\207\252\351\200\202\345\272\224\345\256\271\345\231\250\345\244\247\345\260\217 */\n"
"    border-radius: 12px;\n"
"    padding: 15px;\n"
"}\n"
"#lyricLine0,#lyricLine1,#lyricLine3,#lyricLine4{\n"
"	color: rgb(81, 81, 81);\n"
"	font-size:13pt;\n"
"}\n"
"#lyricLine2{\n"
"	color: rgb(255, 228, 181);\n"
"	font-size:16pt;\n"
"	font-weight: bold;\n"
"}"));
        progressSlider = new QSlider(centralwidget);
        progressSlider->setObjectName("progressSlider");
        progressSlider->setGeometry(QRect(20, 512, 901, 22));
        progressSlider->setMaximum(99);
        progressSlider->setSingleStep(0);
        progressSlider->setPageStep(1);
        progressSlider->setOrientation(Qt::Orientation::Horizontal);
        btn_play = new QPushButton(centralwidget);
        btn_play->setObjectName("btn_play");
        btn_play->setGeometry(QRect(532, 547, 30, 30));
        btn_pre = new QPushButton(centralwidget);
        btn_pre->setObjectName("btn_pre");
        btn_pre->setGeometry(QRect(484, 547, 30, 30));
        btn_next = new QPushButton(centralwidget);
        btn_next->setObjectName("btn_next");
        btn_next->setGeometry(QRect(579, 547, 30, 30));
        btn_volume = new QPushButton(centralwidget);
        btn_volume->setObjectName("btn_volume");
        btn_volume->setGeometry(QRect(623, 549, 24, 24));
        btn_file = new QPushButton(centralwidget);
        btn_file->setObjectName("btn_file");
        btn_file->setGeometry(QRect(40, 548, 26, 26));
        btn_file->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 10, 221, 481));
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
        tab_local = new QWidget();
        tab_local->setObjectName("tab_local");
        list_local = new QListWidget(tab_local);
        list_local->setObjectName("list_local");
        list_local->setGeometry(QRect(0, 0, 211, 451));
        tabWidget->addTab(tab_local, QString());
        tab_online = new QWidget();
        tab_online->setObjectName("tab_online");
        tab_online->setStyleSheet(QString::fromUtf8(""));
        list_online = new QListWidget(tab_online);
        list_online->setObjectName("list_online");
        list_online->setGeometry(QRect(0, 0, 211, 451));
        tabWidget->addTab(tab_online, QString());
        btn_quit = new QPushButton(centralwidget);
        btn_quit->setObjectName("btn_quit");
        btn_quit->setGeometry(QRect(940, 20, 24, 24));
        btn_quit->setIconSize(QSize(18, 18));
        volumeSlider = new QSlider(centralwidget);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setGeometry(QRect(650, 550, 101, 22));
        volumeSlider->setPageStep(1);
        volumeSlider->setValue(50);
        volumeSlider->setOrientation(Qt::Orientation::Horizontal);
        label_currentTime = new QLabel(centralwidget);
        label_currentTime->setObjectName("label_currentTime");
        label_currentTime->setGeometry(QRect(80, 554, 50, 20));
        label_currentTime->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_totalTime = new QLabel(centralwidget);
        label_totalTime->setObjectName("label_totalTime");
        label_totalTime->setGeometry(QRect(112, 554, 50, 20));
        label_totalTime->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lyricContainer = new LyricContainer(centralwidget);
        lyricContainer->setObjectName("lyricContainer");
        lyricContainer->setGeometry(QRect(280, 40, 641, 461));
        lyricContainer->setFrameShape(QFrame::Shape::NoFrame);
        lyricContainer->setFrameShadow(QFrame::Shadow::Raised);
        lyricLine0 = new QLabel(lyricContainer);
        lyricLine0->setObjectName("lyricLine0");
        lyricLine0->setGeometry(QRect(40, 50, 560, 31));
        lyricLine0->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        lyricLine1 = new QLabel(lyricContainer);
        lyricLine1->setObjectName("lyricLine1");
        lyricLine1->setGeometry(QRect(40, 120, 560, 31));
        lyricLine1->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        lyricLine2 = new QLabel(lyricContainer);
        lyricLine2->setObjectName("lyricLine2");
        lyricLine2->setGeometry(QRect(42, 200, 560, 41));
        lyricLine2->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        lyricLine3 = new QLabel(lyricContainer);
        lyricLine3->setObjectName("lyricLine3");
        lyricLine3->setGeometry(QRect(40, 290, 560, 31));
        lyricLine3->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        lyricLine4 = new QLabel(lyricContainer);
        lyricLine4->setObjectName("lyricLine4");
        lyricLine4->setGeometry(QRect(44, 370, 560, 31));
        lyricLine4->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        MusicWindow->setCentralWidget(centralwidget);

        retranslateUi(MusicWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MusicWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MusicWindow)
    {
        MusicWindow->setWindowTitle(QCoreApplication::translate("MusicWindow", "\350\275\246\350\275\275\345\244\232\345\252\222\344\275\223-\351\237\263\344\271\220", nullptr));
        btn_play->setText(QString());
        btn_pre->setText(QString());
        btn_next->setText(QString());
        btn_volume->setText(QString());
        btn_file->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_local), QCoreApplication::translate("MusicWindow", "\346\234\254\345\234\260\345\210\227\350\241\250", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_online), QCoreApplication::translate("MusicWindow", "\345\234\250\347\272\277\345\210\227\350\241\250", nullptr));
        btn_quit->setText(QString());
        label_currentTime->setText(QCoreApplication::translate("MusicWindow", "00:00", nullptr));
        label_totalTime->setText(QCoreApplication::translate("MusicWindow", "00:00", nullptr));
        lyricLine0->setText(QString());
        lyricLine1->setText(QString());
        lyricLine2->setText(QString());
        lyricLine3->setText(QString());
        lyricLine4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MusicWindow: public Ui_MusicWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICWINDOW_H
