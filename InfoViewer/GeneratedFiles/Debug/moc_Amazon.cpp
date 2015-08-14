/****************************************************************************
** Meta object code from reading C++ file 'Amazon.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Amazon.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Amazon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Amazon_t {
    QByteArrayData data[16];
    char stringdata[248];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Amazon_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Amazon_t qt_meta_stringdata_Amazon = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 19),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 19),
QT_MOC_LITERAL(4, 48, 19),
QT_MOC_LITERAL(5, 68, 7),
QT_MOC_LITERAL(6, 76, 18),
QT_MOC_LITERAL(7, 95, 19),
QT_MOC_LITERAL(8, 115, 8),
QT_MOC_LITERAL(9, 124, 6),
QT_MOC_LITERAL(10, 131, 20),
QT_MOC_LITERAL(11, 152, 18),
QT_MOC_LITERAL(12, 171, 17),
QT_MOC_LITERAL(13, 189, 18),
QT_MOC_LITERAL(14, 208, 19),
QT_MOC_LITERAL(15, 228, 18)
    },
    "Amazon\0startRetrievingList\0\0"
    "objectListRetrieved\0QList<AmazonObject>\0"
    "objects\0downloadingStarted\0"
    "downloadingProgress\0iCurrent\0iTotal\0"
    "downloadingCompleted\0onGetListReadyRead\0"
    "onGetListFinished\0onDownloadProgress\0"
    "onDownloadReadyRead\0onDownloadFinished\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Amazon[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06,
       3,    1,   65,    2, 0x06,
       6,    0,   68,    2, 0x06,
       7,    2,   69,    2, 0x06,
      10,    0,   74,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      11,    0,   75,    2, 0x08,
      12,    0,   76,    2, 0x08,
      13,    2,   77,    2, 0x08,
      14,    0,   82,    2, 0x08,
      15,    0,   83,    2, 0x08,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    8,    9,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    8,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Amazon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Amazon *_t = static_cast<Amazon *>(_o);
        switch (_id) {
        case 0: _t->startRetrievingList(); break;
        case 1: _t->objectListRetrieved((*reinterpret_cast< const QList<AmazonObject>(*)>(_a[1]))); break;
        case 2: _t->downloadingStarted(); break;
        case 3: _t->downloadingProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 4: _t->downloadingCompleted(); break;
        case 5: _t->onGetListReadyRead(); break;
        case 6: _t->onGetListFinished(); break;
        case 7: _t->onDownloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 8: _t->onDownloadReadyRead(); break;
        case 9: _t->onDownloadFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Amazon::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Amazon::startRetrievingList)) {
                *result = 0;
            }
        }
        {
            typedef void (Amazon::*_t)(const QList<AmazonObject> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Amazon::objectListRetrieved)) {
                *result = 1;
            }
        }
        {
            typedef void (Amazon::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Amazon::downloadingStarted)) {
                *result = 2;
            }
        }
        {
            typedef void (Amazon::*_t)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Amazon::downloadingProgress)) {
                *result = 3;
            }
        }
        {
            typedef void (Amazon::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Amazon::downloadingCompleted)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject Amazon::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Amazon.data,
      qt_meta_data_Amazon,  qt_static_metacall, 0, 0}
};


const QMetaObject *Amazon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Amazon::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Amazon.stringdata))
        return static_cast<void*>(const_cast< Amazon*>(this));
    return QObject::qt_metacast(_clname);
}

int Amazon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Amazon::startRetrievingList()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Amazon::objectListRetrieved(const QList<AmazonObject> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Amazon::downloadingStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Amazon::downloadingProgress(qint64 _t1, qint64 _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Amazon::downloadingCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
