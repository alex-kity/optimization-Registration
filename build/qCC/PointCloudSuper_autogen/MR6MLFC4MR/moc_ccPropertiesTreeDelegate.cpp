/****************************************************************************
** Meta object code from reading C++ file 'ccPropertiesTreeDelegate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../qCC/db_tree/ccPropertiesTreeDelegate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ccPropertiesTreeDelegate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ccPropertiesTreeDelegate_t {
    QByteArrayData data[7];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ccPropertiesTreeDelegate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ccPropertiesTreeDelegate_t qt_meta_stringdata_ccPropertiesTreeDelegate = {
    {
QT_MOC_LITERAL(0, 0, 24), // "ccPropertiesTreeDelegate"
QT_MOC_LITERAL(1, 25, 25), // "ccObjectPropertiesChanged"
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 10), // "ccHObject*"
QT_MOC_LITERAL(4, 63, 7), // "hObject"
QT_MOC_LITERAL(5, 71, 25), // "ccObjectAppearanceChanged"
QT_MOC_LITERAL(6, 97, 36) // "ccObjectAndChildrenAppearance..."

    },
    "ccPropertiesTreeDelegate\0"
    "ccObjectPropertiesChanged\0\0ccHObject*\0"
    "hObject\0ccObjectAppearanceChanged\0"
    "ccObjectAndChildrenAppearanceChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ccPropertiesTreeDelegate[] = {

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
       1,    1,   29,    2, 0x06 /* Public */,
       5,    1,   32,    2, 0x06 /* Public */,
       6,    1,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void ccPropertiesTreeDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ccPropertiesTreeDelegate *_t = static_cast<ccPropertiesTreeDelegate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ccObjectPropertiesChanged((*reinterpret_cast< ccHObject*(*)>(_a[1]))); break;
        case 1: _t->ccObjectAppearanceChanged((*reinterpret_cast< ccHObject*(*)>(_a[1]))); break;
        case 2: _t->ccObjectAndChildrenAppearanceChanged((*reinterpret_cast< ccHObject*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ccPropertiesTreeDelegate::*_t)(ccHObject * ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ccPropertiesTreeDelegate::ccObjectPropertiesChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (ccPropertiesTreeDelegate::*_t)(ccHObject * ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ccPropertiesTreeDelegate::ccObjectAppearanceChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (ccPropertiesTreeDelegate::*_t)(ccHObject * ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ccPropertiesTreeDelegate::ccObjectAndChildrenAppearanceChanged)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject ccPropertiesTreeDelegate::staticMetaObject = {
    { &QStyledItemDelegate::staticMetaObject, qt_meta_stringdata_ccPropertiesTreeDelegate.data,
      qt_meta_data_ccPropertiesTreeDelegate,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ccPropertiesTreeDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ccPropertiesTreeDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ccPropertiesTreeDelegate.stringdata0))
        return static_cast<void*>(const_cast< ccPropertiesTreeDelegate*>(this));
    return QStyledItemDelegate::qt_metacast(_clname);
}

int ccPropertiesTreeDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStyledItemDelegate::qt_metacall(_c, _id, _a);
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
void ccPropertiesTreeDelegate::ccObjectPropertiesChanged(ccHObject * _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< ccPropertiesTreeDelegate *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ccPropertiesTreeDelegate::ccObjectAppearanceChanged(ccHObject * _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< ccPropertiesTreeDelegate *>(this), &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ccPropertiesTreeDelegate::ccObjectAndChildrenAppearanceChanged(ccHObject * _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< ccPropertiesTreeDelegate *>(this), &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
