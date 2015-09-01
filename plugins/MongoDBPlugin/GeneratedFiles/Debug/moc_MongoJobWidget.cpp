/****************************************************************************
** Meta object code from reading C++ file 'MongoJobWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MongoJobWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MongoJobWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MongoJobWidget_t {
    QByteArrayData data[11];
    char stringdata[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MongoJobWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MongoJobWidget_t qt_meta_stringdata_MongoJobWidget = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 18),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 16),
QT_MOC_LITERAL(4, 52, 8),
QT_MOC_LITERAL(5, 61, 6),
QT_MOC_LITERAL(6, 68, 21),
QT_MOC_LITERAL(7, 90, 19),
QT_MOC_LITERAL(8, 110, 5),
QT_MOC_LITERAL(9, 116, 8),
QT_MOC_LITERAL(10, 125, 21)
    },
    "MongoJobWidget\0onJobsStartParsing\0\0"
    "onJobsItemParsed\0iCurrent\0iTotal\0"
    "onJobsCompleteParsing\0onCurrentJobChanged\0"
    "index\0oldIndex\0onJodApplyFilterClick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MongoJobWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    2,   40,    2, 0x08 /* Private */,
       6,    0,   45,    2, 0x08 /* Private */,
       7,    2,   46,    2, 0x08 /* Private */,
      10,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    8,    9,
    QMetaType::Void,

       0        // eod
};

void MongoJobWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MongoJobWidget *_t = static_cast<MongoJobWidget *>(_o);
        switch (_id) {
        case 0: _t->onJobsStartParsing(); break;
        case 1: _t->onJobsItemParsed((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 2: _t->onJobsCompleteParsing(); break;
        case 3: _t->onCurrentJobChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 4: _t->onJodApplyFilterClick(); break;
        default: ;
        }
    }
}

const QMetaObject MongoJobWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MongoJobWidget.data,
      qt_meta_data_MongoJobWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *MongoJobWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MongoJobWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MongoJobWidget.stringdata))
        return static_cast<void*>(const_cast< MongoJobWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MongoJobWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
