#ifndef ITEMSMODEL_H
#define ITEMSMODEL_H

#include <QAbstractListModel>
#include <vector>
#include <sceneentitytype.h>

class SceneEntity;
class QGraphicsScene;

class ItemsModel : public QAbstractListModel
{
    Q_OBJECT

public:
    ItemsModel(QObject *parent = nullptr, QGraphicsScene *graphicsScene = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void removeEntity(int row);
    void addEntity(SceneEntityType type);

public slots:
    void updateList();

private:
    std::vector<SceneEntity *> _sceneEntities;
    int _nextId;
    QGraphicsScene *_graphicsScene;
};

#endif // ITEMSMODEL_H
