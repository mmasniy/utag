#pragma once

#include "Application.h"

#include <QWidget>
#include <QTableWidget>

class MainTable : public QTableWidget {
    Q_OBJECT;
    public:
    explicit MainTable(QWidget *parent = nullptr);
    void setTable(const QModelIndex &index, const QString& sPath);
    void setApp(const QModelIndex &index, const QString& sPath);
    void clearTable();
    ~MainTable() override;
    protected:

    public slots:

    signals:

    private:
    Application *m_application;
};
