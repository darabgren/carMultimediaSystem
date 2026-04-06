#ifndef MUSIC_H
#define MUSIC_H

#include <QString>

class Music
{
public:
    // 无参构造函数
    Music() = default;

    // 带参数构造函数
    Music(int id, const QString &name, const QString &path,
          const QString &lrcPath = "", const QString &cover = "")
        : m_id(id), m_name(name), m_path(path), m_lrcPath(lrcPath), m_cover(cover) {}

    // 属性访问器
    int id() const { return m_id; }
    QString name() const { return m_name; }
    QString path() const { return m_path; }
    QString lrcPath() const { return m_lrcPath; }
    QString cover() const { return m_cover; }

    // 设置器（可选）
    void setId(int id) { m_id = id; }
    void setName(const QString &name) { m_name = name; }
    void setPath(const QString &path) { m_path = path; }
    void setLrcPath(const QString &lrcPath) { m_lrcPath = lrcPath; }
    void setCover(const QString &cover) { m_cover = cover; }

private:
    int m_id = 0;          // 主键ID
    QString m_name;        // 歌曲名称
    QString m_path;        // 歌曲文件路径
    QString m_lrcPath;     // LRC歌词路径
    QString m_cover;       // 封面路径
};

#endif // MUSIC_H
