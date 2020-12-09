#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>
#include "itemsmodel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create Scene
    _graphicsScene = new QGraphicsScene();
    ui->graphicsView->setScene(_graphicsScene);

    _itemsModel = new ItemsModel();
    ui->listView->setModel(_itemsModel);
    ui->listView->show(); // TODO: check if i need this one
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_tesseract_clicked()
{
    _itemsModel->addEntity(SceneEntityType::TESSERACT);
}

void MainWindow::on_pushButton_qRadioButton_clicked()
{
    _itemsModel->addEntity(SceneEntityType::QRADIOBUTTON);
}

void MainWindow::on_pushButton_hippo_clicked()
{
    _itemsModel->addEntity(SceneEntityType::HIPPO);
}

void MainWindow::on_pushButton_removeSelected_clicked()
{
    _itemsModel->removeEntity(ui->listView->currentIndex().row());
}
