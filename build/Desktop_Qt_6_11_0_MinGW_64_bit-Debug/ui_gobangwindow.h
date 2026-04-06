/********************************************************************************
** Form generated from reading UI file 'gobangwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOBANGWINDOW_H
#define UI_GOBANGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GobangWindow
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QPushButton *btn_quit;
    QPushButton *btn_take_back;
    QPushButton *btn_request_draw;
    QPushButton *btn_give_up;
    QPushButton *btn_restart;
    QLabel *label_currentTurn;
    QLabel *label_player;

    void setupUi(QMainWindow *GobangWindow)
    {
        if (GobangWindow->objectName().isEmpty())
            GobangWindow->setObjectName("GobangWindow");
        GobangWindow->resize(820, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GobangWindow->sizePolicy().hasHeightForWidth());
        GobangWindow->setSizePolicy(sizePolicy);
        GobangWindow->setMaximumSize(QSize(820, 600));
        centralwidget = new QWidget(GobangWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("#label_currentTurn{\n"
"	font-size: 25px;                /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    font-weight: bold;              /* \345\255\227\344\275\223\345\212\240\347\262\227 */\n"
"}\n"
"#label_player{\n"
"	font-size:45px;\n"
"	font-weight:bold;\n"
"}\n"
"QPushButton {\n"
"    border: 2px solid #333;          /* \347\273\237\344\270\200\350\276\271\346\241\206 */\n"
"    border-radius: 10px;            /* \345\234\206\350\247\222 */\n"
"    font-size: 16px;                /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    font-weight: bold;              /* \345\255\227\344\275\223\345\212\240\347\262\227 */\n"
"    margin: 8px;                    /* \346\214\211\351\222\256\351\227\264\350\267\235 */\n"
"}\n"
"\n"
"#btn_take_back {\n"
"    background-color: #ffcccc;      /* \346\202\224\346\243\213 - \346\265\205\347\272\242 */\n"
"    qproperty-icon: url(:/images/gobang/btn_take_back.png);\n"
"    icon-size: 24px;                /* \345\233\276\346\240\207\345\244\247"
                        "\345\260\217 */\n"
"}\n"
"\n"
"#btn_request_draw {\n"
"    background-color: #ffffcc;      /* \346\261\202\345\222\214 - \346\265\205\351\273\204 */\n"
"    qproperty-icon: url(:/images/gobang/btn_request_draw.png);\n"
"    icon-size: 24px;\n"
"}\n"
"\n"
"#btn_give_up {\n"
"    background-color: #ffcc99;      /* \350\256\244\350\276\223 - \346\265\205\346\251\231 */\n"
"    qproperty-icon: url(:/images/gobang/btn_give_up.png);\n"
"    icon-size: 24px;\n"
"}\n"
"\n"
"#btn_restart {\n"
"    background-color: #ccff99;      /* \351\207\215\346\226\260\345\274\200\345\247\213 - \346\265\205\347\273\277 */\n"
"    qproperty-icon: url(:/images/gobang/btn_restart.png);\n"
"    icon-size: 24px;\n"
"}\n"
"\n"
"#btn_quit {\n"
"	background-color: rgba(255, 111, 97, 0.7);\n"
"    \n"
"    qproperty-icon: url(:/images/gobang/btn_quit.png);\n"
"    icon-size: 24px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border-color: #666;            /* \346\202\254\345\201\234\346\227\266\350\276\271\346\241\206\345\217\230\346\267\261 "
                        "*/\n"
"    background-color: #eeeeee;     /* \346\202\254\345\201\234\346\227\266\350\203\214\346\231\257\345\217\230\346\265\205 */\n"
"}"));
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(600, 0, 20, 601));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        btn_quit = new QPushButton(centralwidget);
        btn_quit->setObjectName("btn_quit");
        btn_quit->setGeometry(QRect(654, 522, 120, 60));
        btn_quit->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        btn_quit->setIconSize(QSize(25, 25));
        btn_take_back = new QPushButton(centralwidget);
        btn_take_back->setObjectName("btn_take_back");
        btn_take_back->setGeometry(QRect(653, 214, 120, 60));
        btn_take_back->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        btn_take_back->setIconSize(QSize(25, 25));
        btn_request_draw = new QPushButton(centralwidget);
        btn_request_draw->setObjectName("btn_request_draw");
        btn_request_draw->setGeometry(QRect(653, 295, 120, 60));
        btn_request_draw->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        btn_request_draw->setIconSize(QSize(25, 25));
        btn_give_up = new QPushButton(centralwidget);
        btn_give_up->setObjectName("btn_give_up");
        btn_give_up->setGeometry(QRect(653, 372, 120, 60));
        btn_give_up->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        btn_give_up->setIconSize(QSize(25, 25));
        btn_restart = new QPushButton(centralwidget);
        btn_restart->setObjectName("btn_restart");
        btn_restart->setGeometry(QRect(653, 450, 120, 60));
        btn_restart->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        btn_restart->setIconSize(QSize(25, 25));
        label_currentTurn = new QLabel(centralwidget);
        label_currentTurn->setObjectName("label_currentTurn");
        label_currentTurn->setGeometry(QRect(661, 20, 111, 41));
        label_currentTurn->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_player = new QLabel(centralwidget);
        label_player->setObjectName("label_player");
        label_player->setGeometry(QRect(646, 96, 141, 51));
        label_player->setAlignment(Qt::AlignmentFlag::AlignCenter);
        GobangWindow->setCentralWidget(centralwidget);

        retranslateUi(GobangWindow);

        QMetaObject::connectSlotsByName(GobangWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GobangWindow)
    {
        GobangWindow->setWindowTitle(QCoreApplication::translate("GobangWindow", "\350\275\246\350\275\275\345\244\232\345\252\222\344\275\223-\344\272\224\345\255\220\346\243\213", nullptr));
        btn_quit->setText(QCoreApplication::translate("GobangWindow", "\351\200\200\345\207\272", nullptr));
        btn_take_back->setText(QCoreApplication::translate("GobangWindow", "\346\202\224\346\243\213", nullptr));
        btn_request_draw->setText(QCoreApplication::translate("GobangWindow", "\346\261\202\345\222\214", nullptr));
        btn_give_up->setText(QCoreApplication::translate("GobangWindow", "\350\256\244\350\276\223", nullptr));
        btn_restart->setText(QCoreApplication::translate("GobangWindow", "\351\207\215\346\226\260\345\274\200\345\247\213", nullptr));
        label_currentTurn->setText(QCoreApplication::translate("GobangWindow", "\345\275\223\345\211\215\345\233\236\345\220\210", nullptr));
        label_player->setText(QCoreApplication::translate("GobangWindow", "Black", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GobangWindow: public Ui_GobangWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOBANGWINDOW_H
