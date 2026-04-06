#include "video/videodao.h"
#include <QStandardPaths>
#include <QDir>
#include <QDebug>
#include <QtSql/QSqlError>
#include "common/common.h"

VideoDao::VideoDao() {
    QString videoDir = getProjectVideoPath(); // 假设返回 "项目根/video"（无斜杠）
    QDir dir(videoDir);
    QString databasePath = dir.filePath("video.db"); // 自动添加斜杠
    // 等效于：videoDir + "/" + "video.db"
    initDatabase(databasePath); //初始化数据库
}

bool VideoDao::initDatabase(const QString &databasePath){
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(databasePath);
    if (!m_db.open()) {
        qCritical() << "数据库打开失败:" << m_db.lastError().text();
        return false;
    }
    // 创建表t_video（如果不存在）
    QString createTableSql = "CREATE TABLE IF NOT EXISTS t_video ("
                             "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                             "name TEXT NOT NULL,"
                             "path TEXT UNIQUE NOT NULL" // path设为唯一索引，避免重复
                             ");";
    QSqlQuery query;
    if (!query.exec(createTableSql)) {
        qCritical() << "创建表失败:" << query.lastError().text();
        m_db.close();
        return false;
    }
    return true;
}

bool VideoDao::insertVideo(const Video &video)
{
    if (existsByPath(video.path())) {
        m_lastError = "视频已存在"; // 记录错误
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO t_video (name, path) "
                  "VALUES (:name, :path)");
    query.bindValue(":name", video.name());
    query.bindValue(":path", video.path());

    if (!query.exec()) {
        m_lastError = query.lastError().text(); // 记录SQL错误
        return false;
    }
    m_lastError.clear(); // 成功则清空错误
    return true;
}

QList<Video> VideoDao::queryVideos()
{
    QList<Video> videoList;
    QSqlQuery query("SELECT id, name, path FROM t_video");

    while (query.next()) {
        Video video;
        video.setId(query.value(0).toInt());
        video.setName(query.value(1).toString());
        video.setPath(query.value(2).toString());
        videoList.append(video);
    }

    if (query.lastError().isValid()) {
        qWarning() << "查询数据失败:" << query.lastError().text();
    }
    return videoList;
}

bool VideoDao::existsByPath(const QString &path)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM t_video WHERE path = :path");
    query.bindValue(":path", path);
    query.exec();
    if (query.next()) {
        return query.value(0).toInt() > 0;
    }
    return false;
}
