#ifndef PRODUCTSCROLLAREA_H
#define PRODUCTSCROLLAREA_H

#include <QWidget>
#include <QPushButton>
#include <QVector>
#include <QVBoxLayout>
#include <QScrollArea>

#include <productwidget.h>

class ProductScrollArea : public QScrollArea
{
    Q_OBJECT
public:
    explicit ProductScrollArea(QWidget *parent = nullptr);
    void addProduct(int, QString, bool);
    void removeProduct(int setId);
    void makeLayout();
    void clearLayout();
    void clearVector();
    ProductWidget* getWidget(int index) const;
    int getSize();

private:
    QVector<ProductWidget*> productButtons;
    QVBoxLayout* productLayout;
    QWidget* productWidget;

signals:
    void returnIdToProducts(int);

public slots:
    void returnProductId(int);
};

#endif // PRODUCTSCROLLAREA_H
