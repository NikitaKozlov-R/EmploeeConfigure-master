#include "productwidget.h"

ProductWidget::ProductWidget(QWidget *parent) : QWidget(parent) {
    outputButton = new QPushButton;
    outputButton->setMinimumSize(200, 60);
    outputButton->setText("Показать параметры данного товара");

    productIdLabel = new QLabel;
    productNameLabel = new QLabel;

    mainLayout = new QGridLayout;
    mainLayout->addWidget(productIdLabel, 0, 0);
    mainLayout->addWidget(productNameLabel, 0, 1, 1, 2);
    mainLayout->addWidget(outputButton, 1, 0, 1, 3);

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
