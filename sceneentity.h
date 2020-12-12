#ifndef SCENEENTITY_H
#define SCENEENTITY_H

#include <QObject>
#include "sceneentitytype.h"

// Placeholder
class QGraphicsItem;
class QGraphicsWidget;
class QGraphicsProxyWidget;
class QGraphicsRectItem;
class ItemsModel;

class SceneEntity : public QObject
{
    Q_OBJECT
public:
    SceneEntity(QObject *parent = nullptr, SceneEntityType type = SceneEntityType::NONE, int id = 0, ItemsModel *itemsModel = nullptr);
    ~SceneEntity();

    SceneEntityType type() const;
    QGraphicsItem *item();
    QWidget *widget();
    QGraphicsProxyWidget *widgetProxy();
    QGraphicsRectItem *widgetParent();

    int id() const;
    QString toString() const;

private:
    SceneEntityType _type;
    QString _typeString;
    QGraphicsItem *_item;
    QGraphicsProxyWidget *_widgetProxy;
    QGraphicsRectItem *_widgetParent;
    QWidget *_widget;
    QPixmap *_image;

    int _id;
};

#endif // SCENEENTITY_H
