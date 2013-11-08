/****************************************************************************
** Meta object code from reading C++ file 'ibutton.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ibutton.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ibutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Ibutton[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      20,    8,    8,    8, 0x05,
      32,    8,    8,    8, 0x05,
      42,    8,    8,    8, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_Ibutton[] = {
    "Ibutton\0\0iclicked()\0ireleased()\0"
    "ienterd()\0iexited()\0"
};

void Ibutton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Ibutton *_t = static_cast<Ibutton *>(_o);
        switch (_id) {
        case 0: _t->iclicked(); break;
        case 1: _t->ireleased(); break;
        case 2: _t->ienterd(); break;
        case 3: _t->iexited(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Ibutton::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Ibutton::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_Ibutton,
      qt_meta_data_Ibutton, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Ibutton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Ibutton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Ibutton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ibutton))
        return static_cast<void*>(const_cast< Ibutton*>(this));
    return QLabel::qt_metacast(_clname);
}

int Ibutton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Ibutton::iclicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Ibutton::ireleased()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Ibutton::ienterd()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Ibutton::iexited()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
