#ifndef STOCKPILESCROLLAREA_H
#define STOCKPILESCROLLAREA_H

#include <QWidget>
#include <QScrollArea>
#include <QLabel>
#include <QVBoxLayout>
#include <QVector>

#include <stockpilewidget.h>

class StockpileScrollArea : public QScrollArea
{
    Q_OBJECT
public:
    explicit StockpileScrollArea(QWidget *parent = nullptr);
    void addStockpile(int setSapce, int setProductCount, int setRemainSpace, int setId, QString setName);
    void removeStockpile(int setId);
    void makeLayout();
    int getSize() const;
    StockpileWidget* getWidget(int) const;

private:
    QVector<StockpileWidget*> stockpileButtons;
    QVBoxLayout* stockpileLayout;
    QWidget* stockpileWidget;

signals:
    void returnIdToProducts(int);

public slots:
    void returnStockpileId(int);
};

#endif // STOCKPILESCROLLAREA_H
