/****************************************************************************
** Meta object code from reading C++ file 'ColorChangeTool.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../qCC/slam/ColorChangeTool.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ColorChangeTool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ColorChangeTool_t {
    QByteArrayData data[14];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ColorChangeTool_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ColorChangeTool_t qt_meta_stringdata_ColorChangeTool = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ColorChangeTool"
QT_MOC_LITERAL(1, 16, 7), // "onClone"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 21), // "redSliderValueChanged"
QT_MOC_LITERAL(4, 47, 1), // "r"
QT_MOC_LITERAL(5, 49, 23), // "greenSliderValueChanged"
QT_MOC_LITERAL(6, 73, 1), // "g"
QT_MOC_LITERAL(7, 75, 22), // "blueSliderValueChanged"
QT_MOC_LITERAL(8, 98, 1), // "b"
QT_MOC_LITERAL(9, 100, 22), // "redSpinboxValueChanged"
QT_MOC_LITERAL(10, 123, 24), // "greenSpinboxValueChanged"
QT_MOC_LITERAL(11, 148, 23), // "blueSpinboxValueChanged"
QT_MOC_LITERAL(12, 172, 16), // "GetSelectedCloud"
QT_MOC_LITERAL(13, 189, 7) // "onClear"

    },
    "ColorChangeTool\0onClone\0\0redSliderValueChanged\0"
    "r\0greenSliderValueChanged\0g\0"
    "blueSliderValueChanged\0b\0"
    "redSpinboxValueChanged\0greenSpinboxValueChanged\0"
    "blueSpinboxValueChanged\0GetSelectedCloud\0"
    "onClear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ColorChangeTool[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    1,   60,    2, 0x0a /* Public */,
       5,    1,   63,    2, 0x0a /* Public */,
       7,    1,   66,    2, 0x0a /* Public */,
       9,    1,   69,    2, 0x0a /* Public */,
      10,    1,   72,    2, 0x0a /* Public */,
      11,    1,   75,    2, 0x0a /* Public */,
      12,    0,   78,    2, 0x0a /* Public */,
      13,    0,   79,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ColorChangeTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ColorChangeTool *_t = static_cast<ColorChangeTool *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onClone(); break;
        case 1: _t->redSliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->greenSliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->blueSliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->redSpinboxValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->greenSpinboxValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->blueSpinboxValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->GetSelectedCloud(); break;
        case 8: _t->onClear(); break;
        default: ;
        }
    }
}

const QMetaObject ColorChangeTool::staticMetaObject = {
    { &ccOverlayDialog::staticMetaObject, qt_meta_stringdata_ColorChangeTool.data,
      qt_meta_data_ColorChangeTool,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ColorChangeTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ColorChangeTool::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ColorChangeTool.stringdata0))
        return static_cast<void*>(const_cast< ColorChangeTool*>(this));
    return ccOverlayDialog::qt_metacast(_clname);
}

int ColorChangeTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ccOverlayDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
