#include "stockpilewidget.h"

StockpileWidget::StockpileWidget(QWidget *parent) : QWidget(parent)
{
    outputButton = new QPushButton;
    outputButton->setMinimumSize(400, 40);
    outputButton->setText("Товары и парметры");

    stockpileSpace = new QLabel;
    stockpileProductCount = new QLabel;
    stockpileRemainSpace = new QLabel;
    stockpileIdLabel = new QLabel;
    stockpileNameLabel = new QLabel;

    mainLayout = new QGridLayout;
    mainLayout->addWidget(stockpileIdLabel, 0, 0);
    mainLayout->addWidget(stockpileNameLabel, 0, 1, 1, 2);
    mainLayout->addWidget(outputButton, 1, 0, 1, 3);
    mainLayout->addWidget(stockpileSpace, 2, 0, 1, 3);
    mainLayout->addWidget(stockpileProductCount, 3, 0, 1, 3);
    mainLayout->addWidget(stockpileRemainSpace, 4, 0, 1, 3);

    this->setLayout(mainLayout);
}

void StockpileWidget::setStockpileInformation(int setSapce, int setProductCount, int setRemainSpace, int setId, QString setName) {
    stockpileSpace->setText("Общее место: " + QString::number(setSapce));
    stockpileProductCount->setText("Количество товаров: " + QString::number(setProductCount));
    stockpileRemainSpace->setText("Свободно мест: " + QString::number(setRemainSpace));
    stockpileIdLabel->setText("ID склада: " + QString::number(setId));
    stockpileNameLabel->setText("Склад " + setName);

    stockpileId = setId;
}

void StockpileWidget::setStockpileName(QString setName) {
    stockpileNameLabel->setText("Склад " + setName);
}

void StockpileWidget::setStockpileCapacity(int setSapce) {
    stockpileSpace->setText("Общее место: " + QString::number(setSapce));
}

QPushButton* StockpileWidget::getOutputButton() const{
    return outputButton;
}

void StockpileWidget::setStockpileId(int setId) {
    stockpileId = setId;
}

int StockpileWidget::getStockpileId() const {
    return stockpileId;
}

void StockpileWidget::stockpileButtonClickedToId() {
    emit stockpileButtonIdReturn(stockpileId);
}
