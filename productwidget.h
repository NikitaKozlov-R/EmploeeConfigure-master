#ifndef PRODUCTWIDGET_H
#define PRODUCTWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

class ProductWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ProductWidget(QWidget *parent = nullptr);
    void setInformation(int, QString);
    QPushButton* getOutputButton();
    int getProductId() const;

private:
    QPushButton* outputButton;
    QLabel* productIdLabel;
    QLabel* productNameLabel;

    QGridLayout* mainLayout;

    int productId;

signals:
    void productButtonIdReturn(int);

public slots:
    void productButtonClickedToId();
};

#endif // PRODUCTWIDGET_H
