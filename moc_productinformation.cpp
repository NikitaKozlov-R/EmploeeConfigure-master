/****************************************************************************
** Meta object code from reading C++ file 'productinformation.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../productinformation.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'productinformation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProductInformationWidget_t {
    const uint offsetsAndSize[28];
    char stringdata0[274];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ProductInformationWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ProductInformationWidget_t qt_meta_stringdata_ProductInformationWidget = {
    {
QT_MOC_LITERAL(0, 24), // "ProductInformationWidget"
QT_MOC_LITERAL(25, 11), // "nameChanged"
QT_MOC_LITERAL(37, 0), // ""
QT_MOC_LITERAL(38, 13), // "weightChanged"
QT_MOC_LITERAL(52, 11), // "costChanged"
QT_MOC_LITERAL(64, 12), // "countChanged"
QT_MOC_LITERAL(77, 17), // "supplierIdChanged"
QT_MOC_LITERAL(95, 18), // "stockpileIdChanged"
QT_MOC_LITERAL(114, 23), // "nameLineEditDataChanged"
QT_MOC_LITERAL(138, 25), // "weightLineEditDataChanged"
QT_MOC_LITERAL(164, 23), // "costLineEditDataChanged"
QT_MOC_LITERAL(188, 24), // "countLineEditDataChanged"
QT_MOC_LITERAL(213, 29), // "supplierIdLineEditDataChanged"
QT_MOC_LITERAL(243, 30) // "stockpileIdLineEditDataChanged"

    },
    "ProductInformationWidget\0nameChanged\0"
    "\0weightChanged\0costChanged\0countChanged\0"
    "supplierIdChanged\0stockpileIdChanged\0"
    "nameLineEditDataChanged\0"
    "weightLineEditDataChanged\0"
    "costLineEditDataChanged\0"
    "countLineEditDataChanged\0"
    "supplierIdLineEditDataChanged\0"
    "stockpileIdLineEditDataChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProductInformationWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   86,    2, 0x06,    1 /* Public */,
       3,    2,   91,    2, 0x06,    4 /* Public */,
       4,    2,   96,    2, 0x06,    7 /* Public */,
       5,    2,  101,    2, 0x06,   10 /* Public */,
       6,    2,  106,    2, 0x06,   13 /* Public */,
       7,    2,  111,    2, 0x06,   16 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,  116,    2, 0x0a,   19 /* Public */,
       9,    0,  117,    2, 0x0a,   20 /* Public */,
      10,    0,  118,    2, 0x0a,   21 /* Public */,
      11,    0,  119,    2, 0x0a,   22 /* Public */,
      12,    0,  120,    2, 0x0a,   23 /* Public */,
      13,    0,  121,    2, 0x0a,   24 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ProductInformationWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProductInformationWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->nameChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->weightChanged((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->costChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->countChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->supplierIdChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->stockpileIdChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->nameLineEditDataChanged(); break;
        case 7: _t->weightLineEditDataChanged(); break;
        case 8: _t->costLineEditDataChanged(); break;
        case 9: _t->countLineEditDataChanged(); break;
        case 10: _t->supplierIdLineEditDataChanged(); break;
        case 11: _t->stockpileIdLineEditDataChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ProductInformationWidget::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProductInformationWidget::nameChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ProductInformationWidget::*)(double , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProductInformationWidget::weightChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ProductInformationWidget::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProductInformationWidget::costChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ProductInformationWidget::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProductInformationWidget::countChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ProductInformationWidget::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProductInformationWidget::supplierIdChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ProductInformationWidget::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProductInformationWidget::stockpileIdChanged)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject ProductInformationWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ProductInformationWidget.offsetsAndSize,
    qt_meta_data_ProductInformationWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ProductInformationWidget_t
, QtPrivate::TypeAndForceComplete<ProductInformationWidget, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ProductInformationWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProductInformationWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProductInformationWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ProductInformationWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ProductInformationWidget::nameChanged(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ProductInformationWidget::weightChanged(double _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ProductInformationWidget::costChanged(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ProductInformationWidget::countChanged(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ProductInformationWidget::supplierIdChanged(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ProductInformationWidget::stockpileIdChanged(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
