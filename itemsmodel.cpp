#include "itemsmodel.h"

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include "sceneentity.h"

ItemsModel::ItemsModel(QObject *parent, QGraphicsScene *graphicsScene)
    : QAbstractListModel(parent),
      _nextId(0),
      _graphicsScene(graphicsScene)
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
    if (_sceneEntities.empty())
        return;

    if (_sceneEntities[row]->type() == SceneEntityType::QRADIOBUTTON) {
        _graphicsScene->removeItem(_sceneEntities[row]->widgetParent());

        /*QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget();
        proxy = proxy->createProxyForChildWidget(_sceneEntities[row]->widget());

        _graphicsScene->removeItem(proxy);

        delete proxy;*/
    } else {
        _graphicsScene->removeItem(_sceneEntities[row]->item());
    }

    //delete _sceneEntities[row]; // TODO: Check if i need this one
    _sceneEntities.erase(_sceneEntities.begin() + row);

    // Refresh ListModel
    QModelIndex start = index(row, 0);
    QModelIndex end = index(static_cast<int>(_sceneEntities.size()), 0);

    emit dataChanged(start, end);
}

void ItemsModel::addEntity(SceneEntityType type)
{
    auto scEntity = new SceneEntity(nullptr, type, _nextId, this);
    _sceneEntities.push_back(scEntity);

    if (type == SceneEntityType::QRADIOBUTTON) {
        _graphicsScene->addItem(scEntity->widgetParent());
    } else {
        _graphicsScene->addItem(scEntity->item());
    }

    qDebug() << _nextId;

    _nextId++;

    // Refresh ListModel
    QModelIndex start = index(static_cast<int>(_sceneEntities.size()-1), 0);
    QModelIndex end = index(static_cast<int>(_sceneEntities.size()), 0);

    emit dataChanged(start, end);
}

void ItemsModel::updateList()
{
    qDebug() << "here";
    QModelIndex start = index(0, 0);
    QModelIndex end = index(static_cast<int>(_sceneEntities.size()), 0);

    emit dataChanged(start, end);
}
