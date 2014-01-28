/****************************************************************************
** Meta object code from reading C++ file 'runedgecfd.h'
**
** Created: Tue 27. Aug 18:46:25 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../runedgecfd.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'runedgecfd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_runEdgeCFD[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,   11,   11,   11, 0x0a,
      41,   11,   11,   11, 0x0a,
      52,   11,   11,   11, 0x0a,
      63,   11,   11,   11, 0x0a,
      81,   11,   11,   11, 0x0a,
     103,   11,   11,   11, 0x0a,
     120,   11,   11,   11, 0x0a,
     139,   11,   11,   11, 0x0a,
     154,   11,   11,   11, 0x0a,
     172,   11,   11,   11, 0x0a,
     194,   11,   11,   11, 0x0a,
     220,   11,   11,   11, 0x0a,
     249,  240,   11,   11, 0x0a,
     275,   11,   11,   11, 0x0a,
     301,   11,   11,   11, 0x0a,
     325,   11,   11,   11, 0x0a,
     343,   11,   11,   11, 0x0a,
     364,   11,   11,   11, 0x0a,
     386,   11,   11,   11, 0x0a,
     421,  409,   11,   11, 0x0a,
     453,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_runEdgeCFD[] = {
    "runEdgeCFD\0\0mouseClickEvent()\0slotOpen()\0"
    "slotSave()\0slotExit()\0slotConfigAnsys()\0"
    "slotChangeDirectory()\0slotMakeButton()\0"
    "slotSelectDBFile()\0slotNewSetup()\0"
    "slotDeleteSetup()\0slotRunEdgeCFDSetup()\0"
    "slotEscreveArquivoSetup()\0slotRunEdgeCFDPRE()\0"
    "FileName\0setNameFileInput(QString)\0"
    "slotEscreveArquivoInput()\0"
    "slotEscreveArquivoFSI()\0slotNewMaterial()\0"
    "slotDeleteMaterial()\0slotEscreveMaterial()\0"
    "slotRunEdgeCFDSolver()\0VersaoAtual\0"
    "slotAtualizaLabelAnsys(QString)\0"
    "slotSetWireframeMode(bool)\0"
};

void runEdgeCFD::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        runEdgeCFD *_t = static_cast<runEdgeCFD *>(_o);
        switch (_id) {
        case 0: _t->mouseClickEvent(); break;
        case 1: _t->slotOpen(); break;
        case 2: _t->slotSave(); break;
        case 3: _t->slotExit(); break;
        case 4: _t->slotConfigAnsys(); break;
        case 5: _t->slotChangeDirectory(); break;
        case 6: _t->slotMakeButton(); break;
        case 7: _t->slotSelectDBFile(); break;
        case 8: _t->slotNewSetup(); break;
        case 9: _t->slotDeleteSetup(); break;
        case 10: _t->slotRunEdgeCFDSetup(); break;
        case 11: _t->slotEscreveArquivoSetup(); break;
        case 12: _t->slotRunEdgeCFDPRE(); break;
        case 13: _t->setNameFileInput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->slotEscreveArquivoInput(); break;
        case 15: _t->slotEscreveArquivoFSI(); break;
        case 16: _t->slotNewMaterial(); break;
        case 17: _t->slotDeleteMaterial(); break;
        case 18: _t->slotEscreveMaterial(); break;
        case 19: _t->slotRunEdgeCFDSolver(); break;
        case 20: _t->slotAtualizaLabelAnsys((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: _t->slotSetWireframeMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData runEdgeCFD::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject runEdgeCFD::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_runEdgeCFD,
      qt_meta_data_runEdgeCFD, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &runEdgeCFD::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *runEdgeCFD::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *runEdgeCFD::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_runEdgeCFD))
        return static_cast<void*>(const_cast< runEdgeCFD*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int runEdgeCFD::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void runEdgeCFD::mouseClickEvent()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
