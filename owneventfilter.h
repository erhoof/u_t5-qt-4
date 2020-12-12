#ifndef OWNEVENTFILTER_H
#define OWNEVENTFILTER_H

#include <QObject>

class QEvent;

class OwnEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit OwnEventFilter(QObject *parent = nullptr);

protected:
    bool eventFilter(QObject *obj, QEvent *event);

signals:
    void updateList();

};

#endif // OWNEVENTFILTER_H
