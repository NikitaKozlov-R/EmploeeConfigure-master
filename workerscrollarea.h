#ifndef WORKERSCROLLAREA_H
#define WORKERSCROLLAREA_H

#include <QWidget>
#include <QScrollArea>
#include <QVector>
#include <QVBoxLayout>

#include <workerswidget.h>

class WorkerScrollArea : public QScrollArea
{
    Q_OBJECT
public:
    explicit WorkerScrollArea(QWidget *parent = nullptr);
    void addWorker(int, QString, int, bool);
    void makeLayout();
    int getSize() const;
    void clearVector();
    void clearLayout();
    WorkerWidget* getWidget(int) const;

private:
    QVector<WorkerWidget*> workerButtons;
    QVBoxLayout* workerLayout;
    QWidget* workerWidget;
signals:

};

#endif // WORKERSCROLLAREA_H
