/****************************************************************************
** Meta object code from reading C++ file 'MongoEventParserThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MongoEventParserThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MongoEventParserThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MongoEventParserThread_t {
    QByteArrayData data[7];
    char stringdata[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MongoEventParserThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MongoEventParserThread_t qt_meta_stringdata_MongoEventParserThread = {
    {
QT_MOC_LITERAL(0, 0, 22),
QT_MOC_LITERAL(1, 23, 12),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 10),
QT_MOC_LITERAL(4, 48, 8),
QT_MOC_LITERAL(5, 57, 6),
QT_MOC_LITERAL(6, 64, 15)
    },
    "MongoEventParserThread\0startParsing\0"
    "\0itemParsed\0iCurrent\0iTotal\0completeParsing\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MongoEventParserThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06,
       3,    2,   30,    2, 0x06,
       6,    0,   35,    2, 0x06,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    4,    5,
    QMetaType::Void,

       0        // eod
};

void MongoEventParserThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MongoEventParserThread *_t = static_cast<MongoEventParserThread *>(_o);
        switch (_id) {
        case 0: _t->startParsing(); break;
        case 1: _t->itemParsed((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 2: _t->completeParsing(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MongoEventParserThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MongoEventParserThread::startParsing)) {
                *result = 0;
            }
        }
        {
            typedef void (MongoEventParserThread::*_t)(uint , uint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MongoEventParserThread::itemParsed)) {
                *result = 1;
            }
        }
        {
            typedef void (MongoEventParserThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MongoEventParserThread::completeParsing)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject MongoEventParserThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_MongoEventParserThread.data,
      qt_meta_data_MongoEventParserThread,  qt_static_metacall, 0, 0}
};


const QMetaObject *MongoEventParserThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MongoEventParserThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MongoEventParserThread.stringdata))
        return static_cast<void*>(const_cast< MongoEventParserThread*>(this));
    if (!strcmp(_clname, "IMongoEventParserListener"))
        return static_cast< IMongoEventParserListener*>(const_cast< MongoEventParserThread*>(this));
    return QThread::qt_metacast(_clname);
}

int MongoEventParserThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MongoEventParserThread::startParsing()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MongoEventParserThread::itemParsed(uint _t1, uint _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MongoEventParserThread::completeParsing()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
