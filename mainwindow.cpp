#include "mainwindow.h"

namespace stockpileDB {
    int STOCKPILE_ID = 0;
    int STOCKPILE_NAME = 1;
    int STOCKPILE_PRODUCTS_COUNT = 2;
    int STOCKPILE_CAPACITY = 3;
    int STOCKPILE_SPACE_REMAINING = 4;
}

namespace productDB {
    int PRODUCT_ID = 0;
    int PRODUCT_NAME = 1;
    int PRODUCT_WEIGHT = 2;
    int PRODICT_COST = 3;
    int PRODUCT_COUNT = 4;
    int SUPPLIER_ID = 5;
    int STOCKPILE_ID = 6;
}

namespace employeeDB {
    int EMPLOYEE_ID = 0;
    int EMPLOYEE_NAME = 1;
    int STOCKPILE_ID = 2;
}

MainWindow::MainWindow()
{
    styleSheetFile->open(QIODevice::ReadOnly);
    QString style = styleSheetFile->readAll();

    stockpileScrollArea = new StockpileScrollArea();
    stockpileTitle = new QLabel("Список складов");
    addNewStockpileButton = new QPushButton("Добавить новый склад");

    stockpileLayout = new QVBoxLayout();
    stockpileLayout->addWidget(stockpileTitle);
    stockpileLayout->addWidget(stockpileScrollArea);
    stockpileLayout->addWidget(addNewStockpileButton);

    productScrollArea = new ProductScrollArea();
    productTitle = new QLabel("Список продуктов");
    addNewProductButton = new QPushButton("Добавить новый продукт");
    addNewProductButton->setEnabled(0);

    productLayout = new QVBoxLayout();
    productLayout->addWidget(productTitle);
    productLayout->addWidget(productScrollArea);
    productLayout->addWidget(addNewProductButton);

    stockpileInformationWidget = new StockpileInformation();
    productInformationWidget = new ProductInformationWidget();
    informationTitle = new QLabel("Информация");

    deleteStockpileButton = new QPushButton("Удалить склад");
    deleteProductButton = new QPushButton("Удалить продукт");

    informationLayout = new QVBoxLayout();
    informationLayout->addWidget(informationTitle);
    informationLayout->addWidget(deleteProductButton);
    informationLayout->addWidget(productInformationWidget);
    informationLayout->addWidget(deleteStockpileButton);
    informationLayout->addWidget(stockpileInformationWidget);

    makeStockpileLayout();

    this->setStyleSheet(style);

    mainLayout = new QHBoxLayout(this);
    mainLayout->addLayout(stockpileLayout);
    mainLayout->addLayout(productLayout);
    mainLayout->addLayout(informationLayout);
    this->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
}

//-------------------------FUNCTONS-----------------------------//

void MainWindow::makeStockpileLayout() { //---------Make Stockpile Layout
    QSqlQuery stockpileQuery;
    stockpileQuery.exec("select * from stockpiles;");
    if(!stockpileQuery.first()) {
        return;
    }

    int index = 0;

    do {
        stockpileScrollArea->addStockpile(stockpileQuery.value(stockpileDB::STOCKPILE_CAPACITY).toInt(),
                                             stockpileQuery.value(stockpileDB::STOCKPILE_PRODUCTS_COUNT).toInt(),
                                             stockpileQuery.value(stockpileDB::STOCKPILE_SPACE_REMAINING).toInt(),
                                             stockpileQuery.value(stockpileDB::STOCKPILE_ID).toInt(),
                                             stockpileQuery.value(stockpileDB::STOCKPILE_NAME).toString());

        connect(stockpileScrollArea->getWidget(index)->getOutputButton(), SIGNAL(clicked()),
                stockpileScrollArea->getWidget(index), SLOT(stockpileButtonClickedToId()));
        connect(stockpileScrollArea->getWidget(index), SIGNAL(stockpileButtonIdReturn(int)),
                this, SLOT(stockpileButtonClicked(int)));
        index++;
    } while (stockpileQuery.next());
}

void MainWindow::makeProductLayout(int stockpileClickedId) { // -----------Make Product Layout
    productScrollArea->clearLayout();
    productScrollArea->clearVector();

    currentStockpileId = stockpileClickedId;

    QSqlQuery productQuery;
    productQuery.exec("select * from products where STOCKPILE_ID = " + QString::number(stockpileClickedId) + " order by PRODUCT_ID;");
    if(!productQuery.first()) {
        return;
    }

    int querySize = productQuery.numRowsAffected() - 1;
    int index = 0;

    do {
        if(querySize == 0){
            productScrollArea->addProduct(productQuery.value(productDB::PRODUCT_ID).toInt(),
                                      productQuery.value(productDB::PRODUCT_NAME).toString(), 1);
        }

        else {
            productScrollArea->addProduct(productQuery.value(productDB::PRODUCT_ID).toInt(),
                                      productQuery.value(productDB::PRODUCT_NAME).toString(), 0);
        }

        connect(productScrollArea->getWidget(index)->getOutputButton(), SIGNAL(clicked()),
                productScrollArea->getWidget(index), SLOT(productButtonClickedToId()));
        connect(productScrollArea->getWidget(index), SIGNAL(productButtonIdReturn(int)),
                this, SLOT(productButtonClicked(int)));

        querySize--;
        index++;
    } while(productQuery.next());

    addNewProductButton->setEnabled(1);
}

void MainWindow::makeStockpileInformationLayout(int stockpileClickedId) { //---Emits Information about Stockpile
    stockpileInformationWidget->clearWorkers();

    QSqlQuery stockpileQuery;
    stockpileQuery.exec("select * from stockpiles where STOCKPILE_ID = " +
                                                          QString::number(stockpileClickedId) + ";");
    if(!stockpileQuery.first()) {
        return;
    }

    stockpileInformationWidget->setInformation(stockpileQuery.value(stockpileDB::STOCKPILE_ID).toInt(),
                                               stockpileQuery.value(stockpileDB::STOCKPILE_NAME).toString(),
                                               stockpileQuery.value(stockpileDB::STOCKPILE_PRODUCTS_COUNT).toInt(),
                                               stockpileQuery.value(stockpileDB::STOCKPILE_CAPACITY).toInt(),
                                               stockpileQuery.value(stockpileDB::STOCKPILE_SPACE_REMAINING).toInt());

    stockpileQuery.exec("select * from employees where STOCKPILE_ID = " +
                        QString::number(stockpileClickedId) + ";");
    if(!stockpileQuery.first()) {
        return;
    }
    int querySize = stockpileQuery.numRowsAffected() - 1;
    int index = 0;

    do {
        if(querySize == 0) {
            stockpileInformationWidget->addWorker(stockpileQuery.value(employeeDB::EMPLOYEE_ID).toInt(),
                                              stockpileQuery.value(employeeDB::EMPLOYEE_NAME).toString(),
                                              stockpileQuery.value(employeeDB::STOCKPILE_ID).toInt(), 1);
        }
        else {
            stockpileInformationWidget->addWorker(stockpileQuery.value(employeeDB::EMPLOYEE_ID).toInt(),
                                              stockpileQuery.value(employeeDB::EMPLOYEE_NAME).toString(),
                                              stockpileQuery.value(employeeDB::STOCKPILE_ID).toInt(), 0);
        }
        connect(stockpileInformationWidget->getScrollArea()->getWidget(index)->getNameLineEdit(),
                SIGNAL(editingFinished()), stockpileInformationWidget->getScrollArea()->getWidget(index), SLOT(nameLineEditDataChanged()));
        connect(stockpileInformationWidget->getScrollArea()->getWidget(index),
                SIGNAL(nameChanged(QString,int)), this, SLOT(workerNameChanged(QString,int)));

        connect(stockpileInformationWidget->getScrollArea()->getWidget(index)->getStockpileLineEdit(),
                SIGNAL(editingFinished()), stockpileInformationWidget->getScrollArea()->getWidget(index), SLOT(stockpileLineEditDataChanged()));
        connect(stockpileInformationWidget->getScrollArea()->getWidget(index),
                SIGNAL(stockpileChanged(int,int)), this, SLOT(workerStockpileChanged(int,int)));

        index++;
        querySize--;
    } while(stockpileQuery.next());
}

void MainWindow::makeProductInformationLayout(int productClickedId) {
    currentProductId = productClickedId;

    QSqlQuery productQuery;
    productQuery.exec("select * from products where PRODUCT_ID = " +
                                                          QString::number(productClickedId) + ";");
    productQuery.first();

    productInformationWidget->setInformation(productQuery.value(productDB::PRODUCT_ID).toInt(),
                                             productQuery.value(productDB::PRODUCT_NAME).toString(),
                                             productQuery.value(productDB::PRODUCT_WEIGHT).toInt(),
                                             productQuery.value(productDB::PRODICT_COST).toInt(),
                                             productQuery.value(productDB::PRODUCT_COUNT).toInt(),
                                             productQuery.value(productDB::SUPPLIER_ID).toInt(),
                                             productQuery.value(productDB::STOCKPILE_ID).toInt());
}

void MainWindow::clearLayout(QLayout *layout) {
    if (layout == NULL)
        return;
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
           delete item->widget();
        }
        delete item;
    }
}
