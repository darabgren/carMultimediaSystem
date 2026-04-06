/****************************************************************************
** Meta object code from reading C++ file 'musicwindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../music/musicwindow.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'musicwindow.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11MusicWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto MusicWindow::qt_create_metaobjectdata<qt_meta_tag_ZN11MusicWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MusicWindow",
        "on_btn_play_clicked",
        "",
        "on_btn_quit_clicked",
        "on_btn_file_clicked",
        "on_list_local_itemDoubleClicked",
        "QListWidgetItem*",
        "item",
        "on_btn_next_clicked",
        "on_btn_pre_clicked",
        "durationChanged",
        "duration",
        "positionChanged",
        "position",
        "on_progressSlider_sliderReleased",
        "on_btn_volume_clicked",
        "on_volumeSlider_valueChanged",
        "value",
        "updateLyrics",
        "currentTime",
        "showOnlineList",
        "QNetworkReply*",
        "reply",
        "on_list_online_itemDoubleClicked",
        "on_tabWidget_currentChanged",
        "index"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_btn_play_clicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btn_quit_clicked'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btn_file_clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_list_local_itemDoubleClicked'
        QtMocHelpers::SlotData<void(QListWidgetItem *)>(5, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
        // Slot 'on_btn_next_clicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btn_pre_clicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'durationChanged'
        QtMocHelpers::SlotData<void(qint64)>(10, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::LongLong, 11 },
        }}),
        // Slot 'positionChanged'
        QtMocHelpers::SlotData<void(qint64)>(12, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::LongLong, 13 },
        }}),
        // Slot 'on_progressSlider_sliderReleased'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btn_volume_clicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_volumeSlider_valueChanged'
        QtMocHelpers::SlotData<void(int)>(16, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 17 },
        }}),
        // Slot 'updateLyrics'
        QtMocHelpers::SlotData<void(qint64)>(18, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::LongLong, 19 },
        }}),
        // Slot 'showOnlineList'
        QtMocHelpers::SlotData<void(QNetworkReply *)>(20, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 21, 22 },
        }}),
        // Slot 'on_list_online_itemDoubleClicked'
        QtMocHelpers::SlotData<void(QListWidgetItem *)>(23, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
        // Slot 'on_tabWidget_currentChanged'
        QtMocHelpers::SlotData<void(int)>(24, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 25 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MusicWindow, qt_meta_tag_ZN11MusicWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MusicWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11MusicWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11MusicWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11MusicWindowE_t>.metaTypes,
    nullptr
} };

void MusicWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MusicWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_btn_play_clicked(); break;
        case 1: _t->on_btn_quit_clicked(); break;
        case 2: _t->on_btn_file_clicked(); break;
        case 3: _t->on_list_local_itemDoubleClicked((*reinterpret_cast<std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 4: _t->on_btn_next_clicked(); break;
        case 5: _t->on_btn_pre_clicked(); break;
        case 6: _t->durationChanged((*reinterpret_cast<std::add_pointer_t<qint64>>(_a[1]))); break;
        case 7: _t->positionChanged((*reinterpret_cast<std::add_pointer_t<qint64>>(_a[1]))); break;
        case 8: _t->on_progressSlider_sliderReleased(); break;
        case 9: _t->on_btn_volume_clicked(); break;
        case 10: _t->on_volumeSlider_valueChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->updateLyrics((*reinterpret_cast<std::add_pointer_t<qint64>>(_a[1]))); break;
        case 12: _t->showOnlineList((*reinterpret_cast<std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 13: _t->on_list_online_itemDoubleClicked((*reinterpret_cast<std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 14: _t->on_tabWidget_currentChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
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

const QMetaObject *MusicWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11MusicWindowE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MusicWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
