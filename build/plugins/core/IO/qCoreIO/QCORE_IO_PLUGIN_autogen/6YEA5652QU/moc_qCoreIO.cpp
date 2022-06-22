/****************************************************************************
** Meta object code from reading C++ file 'qCoreIO.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../plugins/core/IO/qCoreIO/include/qCoreIO.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qCoreIO.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_qCoreIO_t {
    QByteArrayData data[1];
    char stringdata0[8];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qCoreIO_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qCoreIO_t qt_meta_stringdata_qCoreIO = {
    {
QT_MOC_LITERAL(0, 0, 7) // "qCoreIO"

    },
    "qCoreIO"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qCoreIO[] = {

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

void qCoreIO::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject qCoreIO::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_qCoreIO.data,
      qt_meta_data_qCoreIO,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *qCoreIO::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qCoreIO::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_qCoreIO.stringdata0))
        return static_cast<void*>(const_cast< qCoreIO*>(this));
    if (!strcmp(_clname, "ccIOPluginInterface"))
        return static_cast< ccIOPluginInterface*>(const_cast< qCoreIO*>(this));
    if (!strcmp(_clname, "cccorp.cloudcompare.ccPluginInterface/3.2"))
        return static_cast< ccPluginInterface*>(const_cast< qCoreIO*>(this));
    if (!strcmp(_clname, "cccorp.cloudcompare.ccIOPluginInterface/1.3"))
        return static_cast< ccIOPluginInterface*>(const_cast< qCoreIO*>(this));
    return QObject::qt_metacast(_clname);
}

int qCoreIO::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}

QT_PLUGIN_METADATA_SECTION const uint qt_section_alignment_dummy = 42;

#ifdef QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    'q',  'b',  'j',  's',  0x01, 0x00, 0x00, 0x00,
    '0',  0x01, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    0x1c, 0x01, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    '"',  0x00, 'c',  'c',  'c',  'o',  'r',  'p', 
    '.',  'c',  'l',  'o',  'u',  'd',  'c',  'o', 
    'm',  'p',  'a',  'r',  'e',  '.',  'p',  'l', 
    'u',  'g',  'i',  'n',  '.',  'q',  'C',  'o', 
    'r',  'e',  'I',  'O',  0x9b, 0x09, 0x00, 0x00,
    0x09, 0x00, 'c',  'l',  'a',  's',  's',  'N', 
    'a',  'm',  'e',  0x00, 0x07, 0x00, 'q',  'C', 
    'o',  'r',  'e',  'I',  'O',  0x00, 0x00, 0x00,
    ':',  0xa0, 0xa0, 0x00, 0x07, 0x00, 'v',  'e', 
    'r',  's',  'i',  'o',  'n',  0x00, 0x00, 0x00,
    0x11, 0x00, 0x00, 0x00, 0x05, 0x00, 'd',  'e', 
    'b',  'u',  'g',  0x00, 0x95, 0x10, 0x00, 0x00,
    0x08, 0x00, 'M',  'e',  't',  'a',  'D',  'a', 
    't',  'a',  0x00, 0x00, 0x98, 0x00, 0x00, 0x00,
    0x09, 0x00, 0x00, 0x00, 0x88, 0x00, 0x00, 0x00,
    0x1b, 0x03, 0x00, 0x00, 0x04, 0x00, 't',  'y', 
    'p',  'e',  0x00, 0x00, 0x03, 0x00, 'I',  '/', 
    'O',  0x00, 0x00, 0x00, '1',  0x00, 0x00, 0x00,
    0x04, 0x00, 'c',  'o',  'r',  'e',  0x00, 0x00,
    0x1b, 0x07, 0x00, 0x00, 0x04, 0x00, 'n',  'a', 
    'm',  'e',  0x00, 0x00, 0x08, 0x00, 'C',  'o', 
    'r',  'e',  ' ',  'I',  '/',  'O',  0x00, 0x00,
    0x1b, 0x0b, 0x00, 0x00, 0x0b, 0x00, 'd',  'e', 
    's',  'c',  'r',  'i',  'p',  't',  'i',  'o', 
    'n',  0x00, 0x00, 0x00, '.',  0x00, 'A',  'l', 
    'l',  'o',  'w',  's',  ' ',  'r',  'e',  'a', 
    'd',  'i',  'n',  'g',  ' ',  '&',  ' ',  'w', 
    'r',  'i',  't',  'i',  'n',  'g',  ' ',  'o', 
    'f',  ' ',  'm',  'a',  'n',  'y',  ' ',  'f', 
    'i',  'l',  'e',  ' ',  'f',  'o',  'r',  'm', 
    'a',  't',  's',  '.',  ' ',  0x00, 0x00, 0x00,
    'D',  0x00, 0x00, 0x00, ',',  0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    't',  0x00, 0x00, 0x00, '<',  0x00, 0x00, 0x00,
    'h',  0x00, 0x00, 0x00, 'X',  0x00, 0x00, 0x00
};

#else // QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    'q',  'b',  'j',  's',  0x01, 0x00, 0x00, 0x00,
    '0',  0x01, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    0x1c, 0x01, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    '"',  0x00, 'c',  'c',  'c',  'o',  'r',  'p', 
    '.',  'c',  'l',  'o',  'u',  'd',  'c',  'o', 
    'm',  'p',  'a',  'r',  'e',  '.',  'p',  'l', 
    'u',  'g',  'i',  'n',  '.',  'q',  'C',  'o', 
    'r',  'e',  'I',  'O',  0x95, 0x09, 0x00, 0x00,
    0x08, 0x00, 'M',  'e',  't',  'a',  'D',  'a', 
    't',  'a',  0x00, 0x00, 0x98, 0x00, 0x00, 0x00,
    0x09, 0x00, 0x00, 0x00, 0x88, 0x00, 0x00, 0x00,
    0x1b, 0x03, 0x00, 0x00, 0x04, 0x00, 't',  'y', 
    'p',  'e',  0x00, 0x00, 0x03, 0x00, 'I',  '/', 
    'O',  0x00, 0x00, 0x00, '1',  0x00, 0x00, 0x00,
    0x04, 0x00, 'c',  'o',  'r',  'e',  0x00, 0x00,
    0x1b, 0x07, 0x00, 0x00, 0x04, 0x00, 'n',  'a', 
    'm',  'e',  0x00, 0x00, 0x08, 0x00, 'C',  'o', 
    'r',  'e',  ' ',  'I',  '/',  'O',  0x00, 0x00,
    0x1b, 0x0b, 0x00, 0x00, 0x0b, 0x00, 'd',  'e', 
    's',  'c',  'r',  'i',  'p',  't',  'i',  'o', 
    'n',  0x00, 0x00, 0x00, '.',  0x00, 'A',  'l', 
    'l',  'o',  'w',  's',  ' ',  'r',  'e',  'a', 
    'd',  'i',  'n',  'g',  ' ',  '&',  ' ',  'w', 
    'r',  'i',  't',  'i',  'n',  'g',  ' ',  'o', 
    'f',  ' ',  'm',  'a',  'n',  'y',  ' ',  'f', 
    'i',  'l',  'e',  ' ',  'f',  'o',  'r',  'm', 
    'a',  't',  's',  '.',  ' ',  0x00, 0x00, 0x00,
    'D',  0x00, 0x00, 0x00, ',',  0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x9b, 0x1e, 0x00, 0x00,
    0x09, 0x00, 'c',  'l',  'a',  's',  's',  'N', 
    'a',  'm',  'e',  0x00, 0x07, 0x00, 'q',  'C', 
    'o',  'r',  'e',  'I',  'O',  0x00, 0x00, 0x00,
    '1',  0x00, 0x00, 0x00, 0x05, 0x00, 'd',  'e', 
    'b',  'u',  'g',  0x00, ':',  0xa0, 0xa0, 0x00,
    0x07, 0x00, 'v',  'e',  'r',  's',  'i',  'o', 
    'n',  0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    '<',  0x00, 0x00, 0x00, 0xe4, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x00, 0x00, 0x0c, 0x01, 0x00, 0x00
};
#endif // QT_NO_DEBUG

QT_MOC_EXPORT_PLUGIN(qCoreIO, qCoreIO)

QT_END_MOC_NAMESPACE
