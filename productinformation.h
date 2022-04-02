#ifndef PRODUCTINFORMATION_H
#define PRODUCTINFORMATION_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>

#include <productscrollarea.h>

class ProductInformationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ProductInformationWidget(QWidget *parent = nullptr);
    void setInformation(int, QString, double, int, int, int, int);
    QLineEdit* getProductName();
    QLineEdit* getProductWeight();
    QLineEdit* getProductCost();
    QLineEdit* getProductCount();
    QLineEdit* getProductSupplierId();
    QLineEdit* getProductStockpileId();

private:
    QLabel* productId;
    QLineEdit* productName;
    QLineEdit* productWeight;
    QLineEdit* productCost;
    QLineEdit* productCount;
    QLineEdit* productSupplierId;
    QLineEdit* productStockpileId;
    QGridLayout* productLayout;
    QVBoxLayout* mainLayout;

signals:
    void nameChanged(QString, int);
    void weightChanged(double, int);
    void costChanged(int, int);
    void countChanged(int, int);
    void supplierIdChanged(int, int);
    void stockpileIdChanged(int, int);

public slots:
    void nameLineEditDataChanged();
    void weightLineEditDataChanged();
    void costLineEditDataChanged();
    void countLineEditDataChanged();
    void supplierIdLineEditDataChanged();
    void stockpileIdLineEditDataChanged();
};

#endif // PRODUCTINFORMATION_H
