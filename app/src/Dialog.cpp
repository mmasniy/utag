#include "Dialog.h"
////#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new(Dialog)) {
    ui->setupUi(this);

    QString sPath = "~/";

    dirmodel = new QFileSystemModel(this);
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirmodel->setRootPath(sPath);
    ui->treeView->setModel(dirmodel);
}

Dialog::~Dialog() noexcept {
    delete ui;
}
