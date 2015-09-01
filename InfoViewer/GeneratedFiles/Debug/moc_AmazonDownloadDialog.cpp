/****************************************************************************
** Meta object code from reading C++ file 'AmazonDownloadDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AmazonDownloadDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AmazonDownloadDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AmazonDownloadDialog_t {
    QByteArrayData data[20];
    char stringdata[324];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AmazonDownloadDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AmazonDownloadDialog_t qt_meta_stringdata_AmazonDownloadDialog = {
    {
QT_MOC_LITERAL(0, 0, 20),
QT_MOC_LITERAL(1, 21, 13),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 15),
QT_MOC_LITERAL(4, 52, 17),
QT_MOC_LITERAL(5, 70, 21),
QT_MOC_LITERAL(6, 92, 20),
QT_MOC_LITERAL(7, 113, 8),
QT_MOC_LITERAL(8, 122, 9),
QT_MOC_LITERAL(9, 132, 14),
QT_MOC_LITERAL(10, 147, 15),
QT_MOC_LITERAL(11, 163, 6),
QT_MOC_LITERAL(12, 170, 15),
QT_MOC_LITERAL(13, 186, 21),
QT_MOC_LITERAL(14, 208, 21),
QT_MOC_LITERAL(15, 230, 19),
QT_MOC_LITERAL(16, 250, 7),
QT_MOC_LITERAL(17, 258, 20),
QT_MOC_LITERAL(18, 279, 21),
QT_MOC_LITERAL(19, 301, 22)
    },
    "AmazonDownloadDialog\0logsCompleted\0\0"
    "onSearchClicked\0onDownloadClicked\0"
    "onBrowseButtonClicked\0onCurrentLinkChanged\0"
    "iCurrent\0iPrevious\0onUnZipStarted\0"
    "onUnZipProgress\0iTotal\0onUnZipComplete\0"
    "onStartRetrievingList\0onObjectListRetrieved\0"
    "QList<AmazonObject>\0objects\0"
    "onDownloadingStarted\0onDownloadingProgress\0"
    "onDownloadingCompleted"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AmazonDownloadDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    2,   83,    2, 0x08 /* Private */,
       9,    0,   88,    2, 0x08 /* Private */,
      10,    2,   89,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    1,   96,    2, 0x08 /* Private */,
      17,    0,   99,    2, 0x08 /* Private */,
      18,    2,  100,    2, 0x08 /* Private */,
      19,    0,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    7,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    7,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    7,   11,
    QMetaType::Void,

       0        // eod
};

void AmazonDownloadDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AmazonDownloadDialog *_t = static_cast<AmazonDownloadDialog *>(_o);
        switch (_id) {
        case 0: _t->logsCompleted(); break;
        case 1: _t->onSearchClicked(); break;
        case 2: _t->onDownloadClicked(); break;
        case 3: _t->onBrowseButtonClicked(); break;
        case 4: _t->onCurrentLinkChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 5: _t->onUnZipStarted(); break;
        case 6: _t->onUnZipProgress((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 7: _t->onUnZipComplete(); break;
        case 8: _t->onStartRetrievingList(); break;
        case 9: _t->onObjectListRetrieved((*reinterpret_cast< const QList<AmazonObject>(*)>(_a[1]))); break;
        case 10: _t->onDownloadingStarted(); break;
        case 11: _t->onDownloadingProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 12: _t->onDownloadingCompleted(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AmazonDownloadDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AmazonDownloadDialog::logsCompleted)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject AmazonDownloadDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AmazonDownloadDialog.data,
      qt_meta_data_AmazonDownloadDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *AmazonDownloadDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AmazonDownloadDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AmazonDownloadDialog.stringdata))
        return static_cast<void*>(const_cast< AmazonDownloadDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int AmazonDownloadDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void AmazonDownloadDialog::logsCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
