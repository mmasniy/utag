#include "Dialog.h"
////#include "ui_dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new(MainWindow)) {
    ui->setupUi(this);
    QString sPath = "/";
    dirmodel = new QFileSystemModel(this);
    dirmodel->setRootPath(sPath);
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);

    ui->treeView->setModel(dirmodel);
    for (int i = 1; i < dirmodel->columnCount(); ++i)
        ui->treeView->hideColumn(i);

    filemodel = new QFileSystemModel(this);
    filemodel->setRootPath(sPath);
    filemodel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    filemodel->setNameFilters(QStringList() << "*.mp3" << "*.flac" << "*.waw" << "*.ogg"); // "^(?:.*\/)?((.+)(\.mp3|\.flac|\.waw|\.ogg))$"
    filemodel->setNameFilterDisables(false);
    ui->listView->setModel(filemodel);

}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_treeView_clicked(const QModelIndex &index) {
    QString sPath = dirmodel->fileInfo(index).absoluteFilePath();
    ui->listView->setRootIndex(filemodel->setRootPath(sPath));
}

void MainWindow::on_listView_clicked(const QModelIndex &index) {
    std::string filePath = filemodel->fileInfo(index).absoluteFilePath().toStdString();
    FileInfo file(filePath);
    ui->lineEdit_1->setText(QString::fromStdString(file.getArtist()));
    ui->lineEdit_2->setText(QString::fromStdString(file.getTitle()));
    ui->lineEdit_3->setText(QString::fromStdString(file.getAlbum()));
    ui->lineEdit_4->setText(QString::fromStdString(file.getGenre()));
    ui->lineEdit_5->setText(QString::fromStdString(file.getFilePath()));
}
