#include "workerswidget.h"

WorkerWidget::WorkerWidget(QWidget *parent) : QWidget(parent)
{
    workerId = new QLabel;
    QLabel* workerIdLabel = new QLabel("ID:");

    workerName = new QLineEdit;
    workerName->setMinimumWidth(320);
    QLabel* workerNameLabel = new QLabel("ФИО:");

    workerStockpile = new QLineEdit;
    workerStockpile->setMinimumWidth(320);
    QLabel* workerStockpileLabel = new QLabel("Склад:");

    workerLayout = new QGridLayout;
    workerLayout->addWidget(workerIdLabel, 0, 0, 1, 1);
    workerLayout->addWidget(workerId, 0, 1, 1, 2);
    workerLayout->addWidget(workerNameLabel, 1, 0, 1, 1);
    workerLayout->addWidget(workerName, 1, 1, 1, 2);
    workerLayout->addWidget(workerStockpileLabel, 2, 0, 1, 1);
    workerLayout->addWidget(workerStockpile, 2, 1, 1, 2);
    this->setLayout(workerLayout);
}

void WorkerWidget::setInformation(int setId, QString setName, int setStockpileId) {
    workerId->setText(QString::number(setId));
    workerName->setText(setName);
    workerStockpile->setText(QString::number(setStockpileId));
}

QLineEdit* WorkerWidget::getNameLineEdit() const {
    return workerName;
}
QLineEdit* WorkerWidget::getStockpileLineEdit() const {
    return workerStockpile;
}

void WorkerWidget::nameLineEditDataChanged() {
    emit nameChanged(workerName->text(), workerId->text().toInt());
}
void WorkerWidget::stockpileLineEditDataChanged() {
    emit stockpileChanged(workerStockpile->text().toInt(), workerId->text().toInt());
}
