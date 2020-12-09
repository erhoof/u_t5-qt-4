#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QGraphicsScene;
class ItemsModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_tesseract_clicked();

    void on_pushButton_qRadioButton_clicked();

    void on_pushButton_hippo_clicked();

    void on_pushButton_removeSelected_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *_graphicsScene;
    ItemsModel *_itemsModel;

};
#endif // MAINWINDOW_H
