#include "productwidget.h"

ProductWidget::ProductWidget(QWidget *parent) : QWidget(parent) {
    outputButton = new QPushButton;
    outputButton->setMinimumSize(10, 40);
    outputButton->setText("Параметры товара");

    productIdLabel = new QLabel;
    productNameLabel = new QLabel;

    mainLayout = new QGridLayout;
    mainLayout->addWidget(productIdLabel, 0, 0);
    mainLayout->addWidget(productNameLabel, 0, 1, 1, 6);
    mainLayout->addWidget(outputButton, 1, 0, 1, 7);

    this->setLayout(mainLayout);
}

void ProductWidget::setInformation(int setId, QString setName) {
    productId = setId;

    productIdLabel->setText(QString::number(setId));
    productNameLabel->setText(setName);
}

QPushButton* ProductWidget::getOutputButton() {
    return outputButton;
}

void ProductWidget::productButtonClickedToId() {
    emit productButtonIdReturn(productId);
}

int ProductWidget::getProductId() const {
    return productId;
}
