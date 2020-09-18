#pragma once

#include <QFileSystemModel>
#include <QDialog>
#include <QtCore>
#include <QtGui>

class Dialog : public QDialog {
    Q_OBJECT

    public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    private:
    Dialog *ui;
    QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;
};
