/****************************************************************************
** Meta object code from reading C++ file 'runedgecfd.h'
**
** Created: Fri 24. Jan 00:21:16 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../runedgecfd.h"
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
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      34,   30,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      54,   11,   11,   11, 0x0a,
      65,   11,   11,   11, 0x0a,
      76,   11,   11,   11, 0x0a,
      87,   11,   11,   11, 0x0a,
     105,   11,   11,   11, 0x0a,
     124,   11,   11,   11, 0x0a,
     146,   11,   11,   11, 0x0a,
     163,   11,   11,   11, 0x0a,
     182,   11,   11,   11, 0x0a,
     197,   11,   11,   11, 0x0a,
     215,   11,   11,   11, 0x0a,
     237,   11,   11,   11, 0x0a,
     263,   11,   11,   11, 0x0a,
     292,  283,   11,   11, 0x0a,
     318,   11,   11,   11, 0x0a,
     344,   11,   11,   11, 0x0a,
     368,   11,   11,   11, 0x0a,
     386,   11,   11,   11, 0x0a,
     407,   11,   11,   11, 0x0a,
     429,   11,   11,   11, 0x0a,
     464,  452,   11,   11, 0x0a,
     496,   11,   11,   11, 0x0a,
     528,  523,   11,   11, 0x0a,
     568,  523,   11,   11, 0x0a,
     604,   11,   11,   11, 0x0a,
     621,   11,   11,   11, 0x0a,
     645,   11,   11,   11, 0x0a,
     654,   11,   11,   11, 0x0a,
     680,   11,   11,   11, 0x0a,
     706,   11,  698,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_runEdgeCFD[] = {
    "runEdgeCFD\0\0mouseClickEvent()\0ver\0"
    "outlogtext(QString)\0slotOpen()\0"
    "slotSave()\0slotExit()\0slotConfigAnsys()\0"
    "slotConfigRender()\0slotChangeDirectory()\0"
    "slotMakeButton()\0slotSelectDBFile()\0"
    "slotNewSetup()\0slotDeleteSetup()\0"
    "slotRunEdgeCFDSetup()\0slotEscreveArquivoSetup()\0"
    "slotRunEdgeCFDPRE()\0FileName\0"
    "setNameFileInput(QString)\0"
    "slotEscreveArquivoInput()\0"
    "slotEscreveArquivoFSI()\0slotNewMaterial()\0"
    "slotDeleteMaterial()\0slotEscreveMaterial()\0"
    "slotRunEdgeCFDSolver()\0VersaoAtual\0"
    "slotAtualizaLabelAnsys(QString)\0"
    "slotSetWireframeMode(bool)\0item\0"
    "slotBlocksVisibility(QTableWidgetItem*)\0"
    "slotBlocksColors(QTableWidgetItem*)\0"
    "slotSSHConnect()\0slotClearWindowStatus()\0"
    "outlog()\0slotCopySimulationFiles()\0"
    "slotSavePBSFile()\0QString\0"
    "slotRARSimulationFiles()\0"
};

void runEdgeCFD::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        runEdgeCFD *_t = static_cast<runEdgeCFD *>(_o);
        switch (_id) {
        case 0: _t->mouseClickEvent(); break;
        case 1: _t->outlogtext((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->slotOpen(); break;
        case 3: _t->slotSave(); break;
        case 4: _t->slotExit(); break;
        case 5: _t->slotConfigAnsys(); break;
        case 6: _t->slotConfigRender(); break;
        case 7: _t->slotChangeDirectory(); break;
        case 8: _t->slotMakeButton(); break;
        case 9: _t->slotSelectDBFile(); break;
        case 10: _t->slotNewSetup(); break;
        case 11: _t->slotDeleteSetup(); break;
        case 12: _t->slotRunEdgeCFDSetup(); break;
        case 13: _t->slotEscreveArquivoSetup(); break;
        case 14: _t->slotRunEdgeCFDPRE(); break;
        case 15: _t->setNameFileInput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->slotEscreveArquivoInput(); break;
        case 17: _t->slotEscreveArquivoFSI(); break;
        case 18: _t->slotNewMaterial(); break;
        case 19: _t->slotDeleteMaterial(); break;
        case 20: _t->slotEscreveMaterial(); break;
        case 21: _t->slotRunEdgeCFDSolver(); break;
        case 22: _t->slotAtualizaLabelAnsys((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: _t->slotSetWireframeMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->slotBlocksVisibility((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 25: _t->slotBlocksColors((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 26: _t->slotSSHConnect(); break;
        case 27: _t->slotClearWindowStatus(); break;
        case 28: _t->outlog(); break;
        case 29: _t->slotCopySimulationFiles(); break;
        case 30: _t->slotSavePBSFile(); break;
        case 31: { QString _r = _t->slotRARSimulationFiles();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
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
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    }
    return _id;
}

// SIGNAL 0
void runEdgeCFD::mouseClickEvent()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void runEdgeCFD::outlogtext(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
