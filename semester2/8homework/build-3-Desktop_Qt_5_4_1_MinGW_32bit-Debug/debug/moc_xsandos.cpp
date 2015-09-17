/****************************************************************************
** Meta object code from reading C++ file 'xsandos.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../3/xsandos.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xsandos.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GameTest_t {
    QByteArrayData data[5];
    char stringdata[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameTest_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameTest_t qt_meta_stringdata_GameTest = {
    {
QT_MOC_LITERAL(0, 0, 8), // "GameTest"
QT_MOC_LITERAL(1, 9, 11), // "winningTest"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 14), // "notWinningTest"
QT_MOC_LITERAL(4, 37, 10) // "noLineTest"

    },
    "GameTest\0winningTest\0\0notWinningTest\0"
    "noLineTest"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameTest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GameTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameTest *_t = static_cast<GameTest *>(_o);
        switch (_id) {
        case 0: _t->winningTest(); break;
        case 1: _t->notWinningTest(); break;
        case 2: _t->noLineTest(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject GameTest::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GameTest.data,
      qt_meta_data_GameTest,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GameTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameTest::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GameTest.stringdata))
        return static_cast<void*>(const_cast< GameTest*>(this));
    return QObject::qt_metacast(_clname);
}

int GameTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_MyButton_t {
    QByteArrayData data[5];
    char stringdata[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyButton_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyButton_t qt_meta_stringdata_MyButton = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MyButton"
QT_MOC_LITERAL(1, 9, 16), // "clickedCorrectly"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "changeSymbol"
QT_MOC_LITERAL(4, 40, 8) // "nextTurn"

    },
    "MyButton\0clickedCorrectly\0\0changeSymbol\0"
    "nextTurn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   30,    2, 0x0a /* Public */,
       4,    0,   31,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyButton *_t = static_cast<MyButton *>(_o);
        switch (_id) {
        case 0: _t->clickedCorrectly(); break;
        case 1: _t->changeSymbol(); break;
        case 2: _t->nextTurn(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyButton::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyButton::clickedCorrectly)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MyButton::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MyButton.data,
      qt_meta_data_MyButton,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyButton::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyButton.stringdata))
        return static_cast<void*>(const_cast< MyButton*>(this));
    return QObject::qt_metacast(_clname);
}

int MyButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void MyButton::clickedCorrectly()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_XsAndOs_t {
    QByteArrayData data[4];
    char stringdata[31];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XsAndOs_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XsAndOs_t qt_meta_stringdata_XsAndOs = {
    {
QT_MOC_LITERAL(0, 0, 7), // "XsAndOs"
QT_MOC_LITERAL(1, 8, 15), // "changeWhoseTurn"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5) // "check"

    },
    "XsAndOs\0changeWhoseTurn\0\0check"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XsAndOs[] = {

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
       1,    0,   24,    2, 0x0a /* Public */,
       3,    0,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void XsAndOs::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        XsAndOs *_t = static_cast<XsAndOs *>(_o);
        switch (_id) {
        case 0: _t->changeWhoseTurn(); break;
        case 1: _t->check(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject XsAndOs::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_XsAndOs.data,
      qt_meta_data_XsAndOs,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *XsAndOs::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XsAndOs::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_XsAndOs.stringdata))
        return static_cast<void*>(const_cast< XsAndOs*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int XsAndOs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
