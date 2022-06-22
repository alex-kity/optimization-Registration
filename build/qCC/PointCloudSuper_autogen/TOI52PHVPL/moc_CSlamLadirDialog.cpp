/****************************************************************************
** Meta object code from reading C++ file 'CSlamLadirDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../qCC/slam/CSlamLadirDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CSlamLadirDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CSlamLadirDialog_t {
    QByteArrayData data[11];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CSlamLadirDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CSlamLadirDialog_t qt_meta_stringdata_CSlamLadirDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CSlamLadirDialog"
QT_MOC_LITERAL(1, 17, 15), // "SignalsLoadPath"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 16), // "QList<QVector3D>"
QT_MOC_LITERAL(4, 51, 4), // "_vec"
QT_MOC_LITERAL(5, 56, 19), // "SignalsTestLoadPath"
QT_MOC_LITERAL(6, 76, 15), // "SignalsResample"
QT_MOC_LITERAL(7, 92, 20), // "SignalsRegisterPoint"
QT_MOC_LITERAL(8, 113, 16), // "SignalsTransFrom"
QT_MOC_LITERAL(9, 130, 15), // "SignalsSavePath"
QT_MOC_LITERAL(10, 146, 20) // "on_load_path_clicked"

    },
    "CSlamLadirDialog\0SignalsLoadPath\0\0"
    "QList<QVector3D>\0_vec\0SignalsTestLoadPath\0"
    "SignalsResample\0SignalsRegisterPoint\0"
    "SignalsTransFrom\0SignalsSavePath\0"
    "on_load_path_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSlamLadirDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       5,    1,   52,    2, 0x06 /* Public */,
       6,    0,   55,    2, 0x06 /* Public */,
       7,    0,   56,    2, 0x06 /* Public */,
       8,    0,   57,    2, 0x06 /* Public */,
       9,    0,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void CSlamLadirDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CSlamLadirDialog *_t = static_cast<CSlamLadirDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SignalsLoadPath((*reinterpret_cast< QList<QVector3D>(*)>(_a[1]))); break;
        case 1: _t->SignalsTestLoadPath((*reinterpret_cast< QList<QVector3D>(*)>(_a[1]))); break;
        case 2: _t->SignalsResample(); break;
        case 3: _t->SignalsRegisterPoint(); break;
        case 4: _t->SignalsTransFrom(); break;
        case 5: _t->SignalsSavePath(); break;
        case 6: _t->on_load_path_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QVector3D> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QVector3D> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CSlamLadirDialog::*_t)(QList<QVector3D> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSlamLadirDialog::SignalsLoadPath)) {
                *result = 0;
            }
        }
        {
            typedef void (CSlamLadirDialog::*_t)(QList<QVector3D> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSlamLadirDialog::SignalsTestLoadPath)) {
                *result = 1;
            }
        }
        {
            typedef void (CSlamLadirDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSlamLadirDialog::SignalsResample)) {
                *result = 2;
            }
        }
        {
            typedef void (CSlamLadirDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSlamLadirDialog::SignalsRegisterPoint)) {
                *result = 3;
            }
        }
        {
            typedef void (CSlamLadirDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSlamLadirDialog::SignalsTransFrom)) {
                *result = 4;
            }
        }
        {
            typedef void (CSlamLadirDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSlamLadirDialog::SignalsSavePath)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject CSlamLadirDialog::staticMetaObject = {
    { &ccOverlayDialog::staticMetaObject, qt_meta_stringdata_CSlamLadirDialog.data,
      qt_meta_data_CSlamLadirDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CSlamLadirDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSlamLadirDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CSlamLadirDialog.stringdata0))
        return static_cast<void*>(const_cast< CSlamLadirDialog*>(this));
    return ccOverlayDialog::qt_metacast(_clname);
}

int CSlamLadirDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ccOverlayDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void CSlamLadirDialog::SignalsLoadPath(QList<QVector3D> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CSlamLadirDialog::SignalsTestLoadPath(QList<QVector3D> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CSlamLadirDialog::SignalsResample()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void CSlamLadirDialog::SignalsRegisterPoint()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void CSlamLadirDialog::SignalsTransFrom()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void CSlamLadirDialog::SignalsSavePath()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
