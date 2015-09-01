/****************************************************************************
** Meta object code from reading C++ file 'RecoveryPointsParserThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RecoveryPointsParserThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RecoveryPointsParserThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RecoveryPointsParserThread_t {
    QByteArrayData data[8];
    char stringdata[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RecoveryPointsParserThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RecoveryPointsParserThread_t qt_meta_stringdata_RecoveryPointsParserThread = {
    {
QT_MOC_LITERAL(0, 0, 26),
QT_MOC_LITERAL(1, 27, 14),
QT_MOC_LITERAL(2, 42, 0),
QT_MOC_LITERAL(3, 43, 16),
QT_MOC_LITERAL(4, 60, 11),
QT_MOC_LITERAL(5, 72, 7),
QT_MOC_LITERAL(6, 80, 5),
QT_MOC_LITERAL(7, 86, 19)
    },
    "RecoveryPointsParserThread\0parsingStarted\0"
    "\0parsingCompleted\0agentParsed\0current\0"
    "total\0recoveryPointParsed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RecoveryPointsParserThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    2,   36,    2, 0x06 /* Public */,
       7,    2,   41,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    5,    6,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    5,    6,

       0        // eod
};

void RecoveryPointsParserThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RecoveryPointsParserThread *_t = static_cast<RecoveryPointsParserThread *>(_o);
        switch (_id) {
        case 0: _t->parsingStarted(); break;
        case 1: _t->parsingCompleted(); break;
        case 2: _t->agentParsed((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 3: _t->recoveryPointParsed((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RecoveryPointsParserThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RecoveryPointsParserThread::parsingStarted)) {
                *result = 0;
            }
        }
        {
            typedef void (RecoveryPointsParserThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RecoveryPointsParserThread::parsingCompleted)) {
                *result = 1;
            }
        }
        {
            typedef void (RecoveryPointsParserThread::*_t)(uint , uint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RecoveryPointsParserThread::agentParsed)) {
                *result = 2;
            }
        }
        {
            typedef void (RecoveryPointsParserThread::*_t)(uint , uint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RecoveryPointsParserThread::recoveryPointParsed)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject RecoveryPointsParserThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_RecoveryPointsParserThread.data,
      qt_meta_data_RecoveryPointsParserThread,  qt_static_metacall, 0, 0}
};


const QMetaObject *RecoveryPointsParserThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RecoveryPointsParserThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RecoveryPointsParserThread.stringdata))
        return static_cast<void*>(const_cast< RecoveryPointsParserThread*>(this));
    if (!strcmp(_clname, "IRecoveryPointsParserListener"))
        return static_cast< IRecoveryPointsParserListener*>(const_cast< RecoveryPointsParserThread*>(this));
    return QThread::qt_metacast(_clname);
}

int RecoveryPointsParserThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void RecoveryPointsParserThread::parsingStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void RecoveryPointsParserThread::parsingCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void RecoveryPointsParserThread::agentParsed(uint _t1, uint _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RecoveryPointsParserThread::recoveryPointParsed(uint _t1, uint _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
