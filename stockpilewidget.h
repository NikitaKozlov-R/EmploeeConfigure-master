#ifndef STOCKPILEWIDGET_H
#define STOCKPILEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
//#include <mainwindow.h>

class StockpileWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StockpileWidget(QWidget *parent = nullptr);
    void setStockpileInformation(int setSapce, int setProductCount, int setRemainSpace, int setId, QString setName);
    QPushButton* getOutputButton() const;

    void setStockpileId(int);
    int getStockpileId() const;

private:
    QPushButton* outputButton;
    QLabel* stockpileSpace;
    QLabel* stockpileProductCount;
    QLabel* stockpileRemainSpace;
    QLabel* stockpileIdLabel;
    QLabel* stockpileNameLabel;

    int stockpileId;

    QGridLayout* mainLayout;

signals:
    void stockpileButtonIdReturn(int);

public slots:
    void stockpileButtonClickedToId();
};

#endif // STOCKPILEWIDGET_H
