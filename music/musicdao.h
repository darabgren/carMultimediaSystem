#ifndef MUSICDAO_H
#define MUSICDAO_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QList>
#include "music.h"
#include <QString>

class MusicDao
{
public:
    explicit MusicDao();

    bool initDatabase(const QString &databasePath);
    bool insertMusic(const Music &music);
    QList<Music> queryMusics();
    bool existsByPath(const QString &path);
    QString lastError() const { return m_lastError; } // 新增
private:
    QSqlDatabase m_db;
    QString m_lastError; // 记录最后一次错误
};

#endif // MUSICDAO_H
