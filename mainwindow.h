#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QRandomGenerator>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QVector>
#include <QWidget>

#include <stockpilewidget.h>
#include <productwidget.h>
#include <stockpilescrollarea.h>
#include <productscrollarea.h>
#include <stockpileinformation.h>
#include <productinformation.h>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();
    QString wordGenerate();

    void makeTest();
    void makeConnection();
    void makeStockpileLayout();
    void makeProductLayout(int);
    void makeStockpileInformationLayout(int);
    void makeProductInformationLayout(int productClickedId);

    void clearLayout(QLayout*);

private:
    QSqlDatabase db;

    QLabel* stockpileTitle;
    StockpileScrollArea* stockpileScrollArea;
    QPushButton* addNewStockpileButton;
    QVBoxLayout* stockpileLayout;

    ProductScrollArea* productScrollArea;
    QLabel* productTitle;
    QPushButton* addNewProductButton;
    QVBoxLayout* productLayout;

    QWidget* informationWidget;
    StockpileInformation* stockpileInformationWidget;
    QPushButton* deleteStockpileButton;
    ProductInformationWidget* productInformationWidget;
    QPushButton* deleteProductButton;
    QLabel* informationTitle;
    QVBoxLayout* informationLayout;

    QHBoxLayout* mainLayout;

    int currentStockpileId = -1;
    int currentProductId = -1;

public slots:
    void stockpileButtonClicked(int);
    void productButtonClicked(int getId);

    void addStockpile();
    void addProduct();

    void deleteStockpile();
    void deleteProduct();

    void stockpileNameChanged();
    void stockpileCapacityChanged();

    void workerNameChanged(QString, int);
    void workerStockpileChanged(int, int);

    void productNameChanged(QString, int);
    void productWeightChanged(double, int);
    void productCostChanged(int, int);
    void productCountChanged(int, int);
    void productSupplierIdChanged(int, int);
    void productStockpileIdChanged(int, int);
};
#endif // MAINWINDOW_H
