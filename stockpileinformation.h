#ifndef STOCKPILEINFORMATION_H
#define STOCKPILEINFORMATION_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>

#include <workerscrollarea.h>

class StockpileInformation : public QWidget
{
    Q_OBJECT
public:
    explicit StockpileInformation(QWidget *parent = nullptr);
    void setInformation(int, QString, int, int, int);
    void addWorker(int setId, QString setName, int setStockpileId, bool endOf);
    void clearWorkers();
    WorkerScrollArea* getScrollArea();
    QLineEdit* getNameWidget() const;
    QLineEdit* getCapacityWidget() const;

private:
    QLabel* stockpileId;
    QLineEdit* stockpileName;
    QLineEdit* stockpileCapacity;
    QLabel* stockpileProductsCount;
    QLabel* stockpileRemainCapacity;
    QGridLayout* stockpileLayout;
    QVBoxLayout* mainLayout;

    WorkerScrollArea* workerScrollArea;

signals:

};

#endif // STOCKPILEINFORMATION_H
