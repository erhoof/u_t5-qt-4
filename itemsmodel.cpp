#include "itemsmodel.h"

#include <QDebug>
#include "sceneentity.h"

ItemsModel::ItemsModel(QObject *parent)
    : QAbstractListModel(parent),
      _nextId(0)
{
}

int ItemsModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return _sceneEntities.size();
}

QVariant ItemsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole)
        return _sceneEntities[index.row()]->toString();

    return QVariant();
}

void ItemsModel::removeEntity(int row)
{
    delete _sceneEntities[row-1]; // TODO: Check if i need this one
    _sceneEntities.erase(_sceneEntities.begin() + row);

    // Refresh ListModel
    QModelIndex start = index(row, 0);
    QModelIndex end = index(static_cast<int>(_sceneEntities.size()), 0);

    emit dataChanged(start, end);
}

void ItemsModel::addEntity(SceneEntityType type)
{
    auto scEntity = new SceneEntity(nullptr, type, _nextId);
    _sceneEntities.push_back(scEntity);

    qDebug() << _nextId;

    _nextId++;

    // Refresh ListModel
    QModelIndex start = index(static_cast<int>(_sceneEntities.size()-1), 0);
    QModelIndex end = index(static_cast<int>(_sceneEntities.size()), 0);

    emit dataChanged(start, end);
}
