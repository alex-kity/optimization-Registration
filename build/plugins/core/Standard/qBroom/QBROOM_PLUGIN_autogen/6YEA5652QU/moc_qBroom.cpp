/****************************************************************************
** Meta object code from reading C++ file 'qBroom.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../plugins/core/Standard/qBroom/include/qBroom.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qBroom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_qBroom_t {
    QByteArrayData data[1];
    char stringdata0[7];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qBroom_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qBroom_t qt_meta_stringdata_qBroom = {
    {
QT_MOC_LITERAL(0, 0, 6) // "qBroom"

    },
    "qBroom"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qBroom[] = {

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

void qBroom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject qBroom::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_qBroom.data,
      qt_meta_data_qBroom,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *qBroom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qBroom::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_qBroom.stringdata0))
        return static_cast<void*>(const_cast< qBroom*>(this));
    if (!strcmp(_clname, "ccStdPluginInterface"))
        return static_cast< ccStdPluginInterface*>(const_cast< qBroom*>(this));
    if (!strcmp(_clname, "cccorp.cloudcompare.ccPluginInterface/3.2"))
        return static_cast< ccPluginInterface*>(const_cast< qBroom*>(this));
    if (!strcmp(_clname, "cccorp.cloudcompare.ccStdPluginInterface/1.5"))
        return static_cast< ccStdPluginInterface*>(const_cast< qBroom*>(this));
    return QObject::qt_metacast(_clname);
}

int qBroom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    0x14, 0x04, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    0x00, 0x04, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    '!',  0x00, 'c',  'c',  'c',  'o',  'r',  'p', 
    '.',  'c',  'l',  'o',  'u',  'd',  'c',  'o', 
    'm',  'p',  'a',  'r',  'e',  '.',  'p',  'l', 
    'u',  'g',  'i',  'n',  '.',  'q',  'B',  'r', 
    'o',  'o',  'm',  0x00, 0x9b, 0x09, 0x00, 0x00,
    0x09, 0x00, 'c',  'l',  'a',  's',  's',  'N', 
    'a',  'm',  'e',  0x00, 0x06, 0x00, 'q',  'B', 
    'r',  'o',  'o',  'm',  ':',  0xa0, 0xa0, 0x00,
    0x07, 0x00, 'v',  'e',  'r',  's',  'i',  'o', 
    'n',  0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00,
    0x05, 0x00, 'd',  'e',  'b',  'u',  'g',  0x00,
    0x15, 0x10, 0x00, 0x00, 0x08, 0x00, 'M',  'e', 
    't',  'a',  'D',  'a',  't',  'a',  0x00, 0x00,
    0x80, 0x03, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00,
    '`',  0x03, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x04, 0x00, 't',  'y',  'p',  'e',  0x00, 0x00,
    0x08, 0x00, 'S',  't',  'a',  'n',  'd',  'a', 
    'r',  'd',  0x00, 0x00, '1',  0x00, 0x00, 0x00,
    0x04, 0x00, 'c',  'o',  'r',  'e',  0x00, 0x00,
    0x9b, 0x07, 0x00, 0x00, 0x04, 0x00, 'n',  'a', 
    'm',  'e',  0x00, 0x00, 0x11, 0x00, 'C',  'E', 
    'A',  ' ',  'V',  'i',  'r',  't',  'u',  'a', 
    'l',  ' ',  'B',  'r',  'o',  'o',  'm',  0x00,
    0x9b, 0x0b, 0x00, 0x00, 0x04, 0x00, 'i',  'c', 
    'o',  'n',  0x00, 0x00, '$',  0x00, ':',  '/', 
    'C',  'C',  '/',  'p',  'l',  'u',  'g',  'i', 
    'n',  '/',  'q',  'B',  'r',  'o',  'o',  'm', 
    '/',  'i',  'm',  'a',  'g',  'e',  's',  '/', 
    'q',  'B',  'r',  'o',  'o',  'm',  '.',  'p', 
    'n',  'g',  0x00, 0x00, 0x1b, 0x13, 0x00, 0x00,
    0x0b, 0x00, 'd',  'e',  's',  'c',  'r',  'i', 
    'p',  't',  'i',  'o',  'n',  0x00, 0x00, 0x00,
    ')',  0x00, 'C',  'l',  'e',  'a',  'n',  ' ', 
    'a',  ' ',  'p',  'o',  'i',  'n',  't',  ' ', 
    'c',  'l',  'o',  'u',  'd',  ' ',  'w',  'i', 
    't',  'h',  ' ',  'a',  ' ',  'v',  'i',  'r', 
    't',  'u',  'a',  'l',  ' ',  'b',  'r',  'o', 
    'o',  'm',  '.',  0x00, 0x94, 0x1a, 0x00, 0x00,
    0x07, 0x00, 'a',  'u',  't',  'h',  'o',  'r', 
    's',  0x00, 0x00, 0x00, '`',  0x00, 0x00, 0x00,
    0x02, 0x00, 0x00, 0x00, '\\', 0x00, 0x00, 0x00,
    'P',  0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
    'L',  0x00, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x04, 0x00, 'n',  'a',  'm',  'e',  0x00, 0x00,
    '0',  0x00, 'W',  'e',  's',  'l',  'e',  'y', 
    ' ',  'G',  'r',  'i',  'm',  'e',  's',  ' ', 
    '(',  'C',  'o',  'l',  'l',  'i',  's',  'i', 
    'o',  'n',  ' ',  'E',  'n',  'g',  'i',  'n', 
    'e',  'e',  'r',  'i',  'n',  'g',  ' ',  'A', 
    's',  's',  'o',  'c',  'i',  'a',  't',  'e', 
    's',  ')',  0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    0x85, 0x01, 0x00, 0x00, 0x14, ')',  0x00, 0x00,
    0x0b, 0x00, 'm',  'a',  'i',  'n',  't',  'a', 
    'i',  'n',  'e',  'r',  's',  0x00, 0x00, 0x00,
    '`',  0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
    '\\', 0x00, 0x00, 0x00, 'P',  0x00, 0x00, 0x00,
    0x03, 0x00, 0x00, 0x00, 'L',  0x00, 0x00, 0x00,
    0x1b, 0x03, 0x00, 0x00, 0x04, 0x00, 'n',  'a', 
    'm',  'e',  0x00, 0x00, '0',  0x00, 'W',  'e', 
    's',  'l',  'e',  'y',  ' ',  'G',  'r',  'i', 
    'm',  'e',  's',  ' ',  '(',  'C',  'o',  'l', 
    'l',  'i',  's',  'i',  'o',  'n',  ' ',  'E', 
    'n',  'g',  'i',  'n',  'e',  'e',  'r',  'i', 
    'n',  'g',  ' ',  'A',  's',  's',  'o',  'c', 
    'i',  'a',  't',  'e',  's',  ')',  0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x85, 0x01, 0x00, 0x00,
    0x14, '7',  0x00, 0x00, 0x0a, 0x00, 'r',  'e', 
    'f',  'e',  'r',  'e',  'n',  'c',  'e',  's', 
    0xa8, 0x01, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
    0x9c, 0x01, 0x00, 0x00, 'h',  0x00, 0x00, 0x00,
    0x05, 0x00, 0x00, 0x00, '`',  0x00, 0x00, 0x00,
    0x1b, 0x03, 0x00, 0x00, 0x04, 0x00, 't',  'e', 
    'x',  't',  0x00, 0x00, ' ',  0x00, 'C',  'o', 
    'l',  'l',  'i',  's',  'i',  'o',  'n',  ' ', 
    'E',  'n',  'g',  'i',  'n',  'e',  'e',  'r', 
    'i',  'n',  'g',  ' ',  'A',  's',  's',  'o', 
    'c',  'i',  'a',  't',  'e',  's',  0x00, 0x00,
    0x1b, 0x09, 0x00, 0x00, 0x03, 0x00, 'u',  'r', 
    'l',  0x00, 0x00, 0x00, 0x13, 0x00, 'h',  't', 
    't',  'p',  's',  ':',  '/',  '/',  'c',  'e', 
    'a',  '-',  'a',  'z',  '.',  'c',  'o',  'm', 
    '/',  0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    '<',  0x00, 0x00, 0x00, 0x9c, 0x00, 0x00, 0x00,
    0x05, 0x00, 0x00, 0x00, 0x94, 0x00, 0x00, 0x00,
    0x1b, 0x03, 0x00, 0x00, 0x04, 0x00, 't',  'e', 
    'x',  't',  0x00, 0x00, 0x15, 0x00, 'C',  'o', 
    'n',  't',  'r',  'i',  'b',  'u',  't',  'e', 
    ' ',  'v',  'i',  'a',  ' ',  'P',  'a',  'y', 
    'P',  'a',  'l',  0x00, 0x9b, 0x07, 0x00, 0x00,
    0x03, 0x00, 'u',  'r',  'l',  0x00, 0x00, 0x00,
    'V',  0x00, 'h',  't',  't',  'p',  's',  ':', 
    '/',  '/',  'w',  'w',  'w',  '.',  'p',  'a', 
    'y',  'p',  'a',  'l',  '.',  'c',  'o',  'm', 
    '/',  'c',  'g',  'i',  '-',  'b',  'i',  'n', 
    '/',  'w',  'e',  'b',  's',  'c',  'r',  '?', 
    'c',  'm',  'd',  '=',  '_',  's',  '-',  'x', 
    'c',  'l',  'i',  'c',  'k',  '&',  'a',  'm', 
    'p',  ';',  'h',  'o',  's',  't',  'e',  'd', 
    '_',  'b',  'u',  't',  't',  'o',  'n',  '_', 
    'i',  'd',  '=',  'D',  'Z',  'A',  'Y',  'Q', 
    'V',  'L',  'L',  '8',  'M',  'M',  'N',  'L', 
    0x0c, 0x00, 0x00, 0x00, '0',  0x00, 0x00, 0x00,
    0x8c, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00,
    0x84, 0x00, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x04, 0x00, 't',  'e',  'x',  't',  0x00, 0x00,
    0x0d, 0x00, 'D',  'o',  'c',  'u',  'm',  'e', 
    'n',  't',  'a',  't',  'i',  'o',  'n',  0x00,
    0x9b, 0x06, 0x00, 0x00, 0x03, 0x00, 'u',  'r', 
    'l',  0x00, 0x00, 0x00, 'K',  0x00, 'h',  't', 
    't',  'p',  ':',  '/',  '/',  'w',  'w',  'w', 
    '.',  'c',  'l',  'o',  'u',  'd',  'c',  'o', 
    'm',  'p',  'a',  'r',  'e',  '.',  'o',  'r', 
    'g',  '/',  'd',  'o',  'c',  '/',  'w',  'i', 
    'k',  'i',  '/',  'i',  'n',  'd',  'e',  'x', 
    '.',  'p',  'h',  'p',  '?',  't',  'i',  't', 
    'l',  'e',  '=',  'V',  'i',  'r',  't',  'u', 
    'a',  'l',  '_',  'b',  'r',  'o',  'o',  'm', 
    '_',  '(',  'p',  'l',  'u',  'g',  'i',  'n', 
    ')',  0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    '(',  0x00, 0x00, 0x00, 0x85, 0x01, 0x00, 0x00,
    0x85, 0x0e, 0x00, 0x00, 0x05, '"',  0x00, 0x00,
    0xc4, 0x00, 0x00, 0x00, '$',  0x00, 0x00, 0x00,
    0x84, 0x00, 0x00, 0x00, 'P',  0x00, 0x00, 0x00,
    '4',  0x01, 0x00, 0x00, '0',  0x00, 0x00, 0x00,
    0xa8, 0x01, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 'p',  0x00, 0x00, 0x00,
    '<',  0x00, 0x00, 0x00, 'd',  0x00, 0x00, 0x00,
    'T',  0x00, 0x00, 0x00
};

#else // QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    'q',  'b',  'j',  's',  0x01, 0x00, 0x00, 0x00,
    0x14, 0x04, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    0x00, 0x04, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    '!',  0x00, 'c',  'c',  'c',  'o',  'r',  'p', 
    '.',  'c',  'l',  'o',  'u',  'd',  'c',  'o', 
    'm',  'p',  'a',  'r',  'e',  '.',  'p',  'l', 
    'u',  'g',  'i',  'n',  '.',  'q',  'B',  'r', 
    'o',  'o',  'm',  0x00, 0x95, 0x09, 0x00, 0x00,
    0x08, 0x00, 'M',  'e',  't',  'a',  'D',  'a', 
    't',  'a',  0x00, 0x00, 0x80, 0x03, 0x00, 0x00,
    0x11, 0x00, 0x00, 0x00, '`',  0x03, 0x00, 0x00,
    0x1b, 0x03, 0x00, 0x00, 0x04, 0x00, 't',  'y', 
    'p',  'e',  0x00, 0x00, 0x08, 0x00, 'S',  't', 
    'a',  'n',  'd',  'a',  'r',  'd',  0x00, 0x00,
    '1',  0x00, 0x00, 0x00, 0x04, 0x00, 'c',  'o', 
    'r',  'e',  0x00, 0x00, 0x9b, 0x07, 0x00, 0x00,
    0x04, 0x00, 'n',  'a',  'm',  'e',  0x00, 0x00,
    0x11, 0x00, 'C',  'E',  'A',  ' ',  'V',  'i', 
    'r',  't',  'u',  'a',  'l',  ' ',  'B',  'r', 
    'o',  'o',  'm',  0x00, 0x9b, 0x0b, 0x00, 0x00,
    0x04, 0x00, 'i',  'c',  'o',  'n',  0x00, 0x00,
    '$',  0x00, ':',  '/',  'C',  'C',  '/',  'p', 
    'l',  'u',  'g',  'i',  'n',  '/',  'q',  'B', 
    'r',  'o',  'o',  'm',  '/',  'i',  'm',  'a', 
    'g',  'e',  's',  '/',  'q',  'B',  'r',  'o', 
    'o',  'm',  '.',  'p',  'n',  'g',  0x00, 0x00,
    0x1b, 0x13, 0x00, 0x00, 0x0b, 0x00, 'd',  'e', 
    's',  'c',  'r',  'i',  'p',  't',  'i',  'o', 
    'n',  0x00, 0x00, 0x00, ')',  0x00, 'C',  'l', 
    'e',  'a',  'n',  ' ',  'a',  ' ',  'p',  'o', 
    'i',  'n',  't',  ' ',  'c',  'l',  'o',  'u', 
    'd',  ' ',  'w',  'i',  't',  'h',  ' ',  'a', 
    ' ',  'v',  'i',  'r',  't',  'u',  'a',  'l', 
    ' ',  'b',  'r',  'o',  'o',  'm',  '.',  0x00,
    0x94, 0x1a, 0x00, 0x00, 0x07, 0x00, 'a',  'u', 
    't',  'h',  'o',  'r',  's',  0x00, 0x00, 0x00,
    '`',  0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
    '\\', 0x00, 0x00, 0x00, 'P',  0x00, 0x00, 0x00,
    0x03, 0x00, 0x00, 0x00, 'L',  0x00, 0x00, 0x00,
    0x1b, 0x03, 0x00, 0x00, 0x04, 0x00, 'n',  'a', 
    'm',  'e',  0x00, 0x00, '0',  0x00, 'W',  'e', 
    's',  'l',  'e',  'y',  ' ',  'G',  'r',  'i', 
    'm',  'e',  's',  ' ',  '(',  'C',  'o',  'l', 
    'l',  'i',  's',  'i',  'o',  'n',  ' ',  'E', 
    'n',  'g',  'i',  'n',  'e',  'e',  'r',  'i', 
    'n',  'g',  ' ',  'A',  's',  's',  'o',  'c', 
    'i',  'a',  't',  'e',  's',  ')',  0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x85, 0x01, 0x00, 0x00,
    0x14, ')',  0x00, 0x00, 0x0b, 0x00, 'm',  'a', 
    'i',  'n',  't',  'a',  'i',  'n',  'e',  'r', 
    's',  0x00, 0x00, 0x00, '`',  0x00, 0x00, 0x00,
    0x02, 0x00, 0x00, 0x00, '\\', 0x00, 0x00, 0x00,
    'P',  0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
    'L',  0x00, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x04, 0x00, 'n',  'a',  'm',  'e',  0x00, 0x00,
    '0',  0x00, 'W',  'e',  's',  'l',  'e',  'y', 
    ' ',  'G',  'r',  'i',  'm',  'e',  's',  ' ', 
    '(',  'C',  'o',  'l',  'l',  'i',  's',  'i', 
    'o',  'n',  ' ',  'E',  'n',  'g',  'i',  'n', 
    'e',  'e',  'r',  'i',  'n',  'g',  ' ',  'A', 
    's',  's',  'o',  'c',  'i',  'a',  't',  'e', 
    's',  ')',  0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    0x85, 0x01, 0x00, 0x00, 0x14, '7',  0x00, 0x00,
    0x0a, 0x00, 'r',  'e',  'f',  'e',  'r',  'e', 
    'n',  'c',  'e',  's',  0xa8, 0x01, 0x00, 0x00,
    0x06, 0x00, 0x00, 0x00, 0x9c, 0x01, 0x00, 0x00,
    'h',  0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00,
    '`',  0x00, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x04, 0x00, 't',  'e',  'x',  't',  0x00, 0x00,
    ' ',  0x00, 'C',  'o',  'l',  'l',  'i',  's', 
    'i',  'o',  'n',  ' ',  'E',  'n',  'g',  'i', 
    'n',  'e',  'e',  'r',  'i',  'n',  'g',  ' ', 
    'A',  's',  's',  'o',  'c',  'i',  'a',  't', 
    'e',  's',  0x00, 0x00, 0x1b, 0x09, 0x00, 0x00,
    0x03, 0x00, 'u',  'r',  'l',  0x00, 0x00, 0x00,
    0x13, 0x00, 'h',  't',  't',  'p',  's',  ':', 
    '/',  '/',  'c',  'e',  'a',  '-',  'a',  'z', 
    '.',  'c',  'o',  'm',  '/',  0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, '<',  0x00, 0x00, 0x00,
    0x9c, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00,
    0x94, 0x00, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x04, 0x00, 't',  'e',  'x',  't',  0x00, 0x00,
    0x15, 0x00, 'C',  'o',  'n',  't',  'r',  'i', 
    'b',  'u',  't',  'e',  ' ',  'v',  'i',  'a', 
    ' ',  'P',  'a',  'y',  'P',  'a',  'l',  0x00,
    0x9b, 0x07, 0x00, 0x00, 0x03, 0x00, 'u',  'r', 
    'l',  0x00, 0x00, 0x00, 'V',  0x00, 'h',  't', 
    't',  'p',  's',  ':',  '/',  '/',  'w',  'w', 
    'w',  '.',  'p',  'a',  'y',  'p',  'a',  'l', 
    '.',  'c',  'o',  'm',  '/',  'c',  'g',  'i', 
    '-',  'b',  'i',  'n',  '/',  'w',  'e',  'b', 
    's',  'c',  'r',  '?',  'c',  'm',  'd',  '=', 
    '_',  's',  '-',  'x',  'c',  'l',  'i',  'c', 
    'k',  '&',  'a',  'm',  'p',  ';',  'h',  'o', 
    's',  't',  'e',  'd',  '_',  'b',  'u',  't', 
    't',  'o',  'n',  '_',  'i',  'd',  '=',  'D', 
    'Z',  'A',  'Y',  'Q',  'V',  'L',  'L',  '8', 
    'M',  'M',  'N',  'L',  0x0c, 0x00, 0x00, 0x00,
    '0',  0x00, 0x00, 0x00, 0x8c, 0x00, 0x00, 0x00,
    0x05, 0x00, 0x00, 0x00, 0x84, 0x00, 0x00, 0x00,
    0x1b, 0x03, 0x00, 0x00, 0x04, 0x00, 't',  'e', 
    'x',  't',  0x00, 0x00, 0x0d, 0x00, 'D',  'o', 
    'c',  'u',  'm',  'e',  'n',  't',  'a',  't', 
    'i',  'o',  'n',  0x00, 0x9b, 0x06, 0x00, 0x00,
    0x03, 0x00, 'u',  'r',  'l',  0x00, 0x00, 0x00,
    'K',  0x00, 'h',  't',  't',  'p',  ':',  '/', 
    '/',  'w',  'w',  'w',  '.',  'c',  'l',  'o', 
    'u',  'd',  'c',  'o',  'm',  'p',  'a',  'r', 
    'e',  '.',  'o',  'r',  'g',  '/',  'd',  'o', 
    'c',  '/',  'w',  'i',  'k',  'i',  '/',  'i', 
    'n',  'd',  'e',  'x',  '.',  'p',  'h',  'p', 
    '?',  't',  'i',  't',  'l',  'e',  '=',  'V', 
    'i',  'r',  't',  'u',  'a',  'l',  '_',  'b', 
    'r',  'o',  'o',  'm',  '_',  '(',  'p',  'l', 
    'u',  'g',  'i',  'n',  ')',  0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, '(',  0x00, 0x00, 0x00,
    0x85, 0x01, 0x00, 0x00, 0x85, 0x0e, 0x00, 0x00,
    0x05, '"',  0x00, 0x00, 0xc4, 0x00, 0x00, 0x00,
    '$',  0x00, 0x00, 0x00, 0x84, 0x00, 0x00, 0x00,
    'P',  0x00, 0x00, 0x00, '4',  0x01, 0x00, 0x00,
    '0',  0x00, 0x00, 0x00, 0xa8, 0x01, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x9b, '{',  0x00, 0x00,
    0x09, 0x00, 'c',  'l',  'a',  's',  's',  'N', 
    'a',  'm',  'e',  0x00, 0x06, 0x00, 'q',  'B', 
    'r',  'o',  'o',  'm',  '1',  0x00, 0x00, 0x00,
    0x05, 0x00, 'd',  'e',  'b',  'u',  'g',  0x00,
    ':',  0xa0, 0xa0, 0x00, 0x07, 0x00, 'v',  'e', 
    'r',  's',  'i',  'o',  'n',  0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, '<',  0x00, 0x00, 0x00,
    0xcc, 0x03, 0x00, 0x00, 0xe4, 0x03, 0x00, 0x00,
    0xf0, 0x03, 0x00, 0x00
};
#endif // QT_NO_DEBUG

QT_MOC_EXPORT_PLUGIN(qBroom, qBroom)

QT_END_MOC_NAMESPACE
