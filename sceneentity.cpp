#include "sceneentity.h"

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QRadioButton>
#include <QDebug>
#include <QGraphicsProxyWidget>
#include <QGraphicsWidget>

#include "tesseractobject.h"

SceneEntity::SceneEntity(QObject *parent, SceneEntityType type, int id)
    : QObject(parent),
      _type(type),
      _id(id)
{
    switch (type) {
    case SceneEntityType::TESSERACT:
        qDebug() << "TESSERACT looks at you.";

        _item = new TesseractObject();
        _typeString = "2D Tesseract imp.";

        _item->setFlag(QGraphicsItem::ItemIsMovable);

        break;
    case SceneEntityType::QRADIOBUTTON:
    {
        qDebug() << "QRADIOBUTTON goes hhhZZZZZZ...";

        _widgetParent = new QGraphicsRectItem(0,0,20,20);
        _widgetProxy = new QGraphicsProxyWidget(_widgetParent);
        _widget = new QRadioButton();

        _widgetParent->setFlag(QGraphicsItem::ItemIsMovable);

        _widgetProxy->setWidget(_widget);
        _widgetProxy->setFlag(QGraphicsItem::ItemIsMovable);

        _typeString = "QRadioButton (untoggled)";

        _widget->setProperty("title", static_cast<QVariant>(_typeString));

        break;
    }
    case SceneEntityType::HIPPO:
    {
        qDebug() << "Another HIPPO!";

        _image = new QPixmap("/Users/erhoof/Developer/Qt/u_t5-qt-4/hippo.jpg");

        _item = new QGraphicsPixmapItem(*_image);
        _item->setScale(0.3); // to make img smaller
        _item->setPos(10,10);

        _item->setFlag(QGraphicsItem::ItemIsMovable);

        _typeString = "HIPPO (〃⌒∇⌒)";

        break;
    }
    default:
        qDebug() << "No obj created";
    }
}

SceneEntity::~SceneEntity()
{
    if (_type == SceneEntityType::QRADIOBUTTON)
        delete _widget;
    else
        delete _item;

    if (_type == SceneEntityType::HIPPO)
        delete _image;

    delete this;
}

SceneEntityType SceneEntity::type() const
{
    return _type;
}

QGraphicsItem *SceneEntity::item()
{
    return _item;
}

QWidget *SceneEntity::widget()
{
    return _widget;
}

int SceneEntity::id() const
{
    return _id;
}

QGraphicsProxyWidget *SceneEntity::widgetProxy()
{
    return _widgetProxy;
}

QGraphicsRectItem *SceneEntity::widgetParent()
{
    return _widgetParent;
}

QString SceneEntity::toString() const
{
    if (_type == SceneEntityType::QRADIOBUTTON)
        return QString("[%1] %2 (x:%3, y:%4)").arg(QString::number(_id),
                                                   _typeString,
                                                   QString::number(_widget->pos().x()),
                                                   QString::number(_widget->pos().y()));
    else
        return QString("[%1] %2 (x:%3, y:%4)").arg(QString::number(_id),
                                                   _typeString,
                                                   QString::number(_item->pos().x()),
                                                   QString::number(_item->pos().y()));
}

