#ifndef TESSERACTOBJECT_H
#define TESSERACTOBJECT_H

#include <QObject>
#include <QGraphicsItem>

class TesseractObject : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit TesseractObject(QObject *parent = nullptr);

signals:

protected:
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // TESSERACTOBJECT_H
