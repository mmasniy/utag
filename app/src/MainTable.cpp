#include "MainTable.h"
#include "mainwindow.h"

void MainTable::setTable(const QModelIndex &index, const QString& sPath) {
    setApp(sPath);
    for (const auto& i : m_application.getTagsInfo()) {
        auto *year = new QTableWidgetItem();
        auto *absPath = new QTableWidgetItem(i.getAllInfo()["path"]);
        auto *fileName = new QTableWidgetItem(i.getAllInfo()["filename"]);
//        auto *check_box = new QCheckBox();

        if (i.getAllInfo()["year"] != 0)
            year->setData(Qt::EditRole, i.getAllInfo()["year"]);
        absPath->setFlags(absPath->flags() ^ Qt::ItemIsEditable ^ Qt::ItemIsSelectable);
        fileName->setFlags(fileName->flags() ^ Qt::ItemIsEditable ^ Qt::ItemIsSelectable);
//        check_box->setCheckState(Qt::Unchecked);
        insertRow(rowCount());

        setItem(rowCount() - 1, 0, fileName);
        setItem(rowCount() - 1, 1, new QTableWidgetItem(i.getAllInfo()["title"]));
        setItem(rowCount() - 1, 2, new QTableWidgetItem(i.getAllInfo()["artist"]));
        setItem(rowCount() - 1, 3, new QTableWidgetItem(i.getAllInfo()["album"]));
        setItem(rowCount() - 1, 4, new QTableWidgetItem(i.getAllInfo()["track_number"]));
        setItem(rowCount() - 1, 5, new QTableWidgetItem(i.getAllInfo()["genre"]));
        setItem(rowCount() - 1, 6, year);
        setItem(rowCount() - 1, 7, absPath);
//        setCellWidget(rowCount() - 1, 8, check_box);
    }
}

MainTable::MainTable(QWidget *parent) : QTableWidget(parent) {
}

void MainTable::setApp(const QString& sPath) {
    std::cout << sPath.toStdString() << std::endl;
    Application app;

    QDir dirent(sPath);
    dirent.setFilter(QDir::NoDotAndDotDot | QDir::Files);
    dirent.setNameFilters(QStringList() << "*.mp3" << "*.flac" << "*.waw" << "*.ogg" << "*.aif");

    QStringList list = dirent.entryList();
    for (auto& i : list) {
        FileTags file(sPath.toStdString() + "/", i);
        app.setFileToInfo(file);
    }
    m_application = app;
}

MainTable::~MainTable() {
}

void MainTable::clearTable() {
    model()->removeRows(0, rowCount());
}
void MainTable::commitData(QWidget *editor) {
    QAbstractItemView::commitData(editor);

    for (auto &i : selectedIndexes()) {
        std::cout << i.row() << std::endl;
        model()->setData(i, currentItem()->data(Qt::EditRole), Qt::EditRole);
    }
}

