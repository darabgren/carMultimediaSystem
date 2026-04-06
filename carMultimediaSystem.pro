QT       += core gui network multimedia sql multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
# common
    common/clickedpauseeventfilter.cpp \
    common/labelclickeventfilter.cpp \
    main.cpp \
    mainwindow.cpp \
# weatheer
    weather/weatherwindow.cpp \
# music
    music/lyriccontainer.cpp \
    music/music.cpp \
    music/musicdao.cpp \
    music/musicwindow.cpp \
# video
    video/video.cpp \
    video/videodao.cpp \
    video/videowindow.cpp \
    video/exitfullscreeneventfilter.cpp \
# map
    map/mapdraggingeventfilter.cpp \
    map/wheeleventfilter.cpp \
    map/mapwindow.cpp \
# photo
    photo/photowindow.cpp \
# gobang
    gobang/gobangwindow.cpp \
    gobang/stone.cpp

HEADERS += \
# common
    common/clickedpauseeventfilter.h \
    common/common.h \
    common/labelclickeventfilter.h \
    mainwindow.h \
# weather
    weather/weatherwindow.h \
# music
    music/lyriccontainer.h \
    music/music.h \
    music/musicdao.h \
    music/musicwindow.h \
# video
    video/video.h \
    video/videodao.h \
    video/videowindow.h \
    video/exitfullscreeneventfilter.h \
# map
    map/mapdraggingeventfilter.h \
    map/wheeleventfilter.h \
    map/mapwindow.h \
# photo
    photo/photowindow.h \
# gobang
    gobang/stone.h \
    gobang/gobangwindow.h

FORMS += \
    mainwindow.ui \
    mapwindow.ui \
    musicwindow.ui \
    photowindow.ui \
    videowindow.ui \
    weatherwindow.ui\
    gobangwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resourse.qrc

DISTFILES +=

# 定义项目源路径
DEFINES +=PROJECT_SOURCE_DIR=\\\"$$PWD\\\"

# exe图标logo.ico
RC_ICONS = logo.ico

