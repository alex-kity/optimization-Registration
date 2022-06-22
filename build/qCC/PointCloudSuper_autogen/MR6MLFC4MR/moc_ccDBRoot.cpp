/****************************************************************************
** Meta object code from reading C++ file 'ccDBRoot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../qCC/db_tree/ccDBRoot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ccDBRoot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ccCustomQTreeView_t {
    QByteArrayData data[1];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ccCustomQTreeView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ccCustomQTreeView_t qt_meta_stringdata_ccCustomQTreeView = {
    {
QT_MOC_LITERAL(0, 0, 17) // "ccCustomQTreeView"

    },
    "ccCustomQTreeView"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ccCustomQTreeView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void ccCustomQTreeView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject ccCustomQTreeView::staticMetaObject = {
    { &QTreeView::staticMetaObject, qt_meta_stringdata_ccCustomQTreeView.data,
      qt_meta_data_ccCustomQTreeView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ccCustomQTreeView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ccCustomQTreeView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ccCustomQTreeView.stringdata0))
        return static_cast<void*>(const_cast< ccCustomQTreeView*>(this));
    return QTreeView::qt_metacast(_clname);
}

int ccCustomQTreeView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_ccDBRoot_t {
    QByteArrayData data[5];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ccDBRoot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ccDBRoot_t qt_meta_stringdata_ccDBRoot = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ccDBRoot"
QT_MOC_LITERAL(1, 9, 16), // "selectionChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "dbIsEmpty"
QT_MOC_LITERAL(4, 37, 19) // "dbIsNotEmptyAnymore"

    },
    "ccDBRoot\0selectionChanged\0\0dbIsEmpty\0"
    "dbIsNotEmptyAnymore"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ccDBRoot[] = {

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
       3,    0,   30,    2, 0x06 /* Public */,
       4,    0,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ccDBRoot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ccDBRoot *_t = static_cast<ccDBRoot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectionChanged(); break;
        case 1: _t->dbIsEmpty(); break;
        case 2: _t->dbIsNotEmptyAnymore(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ccDBRoot::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ccDBRoot::selectionChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (ccDBRoot::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ccDBRoot::dbIsEmpty)) {
                *result = 1;
            }
        }
        {
            typedef void (ccDBRoot::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ccDBRoot::dbIsNotEmptyAnymore)) {
                *result = 2;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ccDBRoot::staticMetaObject = {
    { &QAbstractItemModel::staticMetaObject, qt_meta_stringdata_ccDBRoot.data,
      qt_meta_data_ccDBRoot,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ccDBRoot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ccDBRoot::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ccDBRoot.stringdata0))
        return static_cast<void*>(const_cast< ccDBRoot*>(this));
    return QAbstractItemModel::qt_metacast(_clname);
}

int ccDBRoot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
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
void ccDBRoot::selectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ccDBRoot::dbIsEmpty()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void ccDBRoot::dbIsNotEmptyAnymore()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
