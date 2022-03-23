#include "productscrollarea.h"

ProductScrollArea::ProductScrollArea(QWidget *parent) : QScrollArea(parent)
{
    this->setMinimumWidth(120);

    productLayout = new QVBoxLayout;
    productWidget = new QWidget;

    productWidget->setLayout(productLayout);

    this->setWidget(productWidget);
}

void ProductScrollArea::addProduct(int setId, QString setName, bool endOf) {
    if(endOf == 1) {
        productButtons.push_back(new ProductWidget);
        productButtons[productButtons.size() - 1]->setInformation(setId, setName);
        makeLayout();

        productWidget = new QWidget();
        productWidget->setLayout(productLayout);

        this->setWidget(productWidget);
    }
    else {
        productButtons.push_back(new ProductWidget);
        productButtons[productButtons.size() - 1]->setInformation(setId, setName);
    }
}

void ProductScrollArea::removeProduct(int setId) {
    for(int i = 0; i < productButtons.size(); i++) {
        if(productButtons[i]->getProductId() == setId) {
            productButtons.erase(productButtons.begin() + i);
        }
    }

    makeLayout();

    productWidget = new QWidget();
    productWidget->setLayout(productLayout);

    this->setWidget(productWidget);
}

void ProductScrollArea::makeLayout() {
    QVBoxLayout* tmpLayout = new QVBoxLayout;
    for(int i = 0; i < productButtons.size(); i++) {
        tmpLayout->addWidget(productButtons[i]);
    }

    delete productLayout;
    productLayout = tmpLayout;
}

void ProductScrollArea::clearVector() {
    productButtons.clear();
}

void ProductScrollArea::clearLayout() {
    while(auto item = productLayout->takeAt(0)) {
        delete item->widget();
    }
}

ProductWidget* ProductScrollArea::getWidget(int index) const {
    if (index > productButtons.size() - 1) {
        return nullptr;
    }
    return productButtons[index];
}

void ProductScrollArea::returnProductId(int setId) {
    emit returnIdToProducts(setId);
}

int ProductScrollArea::getSize() {
    return productButtons.size();
}
