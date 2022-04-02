#include "workerscrollarea.h"

WorkerScrollArea::WorkerScrollArea(QWidget *parent) : QScrollArea(parent)
{
    this->setMinimumWidth(120);

    workerLayout = new QVBoxLayout;
    workerWidget = new QWidget;

    workerWidget->setLayout(workerLayout);

    this->setWidget(workerWidget);
}

void WorkerScrollArea::addWorker(int setId, QString setName, int setStockpileId, bool endOf) {
    if(endOf == 1) {
        workerButtons.push_back(new WorkerWidget);
        workerButtons[workerButtons.size() - 1]->setInformation(setId, setName, setStockpileId);
        makeLayout();

        workerWidget = new QWidget();
        workerWidget->setLayout(workerLayout);

        this->setWidget(workerWidget);
    }
    else {
        workerButtons.push_back(new WorkerWidget);
        workerButtons[workerButtons.size() - 1]->setInformation(setId, setName, setStockpileId);
    }
}

void WorkerScrollArea::makeLayout() {
    QVBoxLayout* tmpLayout = new QVBoxLayout;
    for(int i = 0; i < workerButtons.size(); i++) {
        tmpLayout->addWidget(workerButtons[i]);
    }

    delete workerLayout;
    workerLayout = tmpLayout;
}

void WorkerScrollArea::clearVector() {
    workerButtons.clear();
}

void WorkerScrollArea::clearLayout() {
    while(auto item = workerLayout->takeAt(0)) {
        delete item->widget();
    }
}

WorkerWidget* WorkerScrollArea::getWidget(int index) const{
    return workerButtons[index];
}
