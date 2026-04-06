/********************************************************************************
** Form generated from reading UI file 'photowindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHOTOWINDOW_H
#define UI_PHOTOWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PhotoWindow
{
public:
    QWidget *centralwidget;
    QToolButton *btn_files;
    QListWidget *list_files;
    QPushButton *btn_shrink;
    QPushButton *btn_left;
    QPushButton *btn_enlarge;
    QPushButton *btn_pre;
    QPushButton *btn_next;
    QPushButton *btn_right;
    QLabel *label_img;
    QPushButton *btn_quit;
    QPushButton *btn_del;

    void setupUi(QMainWindow *PhotoWindow)
    {
        if (PhotoWindow->objectName().isEmpty())
            PhotoWindow->setObjectName("PhotoWindow");
        PhotoWindow->resize(1000, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PhotoWindow->sizePolicy().hasHeightForWidth());
        PhotoWindow->setSizePolicy(sizePolicy);
        PhotoWindow->setMaximumSize(QSize(1000, 600));
        centralwidget = new QWidget(PhotoWindow);
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
"QListWidget{\n"
"	background-color: transparent; /* \350\203\214\346\231\257\351\200\217\346\230\216 */\n"
"    border: none; /* \347\247\273\351\231\244\350\276\271\346\241\206 */\n"
"	font-size: 16px;\n"
"	border: 1px solid #555; /* \344\273\205\344\277\235\347\225\231\345\272\225\351\203\250\350\276\271\346\241\206 */\n"
"}\n"
"QToolButton {\n"
"    background-color: transparent; /* \350\203\214\346\231\257\351\200\217\346\230\216 */\n"
"    border: none; /* \347\247\273\351\231\244\350\276\271\346\241\206 "
                        "*/\n"
"	font-size: 16px;\n"
"}\n"
"QPushButton {\n"
"    background-color: transparent; /* \350\203\214\346\231\257\351\200\217\346\230\216 */\n"
"    border: none; /* \347\247\273\351\231\244\350\276\271\346\241\206 */\n"
"	font-size: 16px;\n"
"}\n"
"#btn_pre{\n"
"	qproperty-icon: url(:/images/photo/btn_pre.png);\n"
"}\n"
"#btn_next{\n"
"	qproperty-icon: url(:/images/photo/btn_next.png);\n"
"}\n"
"#btn_enlarge{\n"
"	qproperty-icon: url(:/images/photo/btn_enlarge.png);\n"
"}\n"
"#btn_shrink{\n"
"	qproperty-icon: url(:/images/photo/btn_shrink.png);\n"
"}\n"
"#btn_left{\n"
"	qproperty-icon: url(:/images/photo/rotate_left.png);\n"
"}\n"
"#btn_right{\n"
"	qproperty-icon: url(:/images/photo/rotate_right.png);\n"
"}\n"
"#btn_del{\n"
"	qproperty-icon: url(:/images/photo/del.png);\n"
"}\n"
"/*\351\200\200\345\207\272\346\240\267\345\274\217*/\n"
"#btn_quit{\n"
"	border-image: url(:/images/photo/btn_quit_normal.png);\n"
"}\n"
"#btn_quit:hover{\n"
"	border-image: url(:/images/photo/btn_quit_hover.png);\n"
"}\n"
""));
        btn_files = new QToolButton(centralwidget);
        btn_files->setObjectName("btn_files");
        btn_files->setGeometry(QRect(12, 37, 51, 31));
        list_files = new QListWidget(centralwidget);
        list_files->setObjectName("list_files");
        list_files->setGeometry(QRect(10, 70, 251, 421));
        btn_shrink = new QPushButton(centralwidget);
        btn_shrink->setObjectName("btn_shrink");
        btn_shrink->setGeometry(QRect(492, 540, 93, 53));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_shrink->sizePolicy().hasHeightForWidth());
        btn_shrink->setSizePolicy(sizePolicy1);
        btn_shrink->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        btn_shrink->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/shrink.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_shrink->setIcon(icon);
        btn_shrink->setIconSize(QSize(25, 25));
        btn_left = new QPushButton(centralwidget);
        btn_left->setObjectName("btn_left");
        btn_left->setGeometry(QRect(621, 540, 93, 53));
        sizePolicy1.setHeightForWidth(btn_left->sizePolicy().hasHeightForWidth());
        btn_left->setSizePolicy(sizePolicy1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/rotate_left.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_left->setIcon(icon1);
        btn_left->setIconSize(QSize(25, 25));
        btn_enlarge = new QPushButton(centralwidget);
        btn_enlarge->setObjectName("btn_enlarge");
        btn_enlarge->setGeometry(QRect(363, 540, 93, 53));
        sizePolicy1.setHeightForWidth(btn_enlarge->sizePolicy().hasHeightForWidth());
        btn_enlarge->setSizePolicy(sizePolicy1);
        btn_enlarge->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/enlarge.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_enlarge->setIcon(icon2);
        btn_enlarge->setIconSize(QSize(25, 25));
        btn_pre = new QPushButton(centralwidget);
        btn_pre->setObjectName("btn_pre");
        btn_pre->setGeometry(QRect(107, 540, 93, 53));
        sizePolicy1.setHeightForWidth(btn_pre->sizePolicy().hasHeightForWidth());
        btn_pre->setSizePolicy(sizePolicy1);
        btn_pre->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/pre.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_pre->setIcon(icon3);
        btn_pre->setIconSize(QSize(35, 35));
        btn_next = new QPushButton(centralwidget);
        btn_next->setObjectName("btn_next");
        btn_next->setEnabled(true);
        btn_next->setGeometry(QRect(234, 540, 93, 53));
        sizePolicy1.setHeightForWidth(btn_next->sizePolicy().hasHeightForWidth());
        btn_next->setSizePolicy(sizePolicy1);
        btn_next->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        btn_next->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/next.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_next->setIcon(icon4);
        btn_next->setIconSize(QSize(35, 35));
        btn_right = new QPushButton(centralwidget);
        btn_right->setObjectName("btn_right");
        btn_right->setGeometry(QRect(750, 540, 93, 53));
        sizePolicy1.setHeightForWidth(btn_right->sizePolicy().hasHeightForWidth());
        btn_right->setSizePolicy(sizePolicy1);
        btn_right->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/rotate_right.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_right->setIcon(icon5);
        btn_right->setIconSize(QSize(25, 25));
        label_img = new QLabel(centralwidget);
        label_img->setObjectName("label_img");
        label_img->setGeometry(QRect(280, 70, 641, 421));
        label_img->setAlignment(Qt::AlignmentFlag::AlignCenter);
        btn_quit = new QPushButton(centralwidget);
        btn_quit->setObjectName("btn_quit");
        btn_quit->setGeometry(QRect(940, 30, 35, 35));
        btn_del = new QPushButton(centralwidget);
        btn_del->setObjectName("btn_del");
        btn_del->setGeometry(QRect(865, 540, 93, 53));
        btn_del->setIconSize(QSize(25, 25));
        PhotoWindow->setCentralWidget(centralwidget);

        retranslateUi(PhotoWindow);

        QMetaObject::connectSlotsByName(PhotoWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PhotoWindow)
    {
        PhotoWindow->setWindowTitle(QCoreApplication::translate("PhotoWindow", "\350\275\246\350\275\275\345\244\232\345\252\222\344\275\223-\345\233\276\347\211\207", nullptr));
        btn_files->setText(QCoreApplication::translate("PhotoWindow", "\346\226\207\344\273\266", nullptr));
        btn_shrink->setText(QCoreApplication::translate("PhotoWindow", "\347\274\251\345\260\217", nullptr));
        btn_left->setText(QCoreApplication::translate("PhotoWindow", "\345\267\246\346\227\213", nullptr));
        btn_enlarge->setText(QCoreApplication::translate("PhotoWindow", "\346\224\276\345\244\247", nullptr));
        btn_pre->setText(QCoreApplication::translate("PhotoWindow", "\344\270\212\344\270\200\345\274\240", nullptr));
        btn_next->setText(QCoreApplication::translate("PhotoWindow", "\344\270\213\344\270\200\345\274\240", nullptr));
        btn_right->setText(QCoreApplication::translate("PhotoWindow", "\345\217\263\346\227\213", nullptr));
        label_img->setText(QString());
        btn_quit->setText(QString());
        btn_del->setText(QCoreApplication::translate("PhotoWindow", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PhotoWindow: public Ui_PhotoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHOTOWINDOW_H
