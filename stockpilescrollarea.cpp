#include "stockpilescrollarea.h"

StockpileScrollArea::StockpileScrollArea(QWidget * parent) : QScrollArea(parent)
{
    this->setMinimumWidth(150);

    stockpileLayout = new QVBoxLayout;
    stockpileWidget = new QWidget;

    stockpileWidget->setLayout(stockpileLayout);

    this->setWidget(stockpileWidget);
}

void StockpileScrollArea::addStockpile(int setSapce, int setProductCount,
                  int setRemainSpace, int setId, QString setName) {
    stockpileButtons.push_back(new StockpileWidget);
    stockpileButtons[stockpileButtons.size() - 1] -> setStockpileInformation(setSapce, setProductCount,
                                                                           setRemainSpace, setId, setName);
    makeLayout();

    stockpileWidget = new QWidget();
    stockpileWidget->setLayout(stockpileLayout);

    this->setWidget(stockpileWidget);
}

void StockpileScrollArea::removeStockpile(int setId) {
    for(int i = 0; i < stockpileButtons.size(); i++) {
        if(stockpileButtons[i] -> getStockpileId() === setId) {
            stockpileButtons.erase(stockpileButtons.begin() + i);
        }
    }

    makeLayout();

    stockpileWidget = new QWidget();
    stockpileWidget->setLayout(stockpileLayout);

    this->setWidget(stockpileWidget);
}

void StockpileScrollArea::makeLayout() {
    QVBoxLayout * tmpLayout = new QVBoxLayout;
    for(int i = 0; i < stockpileButtons.size(); i++) {
        tmpLayout->addWidget(stockpileButtons[i]);
    }

    delete stockpileLayout;
    stockpileLayout = tmpLayout;
}

int StockpileScrollArea::getSize() const {
    return stockpileButtons.size();
}

StockpileWidget * StockpileScrollArea::getWidget(int index) const {
    if (index > stockpileButtons.size() - 1) {
        return nullptr;
    }
    return stockpileButtons[index];
}

void StockpileScrollArea::returnStockpileId(int setId) {
    emit returnIdToProducts(setId);
}
