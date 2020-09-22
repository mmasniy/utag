#include "MainTable.h"
#include "mainwindow.h"



void MainTable::setTable(const QModelIndex &index, const QString& sPath) {

}

MainTable::MainTable(QWidget *parent) : QTableWidget(parent) {
}

void MainTable::setApp(const QModelIndex &index, const QString& sPath) {
    std::cout << sPath.toStdString() << std::endl;
    Application app;

    QDir dirent(sPath);
    dirent.setFilter(QDir::NoDotAndDotDot | QDir::Files);
    dirent.setNameFilters(QStringList() << "*.mp3" << "*.flac" << "*.waw" << "*.ogg" << "*.aif");

    QStringList list = dirent.entryList();
    for (auto& i : list) {
        std::cout << i.toStdString() << std::endl;
        FileTags file(sPath.toStdString() + "/", i.toStdString());
        app.setFileToInfo(file);
    }
    app.printInfo();
    m_application = app;
}
