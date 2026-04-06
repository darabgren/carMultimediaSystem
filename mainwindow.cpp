#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QLocale>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //定时器每秒执行
    this->timer=new QTimer();
    connect(this->timer,&QTimer::timeout,this,&MainWindow::showDateTime);
    //实时获取时间
    this->showDateTime();

    //安装事件过滤器
    this->eventFilter=new LabelClickEventFilter();
    ui->label_weather->installEventFilter(this->eventFilter);
    ui->label_music->installEventFilter(this->eventFilter);
    ui->label_video->installEventFilter(this->eventFilter);
    ui->label_map->installEventFilter(this->eventFilter);
    ui->label_photo->installEventFilter(this->eventFilter);
    ui->label_gobang->installEventFilter(this->eventFilter);

    //绑定事件过滤器的信号和当前类的槽函数
    connect(this->eventFilter,&LabelClickEventFilter::goOtherWindow,this,&MainWindow::goPage);

    //实例化各个窗口对象
    this->weatherWin=new WeatherWindow(this);
    this->musicWin=new MusicWindow(this);
    this->videoWin=new VideoWindow(this);
    this->mapWin=new MapWindow(this);
    this->photoWin=new PhotoWindow(this);
    this->gobangWin=new GobangWindow(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showDateTime()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    QString date=QLocale(QLocale::Chinese).toString(currentTime, "yyyy-MM-dd ddd");
    QString time=QLocale(QLocale::Chinese).toString(currentTime,"hh:mm:ss");
    ui->label_date->setText(date);
    ui->label_time->setText(time);
    this->timer->start(1000);
}


void MainWindow::goPage(QObject *watched)
{
    QString objName=watched->objectName();
    //跳转到相应页面
    if(objName=="label_weather"){
        this->weatherWin->show();
                                    //可以点击之后在进行初始化,注意有些只初始化一次
    }else if(objName=="label_music"){
        this->musicWin->show();

    }else if(objName=="label_video"){
        this->videoWin->show();

    }else if(objName=="label_map"){
        this->mapWin->show();

    }else if(objName=="label_photo"){
        this->photoWin->show();

    }else if(objName=="label_gobang"){
        this->gobangWin->show();

    }
    this->hide();
}

