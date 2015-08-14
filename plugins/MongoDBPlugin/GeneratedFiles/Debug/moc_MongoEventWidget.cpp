/****************************************************************************
** Meta object code from reading C++ file 'MongoEventWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MongoEventWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MongoEventWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MongoEventWidget_t {
    QByteArrayData data[8];
    char stringdata[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MongoEventWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MongoEventWidget_t qt_meta_stringdata_MongoEventWidget = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 20),
QT_MOC_LITERAL(2, 38, 0),
QT_MOC_LITERAL(3, 39, 18),
QT_MOC_LITERAL(4, 58, 8),
QT_MOC_LITERAL(5, 67, 6),
QT_MOC_LITERAL(6, 74, 23),
QT_MOC_LITERAL(7, 98, 20)
    },
    "MongoEventWidget\0onEventsStartParsing\0"
    "\0onEventsItemParsed\0iCurrent\0iTotal\0"
    "onEventsCompleteParsing\0onApplyButtonClicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MongoEventWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08,
       3,    2,   35,    2, 0x08,
       6,    0,   40,    2, 0x08,
       7,    0,   41,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MongoEventWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MongoEventWidget *_t = static_cast<MongoEventWidget *>(_o);
        switch (_id) {
        case 0: _t->onEventsStartParsing(); break;
        case 1: _t->onEventsItemParsed((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 2: _t->onEventsCompleteParsing(); break;
        case 3: _t->onApplyButtonClicked(); break;
        default: ;
        }
    }
}

const QMetaObject MongoEventWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MongoEventWidget.data,
      qt_meta_data_MongoEventWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *MongoEventWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MongoEventWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MongoEventWidget.stringdata))
        return static_cast<void*>(const_cast< MongoEventWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MongoEventWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
