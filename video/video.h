#ifndef VIDEO_H
#define VIDEO_H

#include <QString>

class Video
{
public:
    // 无参构造函数
    Video() = default;

    // 带参数构造函数
    Video(int id, const QString &name, const QString &path)
        : m_id(id), m_name(name), m_path(path){}

    // 属性访问器
    int id() const { return m_id; }
    QString name() const { return m_name; }
    QString path() const { return m_path; }

    // 设置器
    void setId(int id) { m_id = id; }
    void setName(const QString &name) { m_name = name; }
    void setPath(const QString &path) { m_path = path; }


private:
    int m_id = 0;          // 主键ID
    QString m_name;        // 视频名称
    QString m_path;        // 视频文件路径
};

#endif // VIDEO_H
