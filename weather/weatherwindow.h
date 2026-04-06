#ifndef WEATHERWINDOW_H
#define WEATHERWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QVector>
#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace Ui {
class WeatherWindow;
}

class WeatherWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WeatherWindow(QWidget *parent = nullptr);
    ~WeatherWindow();
    void initWeatherWin();

private slots:
    void on_btn_quit_clicked();
    void showDateTime();
    void initVector();
    void initWeather();
    void showWeather(QNetworkReply *reply);

    void on_btn_city_clicked();

private:
    Ui::WeatherWindow *ui;
    QTimer *timer;
    QNetworkAccessManager *manager;
    QVector<QLabel*> *dates;
    QVector<QLabel*> *tems;
    QVector<QLabel*> *icons;
    QVector<QLabel*> *weathers;


};

#endif // WEATHERWINDOW_H
