#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Application.h"
#include "MainTable.h"

MainWindow::MainWindow(QString sPath, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("uTag");

    picture = new QPixmap("/Users/mmasniy/Desktop/utag/app/res/Different-types-of-instore-music-1024x1024");
    int h = ui->pictureLabel->height();
    int w = ui->pictureLabel->width();

    ui->pictureLabel->setPixmap(picture->scaled(w, h, Qt::KeepAspectRatio));

    dirmodel = new QFileSystemModel(this);
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirmodel->setRootPath(sPath);

    ui->treeView->setModel(dirmodel);
    if (checkDirPermitions(sPath))
        ui->treeView->setRootIndex(dirmodel->index(sPath));
    ui->textBrowser->insertPlainText(QTime::currentTime().toString() + " : start program Utag\n");

    for(int i = 1; i < dirmodel->columnCount(); ++i) {
        ui->treeView->hideColumn(i);
    }
    ui->tableWidget->setTable(sPath);
    ui->tableWidget->resizeColumnsToContents();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_treeView_clicked(const QModelIndex &index) {
    QString sPath = dirmodel->fileInfo(index).absoluteFilePath();
    ui->tableWidget->clearTable();
    ui->tableWidget->setTable(sPath);
    ui->tableWidget->resizeColumnsToContents();
    ui->textBrowser->insertPlainText(QTime::currentTime().toString() + " : folder changed to " + sPath + "\n");
}

void MainWindow::on_changeDir_clicked() {
    QString sPath = ui->plainTextEdit->toPlainText();
    if(checkDirPermitions(sPath)) {
        if (!sPath.toStdString().empty()) {
            ui->tableWidget->clearTable();
            ui->tableWidget->setTable(sPath);
            ui->tableWidget->resizeColumnsToContents();
            ui->treeView->setModel(dirmodel);
            ui->treeView->setRootIndex(dirmodel->index(sPath));
            ui->textBrowser->insertPlainText(
                QTime::currentTime().toString() + " : folder changed to " + sPath
                    + "\n");
        }
    }
}

bool MainWindow::checkDirPermitions(QString &sPath) {
    QDir dir(sPath);
    if (!dir.exists()) {
        QMessageBox::warning(this, "Folder", "Folder doesn`t exist!\nInput valid folder name!");
        return false;
    }
    if (!dir.isReadable()) {
        QMessageBox::warning(this, "Folder", "Folder isn`t readble\nInput valid folder name!");
        return false;
    }
    return true;
}

void saveTagsInFile(MainTable *main_table, TagLib::FileRef& file, int i) {
    size_t year = 0, track = 0;
    file.tag()->setTitle(main_table->item(i, 1)->text().toStdString());
    file.tag()->setArtist(main_table->item(i, 2)->text().toStdString());
    file.tag()->setAlbum(main_table->item(i, 3)->text().toStdString());
    track = (main_table->item(i, 4)->text().toUInt());
    file.tag()->setTrack(track);
    file.tag()->setGenre(main_table->item(i, 5)->text().toStdString());
    year = (main_table->item(i, 6)->text().toUInt());
    file.tag()->setYear(year);
    file.save();
}

void MainWindow::on_saveChages_clicked() {
    MainTable *main_table = ui->tableWidget;
    qDebug() << "Сохранение данных!";
    for (int i = 0; i < main_table->rowCount(); ++i) {
        QFileInfo fileInfo(main_table->item(i, 7)->text());
        if (fileInfo.exists() && fileInfo.isReadable() && fileInfo.isWritable()) {
            TagLib::FileRef file(main_table->item(i, 7)->text().toStdString().c_str());
            if (!file.isNull() && file.tag()) {
                saveTagsInFile(main_table, file, i);
            } else {
                ui->textBrowser->insertPlainText("File not valid " + main_table->item(i, 7)->text() + "\n");
                QMessageBox::warning(this, "Warning", "Нет доступа к файлу: " + main_table->item(i, 0)->text());
            }
        } else {
            ui->textBrowser->insertPlainText("Permissions denie :> " + main_table->item(i, 7)->text() + "\n");
            QMessageBox::warning(this, "Warning", "Нет доступа к файлу: " + main_table->item(i, 0)->text());
        }
    }
    ui->textBrowser->insertPlainText("File/s have been changed!\n");
}

void MainWindow::on_pushButton_5_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "/home",
            tr("Image Files (*.png *.jpg *.bmp)"));
}

void MainWindow::on_tableWidget_cellClicked(int row, int column) {
    //сдесь сделать подгрузку фото альбома!!!
}

void MainWindow::on_actionHelp_triggered() {
    QMessageBox::about(this, "uTag", "This project to work with audio-file tags and metadata!\n"
                       "You can use this app to view and edit audio-file tags, album images and lyrics.");
}
