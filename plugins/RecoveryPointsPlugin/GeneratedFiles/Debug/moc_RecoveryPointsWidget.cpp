/****************************************************************************
** Meta object code from reading C++ file 'RecoveryPointsWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RecoveryPointsWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RecoveryPointsWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RecoveryPointsWidget_t {
    QByteArrayData data[11];
    char stringdata[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RecoveryPointsWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RecoveryPointsWidget_t qt_meta_stringdata_RecoveryPointsWidget = {
    {
QT_MOC_LITERAL(0, 0, 20),
QT_MOC_LITERAL(1, 21, 21),
QT_MOC_LITERAL(2, 43, 0),
QT_MOC_LITERAL(3, 44, 24),
QT_MOC_LITERAL(4, 69, 19),
QT_MOC_LITERAL(5, 89, 14),
QT_MOC_LITERAL(6, 104, 17),
QT_MOC_LITERAL(7, 122, 13),
QT_MOC_LITERAL(8, 136, 7),
QT_MOC_LITERAL(9, 144, 5),
QT_MOC_LITERAL(10, 150, 21)
    },
    "RecoveryPointsWidget\0onAgentCurrentChanged\0"
    "\0onExchangeCurrentChanged\0onSqlCurrentChanged\0"
    "onStartParsing\0onCompleteParsing\0"
    "onAgentParsed\0current\0total\0"
    "onRecoveryPointParsed\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RecoveryPointsWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x08,
       3,    2,   54,    2, 0x08,
       4,    2,   59,    2, 0x08,
       5,    0,   64,    2, 0x08,
       6,    0,   65,    2, 0x08,
       7,    2,   66,    2, 0x08,
      10,    2,   71,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    2,    2,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    2,    2,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    8,    9,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    8,    9,

       0        // eod
};

void RecoveryPointsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RecoveryPointsWidget *_t = static_cast<RecoveryPointsWidget *>(_o);
        switch (_id) {
        case 0: _t->onAgentCurrentChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 1: _t->onExchangeCurrentChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 2: _t->onSqlCurrentChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 3: _t->onStartParsing(); break;
        case 4: _t->onCompleteParsing(); break;
        case 5: _t->onAgentParsed((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 6: _t->onRecoveryPointParsed((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject RecoveryPointsWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RecoveryPointsWidget.data,
      qt_meta_data_RecoveryPointsWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *RecoveryPointsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RecoveryPointsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RecoveryPointsWidget.stringdata))
        return static_cast<void*>(const_cast< RecoveryPointsWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int RecoveryPointsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
