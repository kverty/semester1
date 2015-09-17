/****************************************************************************
** Meta object code from reading C++ file 'buttonTest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../classwork3/buttonTest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'buttonTest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ButtonTest_t {
    QByteArrayData data[4];
    char stringdata[42];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ButtonTest_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ButtonTest_t qt_meta_stringdata_ButtonTest = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ButtonTest"
QT_MOC_LITERAL(1, 11, 13), // "testFourTypes"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 15) // "testBinaryArray"

    },
    "ButtonTest\0testFourTypes\0\0testBinaryArray"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ButtonTest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x08 /* Private */,
       3,    0,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ButtonTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ButtonTest *_t = static_cast<ButtonTest *>(_o);
        switch (_id) {
        case 0: _t->testFourTypes(); break;
        case 1: _t->testBinaryArray(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ButtonTest::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ButtonTest.data,
      qt_meta_data_ButtonTest,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ButtonTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ButtonTest::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ButtonTest.stringdata))
        return static_cast<void*>(const_cast< ButtonTest*>(this));
    return QObject::qt_metacast(_clname);
}

int ButtonTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
