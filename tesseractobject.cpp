#include "tesseractobject.h"

#include <QPen>
#include <QPainter>

TesseractObject::TesseractObject(QObject *parent) : QObject(parent)
{
    this->setPos(10, 10);
}

QRectF TesseractObject::boundingRect() const
{
    int thisX = this->pos().x();
    int thisY = this->pos().y();
    return QRectF(0, 0, thisX+100, thisY+100);
}

void TesseractObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;

    pen.setWidth(2);
    pen.setColor(Qt::blue);

    painter->setPen(pen);

    int thisX = 0;
    int thisY = 0;

    //BIG: Back Square
    painter->drawLine(QPoint(thisX+20,  thisY),    QPoint(thisX+100, thisY)); // ----u
    painter->drawLine(QPoint(thisX+20,  thisY),    QPoint(thisX+20,  thisY+80)); // |l
    painter->drawLine(QPoint(thisX+20,  thisY+80), QPoint(thisX+100, thisY+80)); // ----d
    painter->drawLine(QPoint(thisX+100, thisY),    QPoint(thisX+100, thisY+80)); // |r

    //BIG: Front Square
    painter->drawLine(QPoint(thisX,    thisY+20),    QPoint(thisX+80, thisY+20)); // ----u
    painter->drawLine(QPoint(thisX,    thisY+20),    QPoint(thisX,    thisY+100)); // |l
    painter->drawLine(QPoint(thisX,    thisY+100),   QPoint(thisX+80, thisY+100)); // ----d
    painter->drawLine(QPoint(thisX+80, thisY+20),    QPoint(thisX+80, thisY+100)); // |r

    //BIG:: Sides
    painter->drawLine(QPoint(thisX+20,  thisY),    QPoint(thisX,    thisY+20)); // LU
    painter->drawLine(QPoint(thisX+20,  thisY+80), QPoint(thisX,    thisY+100)); // LD
    painter->drawLine(QPoint(thisX+100, thisY),    QPoint(thisX+80, thisY+20)); // RU
    painter->drawLine(QPoint(thisX+100, thisY+80), QPoint(thisX+80, thisY+100)); // RD

    //SMALL:: Back Square
    painter->drawLine(QPoint(thisX+20 + 30,  thisY + 30),    QPoint(thisX+100 - 30, thisY + 30)); // ----u
    painter->drawLine(QPoint(thisX+20 + 30,  thisY + 30),    QPoint(thisX+20 + 30,  thisY+80 - 30)); // |l
    painter->drawLine(QPoint(thisX+20 + 30,  thisY + 50),    QPoint(thisX+100 - 30, thisY + 50)); // ----u
    painter->drawLine(QPoint(thisX+20 + 50,  thisY + 30),    QPoint(thisX+20 + 50,  thisY+80 - 30)); // |l

    //SMALL: Front Square
    painter->drawLine(QPoint(thisX + 30,      thisY+20  + 30),    QPoint(thisX+80 - 30, thisY+20 + 30)); // ----u
    painter->drawLine(QPoint(thisX + 30,      thisY+20  + 30),    QPoint(thisX + 30,    thisY+100 - 30)); // |l
    painter->drawLine(QPoint(thisX + 30,      thisY + 50 + 20),   QPoint(thisX+80 - 30, thisY + 50 + 20)); // ----d
    painter->drawLine(QPoint(thisX + 30 + 20, thisY+20  + 30),    QPoint(thisX+30 + 20, thisY+100 - 30)); // |r

    //SMALL: Sides
    painter->drawLine(QPoint(thisX+20 + 30,  thisY + 30),    QPoint(thisX + 30,      thisY+20  + 30)); // LU
    painter->drawLine(QPoint(thisX+20 + 30,  thisY + 50),    QPoint(thisX + 30,      thisY+20  + 50)); // LD
    painter->drawLine(QPoint(thisX+50 + 20,  thisY + 30),    QPoint(thisX + 50,      thisY+20  + 30)); // RU
    painter->drawLine(QPoint(thisX+50 + 20,  thisY + 50),    QPoint(thisX + 50,      thisY+20  + 50)); // RU

    //Connecting two rects
    painter->drawLine(QPoint(thisX+20,  thisY),    QPoint(thisX+20 + 30,  thisY + 30)); // LUB - Left Up Back
    painter->drawLine(QPoint(thisX,  thisY+20),    QPoint(thisX + 30,      thisY+20  + 30)); // LUF - Left Up Front
    painter->drawLine(QPoint(thisX+20 + 30,  thisY + 50),    QPoint(thisX,    thisY+100)); // LDB / LFB - the same line. (thx perspective)
    painter->drawLine(QPoint(thisX+100 - 30, thisY + 30),    QPoint(thisX+80, thisY+20)); // RUB / RUF - the same line.
    painter->drawLine(QPoint(thisX+100 - 30, thisY + 50),    QPoint(thisX+100, thisY+80)); // RDB
    painter->drawLine(QPoint(thisX+80 - 30, thisY + 50 + 20),    QPoint(thisX+80, thisY+100)); // RDF
}
