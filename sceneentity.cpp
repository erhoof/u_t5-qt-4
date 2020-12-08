#include "sceneentity.h"

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QRadioButton>
#include <QDebug>

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

        break;
    case SceneEntityType::QRADIOBUTTON:
        qDebug() << "QRADIOBUTTON goes hhhZZZZZ...";

        _addIn._widget = new QRadioButton();

        break;
    case SceneEntityType::HIPPO:
        qDebug() << "Another HIPPO!";

        _addIn._image = new QImage("./hippo.png");
        _item = new QGraphicsPixmapItem(_addIn._image);
        _item->setScale(0.3); // to make img smaller

        break;
    default:
        qDebug() << "No obj created";
    }
}

SceneEntity::~SceneEntity()
{
    delete _item;
    delete _addIn._image; // whatever...
    delete this;
}

SceneEntityType SceneEntity::type() const
{
    return _type;
}

QGraphicsItem &SceneEntity::item()
{
    return *_item;
}

int SceneEntity::id() const
{
    return _id;
}