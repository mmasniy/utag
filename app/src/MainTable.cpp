#include "MainTable.h"
#include "mainwindow.h"

void MainTable::setTable(const QModelIndex &index, const QString& sPath) {
    setApp(index, sPath);
    for (const auto& i : m_application->getTagsInfo()) {
        auto *year = new QTableWidgetItem();
        auto *absPath = new QTableWidgetItem(i.getAllInfo()["path"]);

        if (i.getAllInfo()["year"] != 0)
            year->setData(Qt::EditRole, i.getAllInfo()["year"]);
//        absPath->setFlags(absPath->flags() ^ Qt::ItemIsEditable ^ Qt::ItemIsSelectable);
        insertRow(rowCount());
        setItem(rowCount() - 1, 0, new QTableWidgetItem(i.getAllInfo()["filename"]));
        setItem(rowCount() - 1, 1, new QTableWidgetItem(i.getAllInfo()["title"]));
        setItem(rowCount() - 1, 2, new QTableWidgetItem(i.getAllInfo()["artist"]));
        setItem(rowCount() - 1, 3, new QTableWidgetItem(i.getAllInfo()["album"]));
        setItem(rowCount() - 1, 4, new QTableWidgetItem(i.getAllInfo()["track_number"]));
        setItem(rowCount() - 1, 5, new QTableWidgetItem(i.getAllInfo()["genre"]));
        setItem(rowCount() - 1, 6, year);
        setItem(rowCount() - 1, 7, absPath);
    }
}

MainTable::MainTable(QWidget *parent) : QTableWidget(parent) {
}

void MainTable::setApp(const QModelIndex &index, const QString& sPath) {
    std::cout << sPath.toStdString() << std::endl;
    Application *app = new Application;

    QDir dirent(sPath);
    dirent.setFilter(QDir::NoDotAndDotDot | QDir::Files);
    dirent.setNameFilters(QStringList() << "*.mp3" << "*.flac" << "*.waw" << "*.ogg" << "*.aif");

    QStringList list = dirent.entryList();
    for (auto& i : list) {
//        std::cout << i.toStdString() << std::endl;
        FileTags file(sPath.toStdString() + "/", i);
        app->setFileToInfo(file);
    }
//    app->printInfo();
    m_application = app;
}

MainTable::~MainTable() {
    delete m_application;
}
void MainTable::clearTable() {
    model()->removeRows(0, rowCount());
}

