#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->plainTextEdit->setReadOnly(true);
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("../data/Temp.db");
//    db =QSqlDatabase::database();
//    db.open();
//        QSqlQueryModel *model = new QSqlQueryModel(this);
//        model->setQuery("select * from time", db);
//        model->setHeaderData(0, Qt::Horizontal, tr("Студенческий билет"));
//        model->setHeaderData(1, Qt::Horizontal, tr("Имя"));
//        model->setHeaderData(2, Qt::Horizontal, tr("курс"));
//        ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{

    delete ui;

}


void MainWindow::on_pushButton_clicked()
{
    ui->plainTextEdit->clear();
    QString dbname =ui->label->text();
    QString sqlname = ui->label_2->text();
    if(dbname.contains(".db") & sqlname.contains("SQLIGHT")){

    QString line;
    QString zapr="";
    if (!db.open()){
        ui->plainTextEdit->appendPlainText(db.lastError().databaseText());
//        qDebug()<<db.lastError().databaseText();
        return;
    }
    else{
        QFile inputFile(qApp->applicationDirPath()+"/../temp/TempSQLIGHT.sql");
        if(inputFile.open(QIODevice::ReadOnly| QIODevice::Text)){
        QString data;
       data = inputFile.readAll();
       data = data.simplified();
       QStringList list1 = data.split("; ");
        for (int i = 0; i < list1.size(); i ++ ){
            QString qstr =QString (list1.at(i))+";";
            qDebug()<<qstr;
            qstr = qstr.trimmed();
            ui->plainTextEdit->appendPlainText(qstr);
            ui->plainTextEdit->appendPlainText("");
            QSqlQuery query(qstr);
            if(!query.exec()){

                ui->plainTextEdit->appendPlainText(query.lastError().databaseText()+"  "+QString::number(i)+" Строка выполнения");
                ui->plainTextEdit->appendPlainText("");
               qDebug()<< query.lastError().databaseText()<<i;
            }
//            qDebug()<<query.lastQuery()<< "Последний запрос";
//            qDebug()<<query.executedQuery()<< "Последний успешный запрос";
        }

        }
    }

    }
//     if(dbname.contains(".db") & sqlname.contains("SQLPOSGRES.sql")){}
}

void MainWindow::on_pushButton_2_clicked()
{
    if(!QDir(qApp->applicationDirPath()+"/../temp").exists()){
        QDir().mkdir(qApp->applicationDirPath()+"/../temp");
    }
    db.close();
        QString str = QFileDialog::getOpenFileName(this, "Open file»", "..", "File Base (*.db)");
        QFile file (str);
         QFileInfo fi(file.fileName());
        if(file.fileName().contains(".db")){
            QFile file_1 (qApp->applicationDirPath()+"/../temp/TempSQLIGHT.db");
            file_1.remove();
            file.copy(qApp->applicationDirPath()+"/../temp/TempSQLIGHT.db");
     ui->label->setText("Выбрана база "+fi.fileName());
     ui->comboBox->clear();
//     ui->tableView;
     db = QSqlDatabase::addDatabase("QSQLITE");
     db.setDatabaseName(qApp->applicationDirPath()+"/../temp/TempSQLIGHT.db");

 db =QSqlDatabase::database();
 db.open();
// for (int i = 0; i < db.tables().size(); i ++ ){
ui->comboBox->addItems(db.tables());

//  QListView *model = db.tables();//new QListView(this);
//  ui->listView->setModel()

        }
        else{
//          QMessageBox::information (this, "Оповещение", "Не выбрана база");
        //}
        }


}

void MainWindow::on_pushButton_3_clicked()
{
    if(!QDir(qApp->applicationDirPath()+"/../temp").exists()){
        QDir().mkdir(qApp->applicationDirPath()+"../temp");
    }
        QString str = QFileDialog::getOpenFileName(this, "Open file»", "..", "File Base (*.sql)");
        QFile file (str);
        QFileInfo fi(file.fileName());
        if(file.fileName().contains("SQLIGHT")){
           QFile file_1 (qApp->applicationDirPath()+"/../temp/TempSQLIGHT.sql");
           file_1.remove();
         file.copy(qApp->applicationDirPath()+"/../temp/TempSQLIGHT.sql");
     ui->label_2->setText("Выбран скрипт "+fi.fileName());
        }
        else{
//           QMessageBox::information (this, "Оповещение", "Не выбран скрипт");
        }
}

void MainWindow::on_pushButton_4_clicked()
{

    QString connection;
    connection = db.connectionName();
//    if (db.commit())
    db.close();
//     db.setDatabaseName("");
    //qDebug()<<db.isOpen();
    db.removeDatabase(connection);
    QDir dir(qApp->applicationDirPath()+"/../temp/");
   qDebug()<< dir.removeRecursively();
    ui->label->setText("");
    ui->label_2->setText("");
    ui->plainTextEdit->clear();
    ui->comboBox->clear();
}

void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{

}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("select * from "+ui->comboBox->currentText(), db);
//            model->setHeaderData(0, Qt::Horizontal, tr("Студенческий билет"));
//            model->setHeaderData(1, Qt::Horizontal, tr("Имя"));
//            model->setHeaderData(2, Qt::Horizontal, tr("курс"));
    ui->tableView->setModel(model);
}
