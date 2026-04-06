#ifndef COMMON_H
#define COMMON_H

//定义天气api相关数据
#define WEATHER_URL "http://gfeljm.tianqiapi.com/api?unescape=1&version=%1&appid=%2&appsecret=%3"
#define WEATHER_VERSION "v91"
#define WEATHER_APPID "31722225"
#define WEATHER_APPSECRET "U9M0Cs6S"

#include <QString>
#include <QDir>
#include <QCoreApplication>

inline QString getProjectMusicPath() {
    // 获取项目源码根目录（非构建目录）
    //QString projectRoot = QString(PROJECT_SOURCE_DIR);
    //QDir musicDir(projectRoot + "/music");

    QString execDir = QCoreApplication::applicationDirPath();
    QDir musicDir(execDir + "/music");
    // 如果目录不存在则创建（可选）
    if(!musicDir.exists()) {
        musicDir.mkpath(".");
        qDebug() << "Created music directory:" << musicDir.absolutePath();
    }
    return musicDir.absolutePath();
}

inline QString getProjectVideoPath() {
    // 获取项目源码根目录（非构建目录）
    //QString projectRoot = QString(PROJECT_SOURCE_DIR);
    //QDir videoDir(projectRoot + "/video");

    QString execDir = QCoreApplication::applicationDirPath();
    QDir videoDir(execDir + "/video");
    // 如果目录不存在则创建（可选）
    if(!videoDir.exists()) {
        videoDir.mkpath(".");
        qDebug() << "Created music directory:" << videoDir.absolutePath();
    }
    return videoDir.absolutePath();
}


// 定义百度地图API
#define BAIDU_MAP_URL "https://api.map.baidu.com/staticimage/v2?ak=%1&width=1000&height=520&scaler=2&center=%2,%3&zoom=%4"
#define BAIDU_MAP_AK "v9FbiWTpT09CpYwo92JZLqAszBWzZDRk"
#define BAIDU_MAP_IP_URL "https://api.map.baidu.com/location/ip?ip=%1&coor=bd09ll&ak=%2"


//定义photo打开图片路径(用\\或者/)
#define FILES_OPEN_PATH "C:\\Users\\31657\\Pictures"


//定义五子棋相关
#define CHESSBOARD_ROWS 15  //棋盘行数
#define CHESSBOARD_COLS 15  //棋盘列数
#define GRID_WIDTH 40   //每个格子的宽度(像素)
#define GRID_HEIGHT 40  //每个格子的高度(像素)


#endif // COMMON_H
