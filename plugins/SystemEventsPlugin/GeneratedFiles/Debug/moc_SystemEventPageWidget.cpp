/****************************************************************************
** Meta object code from reading C++ file 'SystemEventPageWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SystemEventPageWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SystemEventPageWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SystemEventPageWidget_t {
    QByteArrayData data[18];
    char stringdata[268];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SystemEventPageWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SystemEventPageWidget_t qt_meta_stringdata_SystemEventPageWidget = {
    {
QT_MOC_LITERAL(0, 0, 21),
QT_MOC_LITERAL(1, 22, 16),
QT_MOC_LITERAL(2, 39, 0),
QT_MOC_LITERAL(3, 40, 13),
QT_MOC_LITERAL(4, 54, 7),
QT_MOC_LITERAL(5, 62, 6),
QT_MOC_LITERAL(6, 69, 18),
QT_MOC_LITERAL(7, 88, 19),
QT_MOC_LITERAL(8, 108, 5),
QT_MOC_LITERAL(9, 114, 8),
QT_MOC_LITERAL(10, 123, 24),
QT_MOC_LITERAL(11, 148, 20),
QT_MOC_LITERAL(12, 169, 18),
QT_MOC_LITERAL(13, 188, 5),
QT_MOC_LITERAL(14, 194, 14),
QT_MOC_LITERAL(15, 209, 14),
QT_MOC_LITERAL(16, 224, 20),
QT_MOC_LITERAL(17, 245, 22)
    },
    "SystemEventPageWidget\0onParsingStarted\0"
    "\0onEventParsed\0iCurent\0iTotal\0"
    "onParsingCompletes\0onCurrentJobChanged\0"
    "index\0oldIndex\0onCurrentProviderChanged\0"
    "onFilterApplyClicked\0onTableContextMenu\0"
    "point\0onIncludeEvent\0onExcludeEvent\0"
    "onSelectAllProviders\0onUnselectAllProviders"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SystemEventPageWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    2,   70,    2, 0x08 /* Private */,
       6,    0,   75,    2, 0x08 /* Private */,
       7,    2,   76,    2, 0x08 /* Private */,
      10,    2,   81,    2, 0x08 /* Private */,
      11,    0,   86,    2, 0x08 /* Private */,
      12,    1,   87,    2, 0x08 /* Private */,
      14,    0,   90,    2, 0x08 /* Private */,
      15,    0,   91,    2, 0x08 /* Private */,
      16,    0,   92,    2, 0x08 /* Private */,
      17,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    8,    9,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SystemEventPageWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SystemEventPageWidget *_t = static_cast<SystemEventPageWidget *>(_o);
        switch (_id) {
        case 0: _t->onParsingStarted(); break;
        case 1: _t->onEventParsed((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 2: _t->onParsingCompletes(); break;
        case 3: _t->onCurrentJobChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 4: _t->onCurrentProviderChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 5: _t->onFilterApplyClicked(); break;
        case 6: _t->onTableContextMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 7: _t->onIncludeEvent(); break;
        case 8: _t->onExcludeEvent(); break;
        case 9: _t->onSelectAllProviders(); break;
        case 10: _t->onUnselectAllProviders(); break;
        default: ;
        }
    }
}

const QMetaObject SystemEventPageWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SystemEventPageWidget.data,
      qt_meta_data_SystemEventPageWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *SystemEventPageWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SystemEventPageWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SystemEventPageWidget.stringdata))
        return static_cast<void*>(const_cast< SystemEventPageWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SystemEventPageWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
