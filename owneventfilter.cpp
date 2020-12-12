#include "owneventfilter.h"

#include <QEvent>
#include <QMouseEvent>
#include <QRadioButton>

#include <QDebug>

OwnEventFilter::OwnEventFilter(QObject *parent) : QObject(parent) {}

bool OwnEventFilter::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonRelease) {

        qDebug() << "MouseButtonRelease";

        // LMB
        if (static_cast<QMouseEvent *>(event)->button() == Qt::LeftButton) {
            qDebug() << "LeftMouseButton";
            qDebug() << obj->metaObject()->className();

            //if (obj->metaObject()->className() == "QRadioButton") {
                qDebug() << "RadioButton event";

                // It is QRadioButton
                auto widget = static_cast<QRadioButton *>(obj);
                qDebug() << widget->isChecked();

                if (widget->isChecked()) {
                    qDebug() << "Set false";
                    widget->setChecked(false);
                    widget->setAccessibleName("QRadioButton (untoggled)");
                } else {
                    widget->setChecked(true);
                    widget->setAccessibleName("QRadioButton (toggled)");
                }

                emit updateList();

                return true;
            //}
        }
    }

    return false;
}
