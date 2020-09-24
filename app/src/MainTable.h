#pragma once

#include "Application.h"

#include <QWidget>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QCheckBox>

class MainTable : public QTableWidget {
    Q_OBJECT;
    public:
    explicit MainTable(QWidget *parent = nullptr);
    void setTable(const QModelIndex &index, const QString& sPath);
    void setApp(const QString& sPath);
    void commitData(QWidget *editor) override;
    void clearTable();
    ~MainTable() override;
    protected:

    public slots:

    signals:

    private:
    Application m_application;
};
