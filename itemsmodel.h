#ifndef ITEMSMODEL_H
#define ITEMSMODEL_H

#include <QAbstractListModel>
#include <vector>
#include <sceneentitytype.h>

class SceneEntity;

class ItemsModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ItemsModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void removeEntity(int row);
    void addEntity(SceneEntityType type);

signals:
    void addEntity(SceneEntity &entity);
    void removeEntity(SceneEntity &entity);


private:
    std::vector<SceneEntity *> _sceneEntities;
    int _nextId;
};

#endif // ITEMSMODEL_H
