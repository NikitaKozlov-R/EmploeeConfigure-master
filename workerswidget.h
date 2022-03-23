#ifndef WORKERSWIDGET_H
#define WORKERSWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>

class WorkerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WorkerWidget(QWidget *parent = nullptr);
    void setInformation(int, QString, int);
    QLineEdit* getNameLineEdit() const;
    QLineEdit* getStockpileLineEdit() const;

private:
    QLabel* workerId;
    QLineEdit* workerName;
    QLineEdit* workerStockpile;
    QGridLayout* workerLayout;

signals:
    void nameChanged(QString, int);
    void stockpileChanged(int, int);

public slots:
    void nameLineEditDataChanged();
    void stockpileLineEditDataChanged();
};

#endif // WORKERSWIDGET_H
