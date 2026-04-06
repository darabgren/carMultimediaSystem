/****************************************************************************
** Meta object code from reading C++ file 'videowindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../video/videowindow.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videowindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN11VideoWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto VideoWindow::qt_create_metaobjectdata<qt_meta_tag_ZN11VideoWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "VideoWindow",
        "on_btn_quit_clicked",
        "",
        "on_volumeSlider_valueChanged",
        "value",
        "on_btn_volume_clicked",
        "on_btn_file_clicked",
        "on_list_local_2_itemDoubleClicked",
        "QListWidgetItem*",
        "item",
        "on_btn_pre_clicked",
        "on_btn_next_clicked",
        "on_btn_play_clicked",
        "on_progressSlider_sliderReleased",
        "durationChanged",
        "duration",
        "positionChanged",
        "position",
        "on_btn_fullScreen_clicked",
        "showOnlineList",
        "QNetworkReply*",
        "reply",
        "on_tabWidget_currentChanged",
        "index",
        "on_list_online_2_itemDoubleClicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_btn_quit_clicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_volumeSlider_valueChanged'
        QtMocHelpers::SlotData<void(int)>(3, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 4 },
        }}),
        // Slot 'on_btn_volume_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btn_file_clicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_list_local_2_itemDoubleClicked'
        QtMocHelpers::SlotData<void(QListWidgetItem *)>(7, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Slot 'on_btn_pre_clicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btn_next_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btn_play_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_progressSlider_sliderReleased'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'durationChanged'
        QtMocHelpers::SlotData<void(qint64)>(14, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::LongLong, 15 },
        }}),
        // Slot 'positionChanged'
        QtMocHelpers::SlotData<void(qint64)>(16, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::LongLong, 17 },
        }}),
        // Slot 'on_btn_fullScreen_clicked'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'showOnlineList'
        QtMocHelpers::SlotData<void(QNetworkReply *)>(19, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 20, 21 },
        }}),
        // Slot 'on_tabWidget_currentChanged'
        QtMocHelpers::SlotData<void(int)>(22, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 23 },
        }}),
        // Slot 'on_list_online_2_itemDoubleClicked'
        QtMocHelpers::SlotData<void(QListWidgetItem *)>(24, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 8, 9 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<VideoWindow, qt_meta_tag_ZN11VideoWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject VideoWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11VideoWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11VideoWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11VideoWindowE_t>.metaTypes,
    nullptr
} };

void VideoWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<VideoWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_btn_quit_clicked(); break;
        case 1: _t->on_volumeSlider_valueChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->on_btn_volume_clicked(); break;
        case 3: _t->on_btn_file_clicked(); break;
        case 4: _t->on_list_local_2_itemDoubleClicked((*reinterpret_cast<std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 5: _t->on_btn_pre_clicked(); break;
        case 6: _t->on_btn_next_clicked(); break;
        case 7: _t->on_btn_play_clicked(); break;
        case 8: _t->on_progressSlider_sliderReleased(); break;
        case 9: _t->durationChanged((*reinterpret_cast<std::add_pointer_t<qint64>>(_a[1]))); break;
        case 10: _t->positionChanged((*reinterpret_cast<std::add_pointer_t<qint64>>(_a[1]))); break;
        case 11: _t->on_btn_fullScreen_clicked(); break;
        case 12: _t->showOnlineList((*reinterpret_cast<std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 13: _t->on_tabWidget_currentChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->on_list_online_2_itemDoubleClicked((*reinterpret_cast<std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *VideoWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11VideoWindowE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int VideoWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
