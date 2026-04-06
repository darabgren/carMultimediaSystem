/********************************************************************************
** Form generated from reading UI file 'weatherwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHERWINDOW_H
#define UI_WEATHERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeatherWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_date1;
    QLabel *label_tem1;
    QLabel *label_icon1;
    QLabel *label_weather1;
    QLabel *label_date2;
    QLabel *label_weather2;
    QLabel *label_icon2;
    QLabel *label_tem2;
    QLabel *label_date3;
    QLabel *label_weather3;
    QLabel *label_icon3;
    QLabel *label_tem3;
    QLabel *label_date4;
    QLabel *label_weather4;
    QLabel *label_icon4;
    QLabel *label_tem4;
    QLabel *label_date5;
    QLabel *label_weather5;
    QLabel *label_icon5;
    QLabel *label_tem5;
    QLabel *label_date6;
    QLabel *label_weather6;
    QLabel *label_icon6;
    QLabel *label_tem6;
    QLabel *label_date7;
    QLabel *label_weather7;
    QLabel *label_icon7;
    QLabel *label_tem7;
    QLabel *label_icon;
    QLabel *label_weather;
    QLabel *label_tem;
    QLabel *label_datetime;
    QPushButton *btn_city;
    QPushButton *btn_quit;

    void setupUi(QMainWindow *WeatherWindow)
    {
        if (WeatherWindow->objectName().isEmpty())
            WeatherWindow->setObjectName("WeatherWindow");
        WeatherWindow->resize(900, 500);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WeatherWindow->sizePolicy().hasHeightForWidth());
        WeatherWindow->setSizePolicy(sizePolicy);
        WeatherWindow->setMinimumSize(QSize(900, 500));
        WeatherWindow->setMaximumSize(QSize(900, 500));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/winIcon.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        WeatherWindow->setWindowIcon(icon);
        centralwidget = new QWidget(WeatherWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        centralwidget->setStyleSheet(QString::fromUtf8("#centralwidget{\n"
"	background-color: qlineargradient(\n"
"    spread:pad, \n"
"    x1:0, y1:0, x2:0, y2:1,  /* \345\236\202\347\233\264\346\270\220\345\217\230\346\226\271\345\220\221 */\n"
"    stop:0 #789ABD,           /* \350\265\267\345\247\213\351\242\234\350\211\262\357\274\210\346\265\205\350\223\235\350\211\262\357\274\211 */\n"
"    stop:1 #E1B698             /* \347\273\223\346\235\237\351\242\234\350\211\262\357\274\210\346\267\261\347\201\260\350\211\262\357\274\211 */\n"
");\n"
"}\n"
"\n"
"#btn_quit{\n"
"	border-image: url(:/images/quit.png);\n"
"}\n"
"QLabel{\n"
"	color:white;\n"
"	font-family:\345\256\213\344\275\223;\n"
"	font-weight:bold;\n"
"	background:transparent;\n"
"}\n"
"#label_datetime{\n"
"	font-size:20pt;\n"
"	font-weight:bold;\n"
"}\n"
"#label_icon{\n"
"	border-image: url(:/images/weather/yun.png);\n"
"}\n"
"#label_weather{\n"
"	font-size:16pt;\n"
"	font-weight:bold;\n"
"}\n"
"\n"
"#btn_city{\n"
"	color:white;\n"
"	font-family:\345\276\256\350\275\257\351\233\205\351\273\221;\n"
"	"
                        "background:transparent;\n"
"	font-size:20pt;\n"
"	font-weight:bold;\n"
"}\n"
"#label_tem{\n"
"	font-size:28pt;\n"
"	font-weight:bold;\n"
"}\n"
"#label_date1,#label_tem1,#label_weather1{\n"
"	color:yellow;\n"
"}\n"
"#label_date1,#label_date2,#label_date3,#label_date4,#label_date5,#label_date6,#label_date7{\n"
"	font-weight:bold;\n"
"}\n"
"#label_tem1,#label_tem2,#label_tem3,#label_tem4,#label_tem5,#label_tem6,#label_tem7{\n"
"	font-weight:bold;\n"
"}\n"
"\n"
"#label_icon1,#label_icon2,#label_icon3,#label_icon4,#label_icon5,#label_icon6,#label_icon7{\n"
"	border-image: url(:/images/weather/xue.png);\n"
"}"));
        label_date1 = new QLabel(centralwidget);
        label_date1->setObjectName("label_date1");
        label_date1->setGeometry(QRect(38, 260, 70, 40));
        label_date1->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_tem1 = new QLabel(centralwidget);
        label_tem1->setObjectName("label_tem1");
        label_tem1->setGeometry(QRect(31, 310, 80, 20));
        label_tem1->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_icon1 = new QLabel(centralwidget);
        label_icon1->setObjectName("label_icon1");
        label_icon1->setGeometry(QRect(42, 350, 60, 50));
        label_icon1->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_weather1 = new QLabel(centralwidget);
        label_weather1->setObjectName("label_weather1");
        label_weather1->setGeometry(QRect(14, 410, 110, 20));
        label_weather1->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_date2 = new QLabel(centralwidget);
        label_date2->setObjectName("label_date2");
        label_date2->setGeometry(QRect(162, 260, 70, 40));
        label_date2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_weather2 = new QLabel(centralwidget);
        label_weather2->setObjectName("label_weather2");
        label_weather2->setGeometry(QRect(139, 410, 110, 20));
        label_weather2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_icon2 = new QLabel(centralwidget);
        label_icon2->setObjectName("label_icon2");
        label_icon2->setGeometry(QRect(164, 350, 60, 50));
        label_icon2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_tem2 = new QLabel(centralwidget);
        label_tem2->setObjectName("label_tem2");
        label_tem2->setGeometry(QRect(155, 310, 80, 20));
        label_tem2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_date3 = new QLabel(centralwidget);
        label_date3->setObjectName("label_date3");
        label_date3->setGeometry(QRect(280, 260, 70, 40));
        label_date3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_weather3 = new QLabel(centralwidget);
        label_weather3->setObjectName("label_weather3");
        label_weather3->setGeometry(QRect(258, 410, 110, 20));
        label_weather3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_icon3 = new QLabel(centralwidget);
        label_icon3->setObjectName("label_icon3");
        label_icon3->setGeometry(QRect(284, 350, 60, 50));
        label_icon3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_tem3 = new QLabel(centralwidget);
        label_tem3->setObjectName("label_tem3");
        label_tem3->setGeometry(QRect(276, 310, 80, 20));
        label_tem3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_date4 = new QLabel(centralwidget);
        label_date4->setObjectName("label_date4");
        label_date4->setGeometry(QRect(413, 260, 70, 40));
        label_date4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_weather4 = new QLabel(centralwidget);
        label_weather4->setObjectName("label_weather4");
        label_weather4->setGeometry(QRect(390, 410, 110, 20));
        label_weather4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_icon4 = new QLabel(centralwidget);
        label_icon4->setObjectName("label_icon4");
        label_icon4->setGeometry(QRect(418, 350, 60, 50));
        label_icon4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_tem4 = new QLabel(centralwidget);
        label_tem4->setObjectName("label_tem4");
        label_tem4->setGeometry(QRect(408, 310, 80, 20));
        label_tem4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_date5 = new QLabel(centralwidget);
        label_date5->setObjectName("label_date5");
        label_date5->setGeometry(QRect(534, 260, 70, 40));
        label_date5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_weather5 = new QLabel(centralwidget);
        label_weather5->setObjectName("label_weather5");
        label_weather5->setGeometry(QRect(512, 410, 110, 20));
        label_weather5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_icon5 = new QLabel(centralwidget);
        label_icon5->setObjectName("label_icon5");
        label_icon5->setGeometry(QRect(538, 350, 60, 50));
        label_icon5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_tem5 = new QLabel(centralwidget);
        label_tem5->setObjectName("label_tem5");
        label_tem5->setGeometry(QRect(531, 310, 80, 20));
        label_tem5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_date6 = new QLabel(centralwidget);
        label_date6->setObjectName("label_date6");
        label_date6->setGeometry(QRect(657, 260, 70, 40));
        label_date6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_weather6 = new QLabel(centralwidget);
        label_weather6->setObjectName("label_weather6");
        label_weather6->setGeometry(QRect(636, 410, 110, 20));
        label_weather6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_icon6 = new QLabel(centralwidget);
        label_icon6->setObjectName("label_icon6");
        label_icon6->setGeometry(QRect(662, 350, 60, 50));
        label_icon6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_tem6 = new QLabel(centralwidget);
        label_tem6->setObjectName("label_tem6");
        label_tem6->setGeometry(QRect(652, 310, 80, 20));
        label_tem6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_date7 = new QLabel(centralwidget);
        label_date7->setObjectName("label_date7");
        label_date7->setGeometry(QRect(792, 260, 70, 40));
        label_date7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_weather7 = new QLabel(centralwidget);
        label_weather7->setObjectName("label_weather7");
        label_weather7->setGeometry(QRect(773, 410, 110, 20));
        label_weather7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_icon7 = new QLabel(centralwidget);
        label_icon7->setObjectName("label_icon7");
        label_icon7->setGeometry(QRect(796, 350, 60, 50));
        label_icon7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_tem7 = new QLabel(centralwidget);
        label_tem7->setObjectName("label_tem7");
        label_tem7->setGeometry(QRect(787, 310, 80, 20));
        label_tem7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_icon = new QLabel(centralwidget);
        label_icon->setObjectName("label_icon");
        label_icon->setGeometry(QRect(90, 49, 101, 71));
        sizePolicy.setHeightForWidth(label_icon->sizePolicy().hasHeightForWidth());
        label_icon->setSizePolicy(sizePolicy);
        label_weather = new QLabel(centralwidget);
        label_weather->setObjectName("label_weather");
        label_weather->setGeometry(QRect(33, 120, 211, 31));
        label_weather->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_tem = new QLabel(centralwidget);
        label_tem->setObjectName("label_tem");
        label_tem->setGeometry(QRect(254, 113, 201, 41));
        label_tem->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_datetime = new QLabel(centralwidget);
        label_datetime->setObjectName("label_datetime");
        label_datetime->setGeometry(QRect(527, 56, 231, 91));
        label_datetime->setAlignment(Qt::AlignmentFlag::AlignCenter);
        btn_city = new QPushButton(centralwidget);
        btn_city->setObjectName("btn_city");
        btn_city->setGeometry(QRect(273, 40, 151, 51));
        btn_city->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        btn_city->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/refresh.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_city->setIcon(icon1);
        btn_quit = new QPushButton(centralwidget);
        btn_quit->setObjectName("btn_quit");
        btn_quit->setGeometry(QRect(810, 20, 51, 41));
        WeatherWindow->setCentralWidget(centralwidget);

        retranslateUi(WeatherWindow);

        QMetaObject::connectSlotsByName(WeatherWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WeatherWindow)
    {
        WeatherWindow->setWindowTitle(QCoreApplication::translate("WeatherWindow", "\350\275\246\350\275\275\345\244\232\345\252\222\344\275\223-\345\244\251\346\260\224", nullptr));
        label_date1->setText(QCoreApplication::translate("WeatherWindow", "17\346\227\245\n"
"\346\230\237\346\234\237\345\233\233", nullptr));
        label_tem1->setText(QCoreApplication::translate("WeatherWindow", "17\342\204\203~30\342\204\203", nullptr));
        label_icon1->setText(QString());
        label_weather1->setText(QCoreApplication::translate("WeatherWindow", "\345\244\247\346\232\264\351\233\250\350\275\254\351\233\267\351\230\265\351\233\250", nullptr));
        label_date2->setText(QCoreApplication::translate("WeatherWindow", "17\346\227\245\n"
"\346\230\237\346\234\237\345\233\233", nullptr));
        label_weather2->setText(QCoreApplication::translate("WeatherWindow", "\345\244\247\346\232\264\351\233\250\350\275\254\351\233\267\351\230\265\351\233\250", nullptr));
        label_icon2->setText(QString());
        label_tem2->setText(QCoreApplication::translate("WeatherWindow", "17\342\204\203~30\342\204\203", nullptr));
        label_date3->setText(QCoreApplication::translate("WeatherWindow", "17\346\227\245\n"
"\346\230\237\346\234\237\345\233\233", nullptr));
        label_weather3->setText(QCoreApplication::translate("WeatherWindow", "\345\244\247\346\232\264\351\233\250\350\275\254\351\233\267\351\230\265\351\233\250", nullptr));
        label_icon3->setText(QString());
        label_tem3->setText(QCoreApplication::translate("WeatherWindow", "17\342\204\203~30\342\204\203", nullptr));
        label_date4->setText(QCoreApplication::translate("WeatherWindow", "17\346\227\245\n"
"\346\230\237\346\234\237\345\233\233", nullptr));
        label_weather4->setText(QCoreApplication::translate("WeatherWindow", "\345\244\247\346\232\264\351\233\250\350\275\254\351\233\267\351\230\265\351\233\250", nullptr));
        label_icon4->setText(QString());
        label_tem4->setText(QCoreApplication::translate("WeatherWindow", "17\342\204\203~30\342\204\203", nullptr));
        label_date5->setText(QCoreApplication::translate("WeatherWindow", "17\346\227\245\n"
"\346\230\237\346\234\237\345\233\233", nullptr));
        label_weather5->setText(QCoreApplication::translate("WeatherWindow", "\345\244\247\346\232\264\351\233\250\350\275\254\351\233\267\351\230\265\351\233\250", nullptr));
        label_icon5->setText(QString());
        label_tem5->setText(QCoreApplication::translate("WeatherWindow", "17\342\204\203~30\342\204\203", nullptr));
        label_date6->setText(QCoreApplication::translate("WeatherWindow", "17\346\227\245\n"
"\346\230\237\346\234\237\345\233\233", nullptr));
        label_weather6->setText(QCoreApplication::translate("WeatherWindow", "\345\244\247\346\232\264\351\233\250\350\275\254\351\233\267\351\230\265\351\233\250", nullptr));
        label_icon6->setText(QString());
        label_tem6->setText(QCoreApplication::translate("WeatherWindow", "17\342\204\203~30\342\204\203", nullptr));
        label_date7->setText(QCoreApplication::translate("WeatherWindow", "17\346\227\245\n"
"\346\230\237\346\234\237\345\233\233", nullptr));
        label_weather7->setText(QCoreApplication::translate("WeatherWindow", "\345\244\247\346\232\264\351\233\250\350\275\254\351\233\267\351\230\265\351\233\250", nullptr));
        label_icon7->setText(QString());
        label_tem7->setText(QCoreApplication::translate("WeatherWindow", "17\342\204\203~30\342\204\203", nullptr));
        label_icon->setText(QString());
        label_weather->setText(QCoreApplication::translate("WeatherWindow", "\345\244\247\346\232\264\351\233\250\350\275\254\351\233\267\351\230\265\351\233\250", nullptr));
        label_tem->setText(QCoreApplication::translate("WeatherWindow", "30.2\342\204\203", nullptr));
        label_datetime->setText(QCoreApplication::translate("WeatherWindow", "2025-04-17\n"
"14:36:05 \345\221\250\345\233\233", nullptr));
        btn_city->setText(QCoreApplication::translate("WeatherWindow", "\346\210\220\351\203\275", nullptr));
        btn_quit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WeatherWindow: public Ui_WeatherWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHERWINDOW_H
