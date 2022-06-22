/****************************************************************************
** Meta object code from reading C++ file 'ccGraphicalTransformationTool.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../qCC/ccGraphicalTransformationTool.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ccGraphicalTransformationTool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ccGraphicalTransformationTool_t {
    QByteArrayData data[3];
    char stringdata0[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ccGraphicalTransformationTool_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ccGraphicalTransformationTool_t qt_meta_stringdata_ccGraphicalTransformationTool = {
    {
QT_MOC_LITERAL(0, 0, 29), // "ccGraphicalTransformationTool"
QT_MOC_LITERAL(1, 30, 21), // "SignalTransfromFinish"
QT_MOC_LITERAL(2, 52, 0) // ""

    },
    "ccGraphicalTransformationTool\0"
    "SignalTransfromFinish\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ccGraphicalTransformationTool[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void ccGraphicalTransformationTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ccGraphicalTransformationTool *_t = static_cast<ccGraphicalTransformationTool *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SignalTransfromFinish(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ccGraphicalTransformationTool::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ccGraphicalTransformationTool::SignalTransfromFinish)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ccGraphicalTransformationTool::staticMetaObject = {
    { &ccOverlayDialog::staticMetaObject, qt_meta_stringdata_ccGraphicalTransformationTool.data,
      qt_meta_data_ccGraphicalTransformationTool,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ccGraphicalTransformationTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ccGraphicalTransformationTool::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ccGraphicalTransformationTool.stringdata0))
        return static_cast<void*>(const_cast< ccGraphicalTransformationTool*>(this));
    if (!strcmp(_clname, "Ui::GraphicalTransformationDlg"))
        return static_cast< Ui::GraphicalTransformationDlg*>(const_cast< ccGraphicalTransformationTool*>(this));
    return ccOverlayDialog::qt_metacast(_clname);
}

int ccGraphicalTransformationTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ccOverlayDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ccGraphicalTransformationTool::SignalTransfromFinish()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
