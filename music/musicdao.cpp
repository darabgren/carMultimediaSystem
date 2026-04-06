#include "music/musicdao.h"
#include <QStandardPaths>
#include <QDir>
#include <QDebug>
#include <QtSql/QSqlError>
#include "common/common.h"

MusicDao::MusicDao() {
    QString musicDir = getProjectMusicPath(); // 假设返回 "项目根/music"（无斜杠）
    QDir dir(musicDir);
    QString databasePath = dir.filePath("music.db"); // 自动添加斜杠
    // 等效于：musicDir + "/" + "music.db"
    initDatabase(databasePath); //初始化数据库
}

bool MusicDao::initDatabase(const QString &databasePath){
     m_db = QSqlDatabase::addDatabase("QSQLITE");
     m_db.setDatabaseName(databasePath);
     if (!m_db.open()) {
         qCritical() << "数据库打开失败:" << m_db.lastError().text();
         return false;
     }
     // 创建表t_music（如果不存在）
     QString createTableSql = "CREATE TABLE IF NOT EXISTS t_music ("
                              "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                              "name TEXT NOT NULL,"
                              "path TEXT UNIQUE NOT NULL," // path设为唯一索引，避免重复
                              "lrc_path TEXT,"
                              "cover TEXT"
                              ");";
    QSqlQuery query;
    if (!query.exec(createTableSql)) {
         qCritical() << "创建表失败:" << query.lastError().text();
         m_db.close();
         return false;
     }
     return true;
}
bool MusicDao::insertMusic(const Music &music)
{
    if (existsByPath(music.path())) {
        m_lastError = "歌曲已存在"; // 记录错误
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO t_music (name, path, lrc_path, cover) "
                  "VALUES (:name, :path, :lrc_path, :cover)");
    query.bindValue(":name", music.name());
    query.bindValue(":path", music.path());
    query.bindValue(":lrc_path", music.lrcPath());
    query.bindValue(":cover", music.cover());

    if (!query.exec()) {
        m_lastError = query.lastError().text(); // 记录SQL错误
        return false;
    }
    m_lastError.clear(); // 成功则清空错误
    return true;
}
QList<Music> MusicDao::queryMusics()
{
    QList<Music> musicList;
    QSqlQuery query("SELECT id, name, path, lrc_path, cover FROM t_music");

    while (query.next()) {
        Music music;
        music.setId(query.value(0).toInt());
        music.setName(query.value(1).toString());
        music.setPath(query.value(2).toString());
        music.setLrcPath(query.value(3).toString());
        music.setCover(query.value(4).toString());
        musicList.append(music);
    }

    if (query.lastError().isValid()) {
        qWarning() << "查询数据失败:" << query.lastError().text();
    }
    return musicList;
}

bool MusicDao::existsByPath(const QString &path)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM t_music WHERE path = :path");
    query.bindValue(":path", path);
    query.exec();
    if (query.next()) {
        return query.value(0).toInt() > 0;
    }
    return false;
}


