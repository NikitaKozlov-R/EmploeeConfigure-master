#include "stockpilewidget.h"

StockpileWidget::StockpileWidget(QWidget *parent) : QWidget(parent)
{
    outputButton = new QPushButton;
    outputButton->setMinimumSize(400, 60);
    outputButton->setText("Показать позиции данного склада");

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
    stockpileSpace->setText("Общее место - " + QString::number(setSapce));
    stockpileProductCount->setText("Количество продуктов - " + QString::number(setProductCount));
    stockpileRemainSpace->setText("Оставшееся место - " + QString::number(setRemainSpace));
    stockpileIdLabel->setText("Номер склада - " + QString::number(setId));
    stockpileNameLabel->setText("Имя склада - " + setName);

    stockpileId = setId;
}

void StockpileWidget::setStockpileName(QString setName) {
    stockpileNameLabel->setText("Имя склада - " + setName);
}

void StockpileWidget::setStockpileCapacity(int setSapce) {
    stockpileSpace->setText("Общее место - " + QString::number(setSapce));
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
