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


