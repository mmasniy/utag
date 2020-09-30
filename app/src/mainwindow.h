#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QFileSystemModel>
#include <QDir>
#include <QTreeView>
#include <QString>
#include <QStringList>
#include <QPixmap>
#include <QFileDialog>
#include <QMessageBox>

#include "ImageFile.h"
#include "MainTable.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QString path = "/", QWidget *parent = nullptr);
    bool checkDirPermitions(QString& sPath);
    void getImage(std::string path);
    void setImage(const char *file_path, const char *image_path);
    void saveTagsInFile(MainTable *main_table, TagLib::FileRef& file, int i);
    void setLyrics(std::string songText);
    std::string getLyrics(std::string path);
    ~MainWindow() override;

private slots:
    void on_treeView_clicked(const QModelIndex &index);

    void on_changeDir_clicked();

    void on_saveChages_clicked();

    void on_pushButton_5_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_actionHelp_triggered();

    void on_pushButton_3_clicked();

    void on_saveLyrics_clicked();

private:
    Ui::MainWindow *ui;
    QFileSystemModel *dirmodel;
    QDir *dir;
    QPixmap *picture;
    QString imgPath;
    std::string songPath;
};
#endif // MAINWINDOW_H
