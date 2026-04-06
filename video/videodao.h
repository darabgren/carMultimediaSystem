#ifndef VIDEODAO_H
#define VIDEODAO_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QList>
#include "video.h"
#include <QString>

class VideoDao
{
public:
    VideoDao();
    bool initDatabase(const QString &databasePath);
    bool insertVideo(const Video &video);
    QList<Video> queryVideos();
    bool existsByPath(const QString &path);
    QString lastError() const { return m_lastError; } // 新增
private:
    QSqlDatabase m_db;
    QString m_lastError; // 记录最后一次错误
};

#endif // VIDEODAO_H
