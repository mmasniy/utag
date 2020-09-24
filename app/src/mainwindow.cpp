#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Application.h"
#include "MainTable.h"

MainWindow::MainWindow(QString sPath, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("utag");

    dirmodel = new QFileSystemModel(this);
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirmodel->setRootPath(sPath);

    ui->treeView->setModel(dirmodel);
    ui->treeView->setRootIndex(dirmodel->index(sPath));
    ui->textBrowser->insertPlainText(QTime::currentTime().toString() + " : start program Utag\n");
//    ui->textBrowser_2->setPlainText("Choose directory!");

    for(int i = 1; i < dirmodel->columnCount(); ++i) {
        ui->treeView->hideColumn(i);
    }
    ui->tableWidget->setTable(dirmodel->index(sPath), sPath);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_treeView_clicked(const QModelIndex &index) {
    QString sPath = dirmodel->fileInfo(index).absoluteFilePath();
    ui->tableWidget->clearTable();
    ui->textBrowser->insertPlainText(QTime::currentTime().toString() + " : table cleared\n");
    ui->tableWidget->setTable(index, sPath);
    ui->textBrowser->insertPlainText(QTime::currentTime().toString() + " : folder changed to " + sPath + "\n");
//    ui->textBrowser_2->setPlainText(sPath);
//    auto list = ui->tableWidget->selectedItems();
//    for (auto& i : list) {
//        std::cout << i << std::endl;
//    }
}

void MainWindow::on_pushButton_2_clicked() {
    QString sPath = ui->plainTextEdit->toPlainText();
    if (!sPath.toStdString().empty()) {
        ui->tableWidget->clearTable();
        ui->tableWidget->setTable(dirmodel->index(sPath), sPath);
        ui->treeView->setModel(dirmodel);
        ui->treeView->setRootIndex(dirmodel->index(sPath));
        ui->textBrowser->insertPlainText(
            QTime::currentTime().toString() + " : folder changed to " + sPath
                + "\n");
    }
}



void MainWindow::checkDirPermitions(QString &sPath) {
    QDir dir(sPath);
//    if ()
}















//    dir = new QDir(sPath);
//    dir->setFilter(QDir::NoDotAndDotDot | QDir::Files);
//    dir->setNameFilters(QStringList() << "*.mp3" << "*.flac" << "*.waw" << "*.ogg" << "*.aif");
//
//    QStringList list = dir->entryList();
//    for (auto& i : list) {
//        std::cout << i.toStdString() << std::endl;
//    }

//
//    filemodel = new QFileSystemModel(this);
//    filemodel->setRootPath(sPath);
//    filemodel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
//    filemodel->setNameFilters(QStringList() << "*.mp3" << "*.flac" << "*.waw" << "*.ogg" << "*.aif");
//    filemodel->setNameFilterDisables(false);



//    ui->tableView->setRootIndex(filemodel->index(sPath));
//    ui->tableView->setEditTriggers((QAbstractItemView::editTriggers()));
//    ui->tableView->editTriggers();
//    ui->tableWidget->UpdateTable();


