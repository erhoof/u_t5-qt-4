#ifndef SCENEENTITY_H
#define SCENEENTITY_H

#include <QObject>
#include "sceneentitytype.h"

// Placeholder
class QGraphicsItem;

class SceneEntity : public QObject
{
    Q_OBJECT
public:
    SceneEntity(QObject *parent = nullptr, SceneEntityType type = SceneEntityType::NONE, int id = 0);
    ~SceneEntity();

    SceneEntityType type() const;
    QGraphicsItem &item();

    int id() const;
    QString toString() const;

signals:

private:
    SceneEntityType _type;
    QString _typeString;
    QGraphicsItem *_item;
    union _addInUnion {
        QWidget *_widget;
        QImage *_image;
    } _addIn;

    int _id;
};

#endif // SCENEENTITY_H
