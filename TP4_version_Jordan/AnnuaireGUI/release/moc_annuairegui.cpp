/****************************************************************************
** Meta object code from reading C++ file 'annuairegui.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../annuairegui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'annuairegui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AnnuaireGUI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      33,   12,   12,   12, 0x08,
      55,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AnnuaireGUI[] = {
    "AnnuaireGUI\0\0dialogAjoutJoueur()\0"
    "dialogAjoutAnnuaire()\0dialogAjoutEntraineur()\0"
};

void AnnuaireGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AnnuaireGUI *_t = static_cast<AnnuaireGUI *>(_o);
        switch (_id) {
        case 0: _t->dialogAjoutJoueur(); break;
        case 1: _t->dialogAjoutAnnuaire(); break;
        case 2: _t->dialogAjoutEntraineur(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData AnnuaireGUI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AnnuaireGUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AnnuaireGUI,
      qt_meta_data_AnnuaireGUI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AnnuaireGUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AnnuaireGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AnnuaireGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AnnuaireGUI))
        return static_cast<void*>(const_cast< AnnuaireGUI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AnnuaireGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
