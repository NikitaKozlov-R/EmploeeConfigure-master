#include "productinformation.h"

ProductInformationWidget::ProductInformationWidget(QWidget *parent) : QWidget(parent)
{
    productId = new QLabel;
    QLabel* productIdLabel = new QLabel("ID продукта");

    productName = new QLineEdit;
    QLabel* productNameLabel = new QLabel("Название продукта");

    productWeight = new QLineEdit;
    QLabel* productCapacityLabel = new QLabel("Масса продукта");

    productCost = new QLineEdit;
    QLabel* productCostLabel = new QLabel("Стоимость");

    productCount = new QLineEdit;
    QLabel* productCountLabel = new QLabel("Количество");

    productSupplierId = new QLineEdit;
    QLabel* productSupplierIdLabel = new QLabel("ID поставщика");

    productStockpileId = new QLineEdit;
    QLabel* productStockpileIdLabel = new QLabel("ID склада");

    productLayout = new QGridLayout;
    productLayout->addWidget(productIdLabel, 0, 0, 1, 1);
    productLayout->addWidget(productId, 0, 1, 1, 2);
    productLayout->addWidget(productNameLabel, 1, 0, 1, 1);
    productLayout->addWidget(productName, 1, 1, 1, 2);
    productLayout->addWidget(productCapacityLabel, 2, 0, 1, 1);
    productLayout->addWidget(productWeight, 2, 1, 1, 2);
    productLayout->addWidget(productCostLabel, 3, 0, 1, 1);
    productLayout->addWidget(productCost, 3, 1, 1, 2);
    productLayout->addWidget(productCountLabel, 4, 0, 1, 1);
    productLayout->addWidget(productCount, 4, 1, 1, 2);
    productLayout->addWidget(productSupplierIdLabel, 5, 0, 1, 1);
    productLayout->addWidget(productSupplierId, 5, 1, 1, 2);
    productLayout->addWidget(productStockpileIdLabel, 6, 0, 1, 1);
    productLayout->addWidget(productStockpileId, 6, 1, 1, 2);

    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(productLayout);
    this->setLayout(mainLayout);
}

void ProductInformationWidget::setInformation(int setId, QString setName, double setWeight, int setCost, int setCount, int setSupplierId, int setStockpileId) {
    productId->setText(QString::number(setId));
    productName->setText(setName);
    productWeight->setText(QString::number(setWeight));
    productCost->setText(QString::number(setCost));
    productCount->setText(QString::number(setCount));
    productSupplierId->setText(QString::number(setSupplierId));
    productStockpileId->setText(QString::number(setStockpileId));
}

QLineEdit* ProductInformationWidget::getProductName() {
    return productName;
}
QLineEdit* ProductInformationWidget::getProductWeight() {
    return productWeight;
}
QLineEdit* ProductInformationWidget::getProductCost() {
    return productCost;
}
QLineEdit* ProductInformationWidget::getProductCount() {
    return productCount;
}
QLineEdit* ProductInformationWidget::getProductSupplierId() {
    return productSupplierId;
}
QLineEdit* ProductInformationWidget::getProductStockpileId() {
    return productStockpileId;
}

void ProductInformationWidget::nameLineEditDataChanged() {
    emit nameChanged(productName->text(), productId->text().toInt());
}
void ProductInformationWidget::weightLineEditDataChanged() {
    emit weightChanged(productWeight->text().toDouble(), productId->text().toInt());
}
void ProductInformationWidget::costLineEditDataChanged() {
    emit costChanged(productCost->text().toInt(), productId->text().toInt());
}
void ProductInformationWidget::countLineEditDataChanged() {
    emit countChanged(productCount->text().toInt(), productId->text().toInt());
}
void ProductInformationWidget::supplierIdLineEditDataChanged() {
    emit supplierIdChanged(productSupplierId->text().toInt(), productId->text().toInt());
}
void ProductInformationWidget::stockpileIdLineEditDataChanged() {
    emit stockpileIdChanged(productStockpileId->text().toInt(), productId->text().toInt());
}

