#ifndef SCENEENTITY_H
#define SCENEENTITY_H

#include <QObject>

enum class SceneEntityType
{
    TESSERACT,
    QRADIOBUTTON,
    HIPPO,
    NONE
};

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

signals:

private:
    SceneEntityType _type;
    QGraphicsItem *_item;
    union _addIn {
        QWidget *_widget;
        QImage *_image;
    };

    int _id;
};

#endif // SCENEENTITY_H
