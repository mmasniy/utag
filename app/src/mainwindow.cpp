﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Application.h"
#include "MainTable.h"

MainWindow::MainWindow(QString sPath, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("uTag");

    setDefaultImage("/Users/mmasniy/Desktop/utag/app/res/fon");

    dirmodel = new QFileSystemModel(this);
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirmodel->setRootPath(sPath);

    ui->treeView->setModel(dirmodel);
    ui->textBrowser->insertPlainText(QTime::currentTime().toString() + " : start program Utag\n");

    for(int i = 1; i < dirmodel->columnCount(); ++i) {
        ui->treeView->hideColumn(i);
    }
    ui->tableWidget->setTable(sPath);
    ui->tableWidget->resizeColumnsToContents();
    if (checkDirPermitions(sPath))
        ui->treeView->setRootIndex(dirmodel->index(sPath));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_treeView_clicked(const QModelIndex &index) {
    setDefaultImage("/Users/mmasniy/Desktop/utag/app/res/fon");
    QString sPath = dirmodel->fileInfo(index).absoluteFilePath();
    if (checkDirPermitions(sPath)) {
        ui->tableWidget->clearTable();
        ui->tableWidget->setTable(sPath);
        ui->tableWidget->resizeColumnsToContents();
        ui->textBrowser->insertPlainText(QTime::currentTime().toString() + " : folder changed to " + sPath + "\n");
    }
}

void MainWindow::on_changeDir_clicked() {
    setDefaultImage("/Users/mmasniy/Desktop/utag/app/res/fon");
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

void MainWindow::saveTagsInFile(MainTable *main_table, TagLib::FileRef& file, int i) {
    size_t year = 0, track = 0;
    file.tag()->setTitle(main_table->item(i, 1)->text().toStdString());
    file.tag()->setArtist(main_table->item(i, 2)->text().toStdString());
    file.tag()->setAlbum(main_table->item(i, 3)->text().toStdString());
    track = (main_table->item(i, 4)->text().toUInt());
    if (track <= 100 && track > 0) {
        file.tag()->setTrack(track);
    } else {
         QMessageBox::about(this, "Track Number", "Track Number can`t be more 100 and less 1 or text");
    }
    file.tag()->setGenre(main_table->item(i, 5)->text().toStdString());
    year = (main_table->item(i, 6)->text().toUInt());
    QDate date = QDate::currentDate();
    if (static_cast<size_t>(date.year()) >= year) {
        file.tag()->setYear(year);
     } else {
        QMessageBox::about(this, "Year", "Year can`t be more current year or text");
    }
    file.save();
//    ui->textBrowser->insertPlainText(QTime::currentTime().toString() + " : Tags for file " +
//                                     main_table->item(i, 0)->text() + "saved\n");
}

void MainWindow::on_saveChages_clicked() {
    MainTable *main_table = ui->tableWidget;
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
    imgPath = QFileDialog::getOpenFileName(this, tr("Open Image"), "/home",
            tr("Image Files (*.png *.jpg *.bmp)"));
    ui->textBrowser->insertPlainText(QTime::currentTime().toString() + " : Image select! You can set her!\n");
}

void MainWindow::getImage(std::string path) {
    TagLib::MPEG::File file(path.c_str());
    TagLib::ID3v2::Tag *m_tag = file.ID3v2Tag(true);
    TagLib::ID3v2::FrameList frameList = m_tag->frameList("APIC");

    if(frameList.isEmpty()) {
        ui->pictureLabel->setPixmap(picture->scaled(ui->pictureLabel->width(), ui->pictureLabel->height(), Qt::KeepAspectRatio));
        return ;
    }
    TagLib::ID3v2::AttachedPictureFrame *coverImg =
        static_cast<TagLib::ID3v2::AttachedPictureFrame *>(frameList.front());

    QImage coverQImg;
    coverQImg.loadFromData((const uchar *)coverImg->picture().data(),
                            coverImg->picture().size());
    QPixmap pic = QPixmap::fromImage(coverQImg);
    ui->pictureLabel->setPixmap(pic.scaled(ui->pictureLabel->width(), ui->pictureLabel->height(), Qt::KeepAspectRatio));
}

void MainWindow::on_tableWidget_cellClicked(int row, int column) {
    MainTable *main_table = ui->tableWidget;
    if (column != 7)
        column = 7;
    std::string path = main_table->item(row, column)->text().toStdString();
    if (path.substr(path.find_last_of(".") + 1) == "mp3") {
        songPath = path;
    }
    if(!path.empty()) {
        getImage(path);
        ui->lyrics->setPlainText(QString::fromStdString(getLyrics(path)));
        ui->textBrowser->insertPlainText(QTime::currentTime().toString() + " : Image and lyrics for file "
                                         + main_table->item(row, 0)->text() + " loaded\n");
    }
}

void MainWindow::on_actionHelp_triggered() {
    QMessageBox::about(this, "uTag", "This project to work with audio-file tags and metadata!\n"
                       "You can use this app to view and edit audio-file tags, album images and lyrics.");
}

void MainWindow::setImage(const char *file_path, const char *image_path) {
    TagLib::MPEG::File mpegFile(file_path);
    TagLib::ID3v2::Tag *tag = mpegFile.ID3v2Tag();
    TagLib::ID3v2::FrameList frames = tag->frameList("APIC");
    TagLib::ID3v2::AttachedPictureFrame *frame = 0;
    if(frames.isEmpty()) {
        frame = new TagLib::ID3v2::AttachedPictureFrame;
        tag->addFrame(frame);
    }
    else {
        frame = dynamic_cast<TagLib::ID3v2::AttachedPictureFrame *>(frames.front());
    }
    ImageFile imageFile(image_path);
    TagLib::ByteVector imageData = imageFile.data();
    frame->setMimeType("image/jpeg");
    frame->setPicture(imageData);
    mpegFile.save();
}

void MainWindow::on_pushButton_3_clicked() {
    if(!songPath.empty() && imgPath != nullptr) {
        setImage(songPath.c_str(), imgPath.toStdString().c_str());
        ui->textBrowser->insertPlainText(QTime::currentTime().toString() + " : Image set!\n");
        getImage(songPath);
    } else {
         QMessageBox::warning(this, "Warning", "Before downloading, you need to select a file in the main window and"
                              "a picture through the button \"Select Image\"! File must also have the extension .mp3");
    }
}

void MainWindow::setLyrics(std::string songText) {
    if (!songPath.empty()) {
        TagLib::MPEG::File file(songPath.c_str());
        TagLib::ID3v2::FrameList frames = file.ID3v2Tag()->frameListMap()["USLT"];
        auto *frame = new TagLib::ID3v2::UnsynchronizedLyricsFrame;

        if (!file.ID3v2Tag()->frameListMap()["USLT"].isEmpty()) {
            file.ID3v2Tag()->removeFrames(file.ID3v2Tag()->frameListMap()["USLT"].front()->frameID());
        }
        frame->setText(songText);
        file.ID3v2Tag()->addFrame(frame);
        file.save();
    } else {
        QMessageBox::warning(this, "Warning", "Select a one of files in the main window!");
    }
}

void MainWindow::setDefaultImage(const QString &imgPath) {
    picture = new QPixmap(imgPath);
    int h = ui->pictureLabel->height();
    int w = ui->pictureLabel->width();

    ui->pictureLabel->setPixmap(picture->scaled(w, h, Qt::KeepAspectRatio));
}

std::string MainWindow::getLyrics(std::string path) {
    TagLib::String lyrics;
    TagLib::MPEG::File file(path.c_str());
    TagLib::ID3v2::FrameList frames = file.ID3v2Tag()->frameListMap()["USLT"];
    TagLib::ID3v2::UnsynchronizedLyricsFrame *frame = NULL;

    if (!frames.isEmpty()) {
        frame = dynamic_cast<TagLib::ID3v2::UnsynchronizedLyricsFrame *>(frames.front());
        if (frame)
            lyrics = frame->text();
    }
    return std::string(lyrics.toCString());
}

void MainWindow::on_saveLyrics_clicked() {
    if (!songPath.empty()) {
        std::string text = ui->lyrics->toPlainText().toStdString();
        if (!text.empty()) {
            setLyrics(text);
            ui->textBrowser->insertPlainText(QTime::currentTime().toString() + " : Lyrics set!\n");
        } else {
            QMessageBox::StandardButton but = QMessageBox::question(this, "Save", "Do you want to save empty lyrics?",
                                                                QMessageBox::Yes | QMessageBox::No);
            if (but == QMessageBox::Yes) {
                setLyrics(text);
                ui->textBrowser->insertPlainText(QTime::currentTime().toString() + " : Lyrics set!\n");
            } else {
                QMessageBox::about(this, "Information", "Empty lyrics wasn`t saved to file!");
            }
        }
        ui->lyrics->setPlainText("");
    } else {
        QMessageBox::warning(this, "Warning", "Select a one of files in the main window!");
    }
}
