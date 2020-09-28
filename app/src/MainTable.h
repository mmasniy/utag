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
    QWidget* setCheck();
    void setTable(const QString& sPath);
    void setApp(const QString& sPath);
    void commitData(QWidget *editor) override;
    void clearTable();
    bool checkPermForFile(QString sPath);
    ~MainTable() override;
    protected:

    public slots:

    signals:

    private:
    Application m_application;
};
