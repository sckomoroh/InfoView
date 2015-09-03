/****************************************************************************
** Meta object code from reading C++ file 'SearchResultWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SearchResultWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SearchResultWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SearchResultWidget_t {
    QByteArrayData data[11];
    char stringdata[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SearchResultWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SearchResultWidget_t qt_meta_stringdata_SearchResultWidget = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 13),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 19),
QT_MOC_LITERAL(4, 54, 5),
QT_MOC_LITERAL(5, 60, 13),
QT_MOC_LITERAL(6, 74, 32),
QT_MOC_LITERAL(7, 107, 13),
QT_MOC_LITERAL(8, 121, 12),
QT_MOC_LITERAL(9, 134, 15),
QT_MOC_LITERAL(10, 150, 14)
    },
    "SearchResultWidget\0doubleCLicked\0\0"
    "CustomTextViewLine*\0pLine\0onSeachResult\0"
    "QList<CustomTextViewSearchLine*>\0"
    "searchStrings\0clearResults\0onDoubleClicked\0"
    "onClearResults"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SearchResultWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   42,    2, 0x0a /* Public */,
       8,    0,   45,    2, 0x0a /* Public */,
       9,    1,   46,    2, 0x08 /* Private */,
      10,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void SearchResultWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SearchResultWidget *_t = static_cast<SearchResultWidget *>(_o);
        switch (_id) {
        case 0: _t->doubleCLicked((*reinterpret_cast< CustomTextViewLine*(*)>(_a[1]))); break;
        case 1: _t->onSeachResult((*reinterpret_cast< QList<CustomTextViewSearchLine*>(*)>(_a[1]))); break;
        case 2: _t->clearResults(); break;
        case 3: _t->onDoubleClicked((*reinterpret_cast< CustomTextViewLine*(*)>(_a[1]))); break;
        case 4: _t->onClearResults(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SearchResultWidget::*_t)(CustomTextViewLine * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SearchResultWidget::doubleCLicked)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject SearchResultWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SearchResultWidget.data,
      qt_meta_data_SearchResultWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *SearchResultWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SearchResultWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SearchResultWidget.stringdata))
        return static_cast<void*>(const_cast< SearchResultWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SearchResultWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void SearchResultWidget::doubleCLicked(CustomTextViewLine * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
