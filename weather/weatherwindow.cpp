#include "weather/weatherwindow.h"
#include "ui_weatherwindow.h"
#include <QDateTime>
#include <QDebug>
#include <QLocale>
#include "common/common.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

WeatherWindow::WeatherWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WeatherWindow)
{
    ui->setupUi(this);
    this->initWeatherWin();
}

WeatherWindow::~WeatherWindow()
{
    delete ui;
}

void WeatherWindow::initWeatherWin()
{
    //定时器每秒执行
    this->timer=new QTimer();
    connect(this->timer,&QTimer::timeout,this,&WeatherWindow::showDateTime);
    //实时获取时间
    this->showDateTime();

    //初始化容器
    this->initVector();
    //初始化天气
    this->manager=new QNetworkAccessManager();
    this->initWeather();
    connect(this->manager,&QNetworkAccessManager::finished,this,&WeatherWindow::showWeather);

}
/**
 * @brief WeatherWindow::on_btn_quit_clicked
 */
void WeatherWindow::on_btn_quit_clicked()
{
    this->parentWidget()->show();
    this->hide();
}

/**
 * @brief WeatherWindow::showDateTime
 */
void WeatherWindow::showDateTime()
{
    QDateTime currenttime=QDateTime::currentDateTime();
    QString datetime=QLocale(QLocale::Chinese).toString(currenttime,"hh:mm:ss\nyyyy-MM-dd ddd");
    ui->label_datetime->setText(datetime);
    this->timer->start(1000);
}

void WeatherWindow::initVector()
{
    this->dates=new QVector<QLabel*>();
    this->tems=new QVector<QLabel*>();
    this->icons=new QVector<QLabel*>();
    this->weathers=new QVector<QLabel*>();

    for(int i=1;i<=7;++i){
        //动态查找日期标签
        QLabel* dateLabel=findChild<QLabel*>(QString("label_date%1").arg(i));
        if(dateLabel) dates->push_back(dateLabel);
        qDebug()<<dates->at(i-1)->objectName();

        QLabel* temLabel=findChild<QLabel*>(QString("label_tem%1").arg(i));
        if(temLabel) tems->push_back(temLabel);


        QLabel* iconLabel=findChild<QLabel*>(QString("label_icon%1").arg(i));
        if(iconLabel) icons->push_back(iconLabel);

        QLabel* weatherLabel=findChild<QLabel*>(QString("label_weather%1").arg(i));
        if(weatherLabel) weathers->push_back(weatherLabel);
        }
}

void WeatherWindow::initWeather()
{
    //调用get()发起Get请求
    QString url=QString(WEATHER_URL)
                      .arg(WEATHER_VERSION).arg(WEATHER_APPID).arg(WEATHER_APPSECRET);
    manager->get(QNetworkRequest(QUrl(url)));
}

void WeatherWindow::showWeather(QNetworkReply *reply)
{
    qDebug()<<"实时天气展示";
    QByteArray data=reply->readAll();
    //解析Json格式的字符串,动态展示数据
    QJsonDocument doc=QJsonDocument::fromJson(data);
    if(doc.isObject()){
        QJsonObject obj=doc.object();
        QString city=obj.value("city").toString();
        ui->btn_city->setText(city);

        QJsonArray arr=obj.value("data").toArray();
        for(int i=0;i<arr.size();++i){
            QJsonObject arrObj=arr.at(i).toObject();

            //日期
            QString date=arrObj.value("date").toString().split("-")[2]+"日";
            QString week=arrObj.value("week").toString();
            QString dateRes=date+"\n"+week;
            dates->at(i)->setText(dateRes);
            //温度
            QString minTem=arrObj.value("tem2").toString()+"℃";
            QString maxTem=arrObj.value("tem1").toString()+"℃";
            QString temRes=minTem+"~"+maxTem;
            tems->at(i)->setText(temRes);
            //图标
            QString weatherImg=arrObj.value("wea_img").toString();
            QString css="border-image:url(:/images/weather/%1.png)";
            css=css.arg(weatherImg);
            icons->at(i)->setStyleSheet(css);
            //天气
            QString weather=arrObj.value("wea").toString();
            weathers->at(i)->setText(weather);

            //当前实时天气第一天实时的天气
            if(i==0){
                ui->label_icon->setStyleSheet(css);
                ui->label_weather->setText(weather);
                QString tem=arrObj.value("tem").toString()+"℃";
                ui->label_tem->setText(tem);
            }
        }
    }
}

/**
 * @brief WeatherWindow::on_btn_city_clicked
 * 点击城市按钮刷新天气,即初始化天气
 */
void WeatherWindow::on_btn_city_clicked()
{
    this->initWeather();
    qDebug()<<"刷新天气";
}

