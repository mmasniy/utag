#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "FileTag.h"

MainWindow::MainWindow(QString sPath, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    dirmodel = new QFileSystemModel(this);
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirmodel->setRootPath(sPath);

    ui->treeView->setModel(dirmodel);
    ui->treeView->setRootIndex(dirmodel->index(sPath));


    for(int i = 1; i < dirmodel->columnCount(); ++i) {
        ui->treeView->hideColumn(i);
    }

    filemodel = new QFileSystemModel(this);
    filemodel->setRootPath(sPath);
    filemodel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    filemodel->setNameFilters(QStringList() << "*.mp3" << "*.flac" << "*.waw" << "*.ogg" << "*.aif");
    filemodel->setNameFilterDisables(false);

//    ui->tableView->setModel(filemodel);
//    ui->tableView->setRootIndex(filemodel->index(sPath));
//    ui->tableView->setEditTriggers((QAbstractItemView::editTriggers()));
//    ui->tableView->editTriggers();
//    ui->tableWidget->UpdateTable();
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_treeView_clicked(const QModelIndex &index) {
    QString sPath = dirmodel->fileInfo(index).absoluteFilePath();
//    ui->tableView->setRootIndex(filemodel->setRootPath(sPath));
}

void MainWindow::on_listView_clicked(const QModelIndex &index) {
//    std::string path = filemodel->fileInfo(index).absoluteFilePath().toStdString();
//    FileTags file(path);

}
