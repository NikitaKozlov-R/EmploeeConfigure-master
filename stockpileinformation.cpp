#include "stockpileinformation.h"

StockpileInformation::StockpileInformation(QWidget *parent) : QWidget(parent)
{
    stockpileId = new QLabel;
    QLabel* stockpileIdLabel = new QLabel("ID склада");

    stockpileName = new QLineEdit;
    QLabel* stockpileNameLabel = new QLabel("Название склада");

    stockpileCapacity = new QLineEdit;
    QLabel* stockpileCapacityLabel = new QLabel("Вместимость склада");

    stockpileProductsCount = new QLabel;
    QLabel* stockpileProductsCountLabel = new QLabel("Количество товаров");

    stockpileRemainCapacity = new QLabel;
    QLabel* stockpileRemainCapacityLabel = new QLabel("Оставшееся место");

    stockpileLayout = new QGridLayout;
    stockpileLayout->addWidget(stockpileIdLabel, 0, 0, 1, 1);
    stockpileLayout->addWidget(stockpileId, 0, 1, 1, 2);
    stockpileLayout->addWidget(stockpileNameLabel, 1, 0, 1, 1);
    stockpileLayout->addWidget(stockpileName, 1, 1, 1, 2);
    stockpileLayout->addWidget(stockpileCapacityLabel, 2, 0, 1, 1);
    stockpileLayout->addWidget(stockpileCapacity, 2, 1, 1, 2);
    stockpileLayout->addWidget(stockpileProductsCountLabel, 3, 0, 1, 1);
    stockpileLayout->addWidget(stockpileProductsCount, 3, 1, 1, 2);
    stockpileLayout->addWidget(stockpileRemainCapacityLabel, 4, 0, 1, 1);
    stockpileLayout->addWidget(stockpileRemainCapacity, 4, 1, 1, 2);

    workerScrollArea = new WorkerScrollArea;
    QLabel* workerTitle = new QLabel("Работники");

    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(stockpileLayout);
    mainLayout->addWidget(workerTitle);
    mainLayout->addWidget(workerScrollArea);
    this->setLayout(mainLayout);
}

void StockpileInformation::setInformation(int setId, QString setName, int setCapacity, int setProductsCount, int setRemainCapacity) {
    stockpileId->setText(QString::number(setId));
    stockpileName->setText(setName);
    stockpileCapacity->setText(QString::number(setCapacity));
    stockpileProductsCount->setText(QString::number(setProductsCount));
    stockpileRemainCapacity->setText(QString::number(setRemainCapacity));
}

void StockpileInformation::addWorker(int setId, QString setName, int setStockpileId, bool endOf) {
    workerScrollArea->addWorker(setId, setName, setStockpileId, endOf);
}

void StockpileInformation::clearWorkers() {
    workerScrollArea->clearLayout();
    workerScrollArea->clearVector();
}

WorkerScrollArea* StockpileInformation::getScrollArea() {
    return workerScrollArea;
}

QLineEdit* StockpileInformation::getNameWidget() const{
    return stockpileName;
}
QLineEdit* StockpileInformation::getCapacityWidget() const{
    return stockpileCapacity;
}
