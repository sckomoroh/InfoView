/****************************************************************************
** Meta object code from reading C++ file 'UnZipThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UnZipThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UnZipThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UnZipThread_t {
    QByteArrayData data[7];
    char stringdata[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UnZipThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UnZipThread_t qt_meta_stringdata_UnZipThread = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 12),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 13),
QT_MOC_LITERAL(4, 40, 9),
QT_MOC_LITERAL(5, 50, 6),
QT_MOC_LITERAL(6, 57, 13)
    },
    "UnZipThread\0unzipStarted\0\0unzipProgress\0"
    "iCurrenty\0iTotal\0unzipComplete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UnZipThread[] = {

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
       1,    0,   29,    2, 0x06 /* Public */,
       3,    2,   30,    2, 0x06 /* Public */,
       6,    0,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    4,    5,
    QMetaType::Void,

       0        // eod
};

void UnZipThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UnZipThread *_t = static_cast<UnZipThread *>(_o);
        switch (_id) {
        case 0: _t->unzipStarted(); break;
        case 1: _t->unzipProgress((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 2: _t->unzipComplete(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UnZipThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UnZipThread::unzipStarted)) {
                *result = 0;
            }
        }
        {
            typedef void (UnZipThread::*_t)(uint , uint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UnZipThread::unzipProgress)) {
                *result = 1;
            }
        }
        {
            typedef void (UnZipThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UnZipThread::unzipComplete)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject UnZipThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_UnZipThread.data,
      qt_meta_data_UnZipThread,  qt_static_metacall, 0, 0}
};


const QMetaObject *UnZipThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UnZipThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UnZipThread.stringdata))
        return static_cast<void*>(const_cast< UnZipThread*>(this));
    return QThread::qt_metacast(_clname);
}

int UnZipThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void UnZipThread::unzipStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void UnZipThread::unzipProgress(uint _t1, uint _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void UnZipThread::unzipComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
