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

void MainWindow::on_changeDir_clicked() {
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


void MainWindow::on_saveChages_clicked() {
    MainTable *main_table = ui->tableWidget;


    for (int i = 0; i < main_table->rowCount(); ++i) {

    }
}

//void MainWindow::on_ApplyButton_clicked()
//{
//    DropTableWidget *table = ui->tableWidget;
//    Tagger tagger;

//    for (int i = 0; i < table->rowCount(); ++i) {
//        int year = table->item(i, 4)->text().toInt();
//        if (year < 0)
//            year = 0;
//        tagger.UpdateTagsInFile({
//            table->item(i, 0)->text(),
//            table->item(i, 1)->text(),
//            table->item(i, 2)->text(),
//            table->item(i, 3)->text(),
//            static_cast<unsigned int>(year),
//            table->item(i, 5)->text()
//        });
//    }
//    ui->textEdit->WriteToLog("Changes was applied to files!");
//    ui->statusbar->showMessage("Changes was applied to files!");
//}










