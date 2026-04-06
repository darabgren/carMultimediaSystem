/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_time;
    QLabel *label_music;
    QLabel *label_video;
    QLabel *label_map;
    QLabel *label_photo;
    QLabel *label_browser;
    QLabel *label_text1;
    QLabel *label_text2;
    QLabel *label_text3;
    QLabel *label_text4;
    QLabel *label_text5;
    QLabel *label_text7;
    QLabel *label_date;
    QLabel *label_weather;
    QLabel *label_gobang;
    QLabel *label_text6;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(1000, 600));
        MainWindow->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/winIcon.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMinimumSize(QSize(800, 500));
        centralwidget->setMaximumSize(QSize(1000, 600));
        centralwidget->setStyleSheet(QString::fromUtf8("#centralwidget{\n"
"	border-image: url(:/images/background.png);\n"
"}\n"
"QLabel{\n"
"	font-family:\345\256\213\344\275\223;\n"
"	font-size:12pt;\n"
"}\n"
"#label_time{\n"
"   color:white;\n"
"   font-size:28pt;\n"
"   font-family:\345\276\256\350\275\257\351\233\205\351\273\221;\n"
"   font-weight:bold;\n"
"}\n"
"\n"
"#label_date{\n"
"   color:white;\n"
"   font-size:18pt;\n"
"   font-family:\345\276\256\350\275\257\351\233\205\351\273\221;\n"
"   font-weight:bold;\n"
"}\n"
"#label_weather{\n"
"	border-image: url(:/images/weather.png);\n"
"}\n"
"#label_music{\n"
"	border-image: url(:/images/music.png);\n"
"}\n"
"#label_video{\n"
"	border-image: url(:/images/video.png);\n"
"}\n"
"#label_map{\n"
"	border-image: url(:/images/map.png);\n"
"}\n"
"#label_photo{\n"
"	border-image: url(:/images/photo.png);\n"
"}\n"
"#label_browser{\n"
"	border-image: url(:/images/browser.png);\n"
"}\n"
"#label_gobang{\n"
"	border-image: url(:/images/gobang.png);\n"
"}\n"
"#label_text1,#label_text2,#label_text3,#label_text4,#label_te"
                        "xt5,#label_text6,#label_text7{\n"
"	color:white;\n"
"}"));
        label_time = new QLabel(centralwidget);
        label_time->setObjectName("label_time");
        label_time->setGeometry(QRect(381, 61, 221, 51));
        label_time->setScaledContents(false);
        label_time->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_time->setWordWrap(false);
        label_music = new QLabel(centralwidget);
        label_music->setObjectName("label_music");
        label_music->setGeometry(QRect(270, 280, 80, 80));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_music->sizePolicy().hasHeightForWidth());
        label_music->setSizePolicy(sizePolicy1);
        label_video = new QLabel(centralwidget);
        label_video->setObjectName("label_video");
        label_video->setEnabled(true);
        label_video->setGeometry(QRect(450, 280, 70, 70));
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_video->sizePolicy().hasHeightForWidth());
        label_video->setSizePolicy(sizePolicy2);
        label_map = new QLabel(centralwidget);
        label_map->setObjectName("label_map");
        label_map->setGeometry(QRect(620, 288, 80, 70));
        label_photo = new QLabel(centralwidget);
        label_photo->setObjectName("label_photo");
        label_photo->setGeometry(QRect(794, 283, 81, 81));
        label_browser = new QLabel(centralwidget);
        label_browser->setObjectName("label_browser");
        label_browser->setGeometry(QRect(268, 404, 81, 81));
        label_text1 = new QLabel(centralwidget);
        label_text1->setObjectName("label_text1");
        label_text1->setGeometry(QRect(100, 360, 69, 19));
        label_text1->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_text2 = new QLabel(centralwidget);
        label_text2->setObjectName("label_text2");
        label_text2->setGeometry(QRect(275, 361, 69, 19));
        label_text2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_text3 = new QLabel(centralwidget);
        label_text3->setObjectName("label_text3");
        label_text3->setGeometry(QRect(450, 363, 69, 19));
        label_text3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_text4 = new QLabel(centralwidget);
        label_text4->setObjectName("label_text4");
        label_text4->setGeometry(QRect(626, 363, 69, 19));
        label_text4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_text5 = new QLabel(centralwidget);
        label_text5->setObjectName("label_text5");
        label_text5->setGeometry(QRect(800, 361, 69, 19));
        label_text5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_text7 = new QLabel(centralwidget);
        label_text7->setObjectName("label_text7");
        label_text7->setGeometry(QRect(274, 483, 69, 19));
        label_text7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_date = new QLabel(centralwidget);
        label_date->setObjectName("label_date");
        label_date->setGeometry(QRect(370, 140, 251, 41));
        label_date->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_weather = new QLabel(centralwidget);
        label_weather->setObjectName("label_weather");
        label_weather->setGeometry(QRect(100, 280, 70, 70));
        sizePolicy2.setHeightForWidth(label_weather->sizePolicy().hasHeightForWidth());
        label_weather->setSizePolicy(sizePolicy2);
        label_weather->setStyleSheet(QString::fromUtf8("border-image: url(:/images/weather.png);"));
        label_gobang = new QLabel(centralwidget);
        label_gobang->setObjectName("label_gobang");
        label_gobang->setGeometry(QRect(101, 416, 71, 61));
        label_text6 = new QLabel(centralwidget);
        label_text6->setObjectName("label_text6");
        label_text6->setGeometry(QRect(100, 486, 69, 19));
        label_text6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\350\275\246\350\275\275\345\244\232\345\252\222\344\275\223-\344\270\273\347\225\214\351\235\242", nullptr));
        label_time->setText(QCoreApplication::translate("MainWindow", "17:09:59", nullptr));
        label_music->setText(QString());
        label_video->setText(QString());
        label_map->setText(QString());
        label_photo->setText(QString());
        label_browser->setText(QString());
        label_text1->setText(QCoreApplication::translate("MainWindow", "\345\244\251\346\260\224", nullptr));
        label_text2->setText(QCoreApplication::translate("MainWindow", "\351\237\263\344\271\220", nullptr));
        label_text3->setText(QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221", nullptr));
        label_text4->setText(QCoreApplication::translate("MainWindow", "\345\234\260\345\233\276", nullptr));
        label_text5->setText(QCoreApplication::translate("MainWindow", "\345\233\276\347\211\207", nullptr));
        label_text7->setText(QCoreApplication::translate("MainWindow", "\346\265\217\350\247\210\345\231\250", nullptr));
        label_date->setText(QCoreApplication::translate("MainWindow", "2025-04-17 \345\221\250\345\233\233", nullptr));
        label_weather->setText(QString());
        label_gobang->setText(QString());
        label_text6->setText(QCoreApplication::translate("MainWindow", "\344\272\224\345\255\220\346\243\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
