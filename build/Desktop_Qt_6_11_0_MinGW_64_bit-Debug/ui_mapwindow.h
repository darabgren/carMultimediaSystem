/********************************************************************************
** Form generated from reading UI file 'mapwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPWINDOW_H
#define UI_MAPWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_map;
    QFrame *line;
    QLabel *label_src;
    QLabel *label_dst;
    QLineEdit *lineEdit_src;
    QLineEdit *lineEdit_dst;
    QPushButton *btn_getRoute;
    QPushButton *btn_enlarge;
    QPushButton *btn_reduce;
    QPushButton *btn_locate;
    QPushButton *btn_quit;

    void setupUi(QMainWindow *MapWindow)
    {
        if (MapWindow->objectName().isEmpty())
            MapWindow->setObjectName("MapWindow");
        MapWindow->resize(1000, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MapWindow->sizePolicy().hasHeightForWidth());
        MapWindow->setSizePolicy(sizePolicy);
        MapWindow->setMaximumSize(QSize(1000, 600));
        MapWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MapWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("#centralwidget{\n"
"	background-color: qlineargradient(\n"
"    spread:pad, \n"
"    x1:0, y1:0, x2:0, y2:1,  /* \345\236\202\347\233\264\346\270\220\345\217\230\346\226\271\345\220\221 */\n"
"    stop:0 #789ABD,           /* \350\265\267\345\247\213\351\242\234\350\211\262\357\274\210\346\265\205\350\223\235\350\211\262\357\274\211 */\n"
"    stop:1 #E1B698             /* \347\273\223\346\235\237\351\242\234\350\211\262\357\274\210\346\267\261\347\201\260\350\211\262\357\274\211 */\n"
");\n"
"}\n"
"\n"
"#btn_enlarge{\n"
"	border-image: url(:/images/map/btn_enlarge_normal.png);\n"
"}\n"
"#btn_enlarge:hover{\n"
"	border-image: url(:/images/map/btn_enlarge_hover.png);\n"
"}\n"
"\n"
"#btn_reduce{\n"
"	border-image: url(:/images/map/btn_reduce_normal.png);\n"
"}\n"
"#btn_reduce:hover{\n"
"	border-image: url(:/images/map/btn_reduce_hover.png);\n"
"}\n"
"#btn_locate{\n"
"	border-image: url(:/images/map/btn_locate_normal.png);\n"
"}\n"
"#btn_locate:hover{\n"
"	border-image: url(:/images/map/btn_locate_hover.png);\n"
""
                        "}\n"
"\n"
"#btn_quit{\n"
"	border-image: url(:/images/map/btn_quit_normal.png);\n"
"}\n"
"#btn_quit:hover{\n"
"	border-image: url(:/images/map/btn_quit_hover.png);\n"
"}\n"
"\n"
"QLineEdit {\n"
"    background-color: rgba(255, 255, 255, 0.9);\n"
"    border: 1px solid #CED4DA;\n"
"    border-radius: 4px;\n"
"    padding: 6px 8px;\n"
"    color: #333333;\n"
"    font-size: 10.5pt;\n"
"    selection-background-color: #20B2AA;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #20B2AA;\n"
"    box-shadow: 0 0 0 2px rgba(32, 178, 170, 0.2);\n"
"}\n"
"QLabel {\n"
"    color: #495057;\n"
"    font-size: 10.5pt;\n"
"}\n"
"#btn_getRoute{\n"
"	background-color:#FCF7F5;\n"
"	color: #495057;\n"
"    font-size: 10.5pt;\n"
"}\n"
"\n"
""));
        label_map = new QLabel(centralwidget);
        label_map->setObjectName("label_map");
        label_map->setGeometry(QRect(0, 0, 1000, 520));
        label_map->setAlignment(Qt::AlignmentFlag::AlignCenter);
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 511, 1001, 16));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        label_src = new QLabel(centralwidget);
        label_src->setObjectName("label_src");
        label_src->setGeometry(QRect(30, 557, 61, 19));
        label_src->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_dst = new QLabel(centralwidget);
        label_dst->setObjectName("label_dst");
        label_dst->setGeometry(QRect(289, 557, 61, 19));
        label_dst->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_src = new QLineEdit(centralwidget);
        lineEdit_src->setObjectName("lineEdit_src");
        lineEdit_src->setGeometry(QRect(83, 553, 190, 31));
        lineEdit_src->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        lineEdit_dst = new QLineEdit(centralwidget);
        lineEdit_dst->setObjectName("lineEdit_dst");
        lineEdit_dst->setGeometry(QRect(339, 552, 190, 31));
        lineEdit_dst->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        btn_getRoute = new QPushButton(centralwidget);
        btn_getRoute->setObjectName("btn_getRoute");
        btn_getRoute->setGeometry(QRect(559, 553, 111, 31));
        btn_getRoute->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/map/btn_getRoute.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_getRoute->setIcon(icon);
        btn_getRoute->setIconSize(QSize(25, 25));
        btn_enlarge = new QPushButton(centralwidget);
        btn_enlarge->setObjectName("btn_enlarge");
        btn_enlarge->setGeometry(QRect(950, 370, 30, 30));
        btn_reduce = new QPushButton(centralwidget);
        btn_reduce->setObjectName("btn_reduce");
        btn_reduce->setGeometry(QRect(950, 420, 30, 30));
        btn_locate = new QPushButton(centralwidget);
        btn_locate->setObjectName("btn_locate");
        btn_locate->setGeometry(QRect(949, 470, 30, 30));
        btn_quit = new QPushButton(centralwidget);
        btn_quit->setObjectName("btn_quit");
        btn_quit->setGeometry(QRect(950, 551, 30, 30));
        MapWindow->setCentralWidget(centralwidget);

        retranslateUi(MapWindow);

        QMetaObject::connectSlotsByName(MapWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MapWindow)
    {
        MapWindow->setWindowTitle(QCoreApplication::translate("MapWindow", "\350\275\246\350\275\275\345\244\232\345\252\222\344\275\223-\345\234\260\345\233\276", nullptr));
        label_map->setText(QString());
        label_src->setText(QCoreApplication::translate("MapWindow", "\350\265\267\347\202\271\357\274\232", nullptr));
        label_dst->setText(QCoreApplication::translate("MapWindow", "\347\273\210\347\202\271\357\274\232", nullptr));
        btn_getRoute->setText(QCoreApplication::translate("MapWindow", "\350\216\267\345\217\226\350\267\257\347\272\277", nullptr));
        btn_enlarge->setText(QString());
        btn_reduce->setText(QString());
        btn_locate->setText(QString());
        btn_quit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MapWindow: public Ui_MapWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPWINDOW_H
