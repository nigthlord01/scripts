#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlRecord>
#include "QTime"
#include "QDate"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QPen>
#include <QDebug>
#include <QFile>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QFileDialog>
#include "QTime"
#include "QDate"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QPen>
#include <QDebug>
#include <QFile>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QFileDialog>
#include <QSqlTableModel>
#include <QFileInfo>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_comboBox_currentIndexChanged(int index);

private:
    QSqlDatabase db ;
    QFile inputFile;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
