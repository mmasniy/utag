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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QString path = "/", QWidget *parent = nullptr);
    void checkDirPermitions(QString& sPath);
    ~MainWindow() override;

private slots:
    void on_treeView_clicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;
    QDir *dir;
};
#endif // MAINWINDOW_H
