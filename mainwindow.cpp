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
    QFile* styleSheetFile = new QFile("style_sheet.css");
    styleSheetFile->open(QIODevice::ReadOnly);
    QString style = styleSheetFile->readAll();

    makeConnection();
    // makeTest();

    stockpileScrollArea = new StockpileScrollArea();
    stockpileTitle = new QLabel("Список складов");
    stockpileTitle->setObjectName("stockpile-title");
    addNewStockpileButton = new QPushButton("Добавить новый склад");
    connect(addNewStockpileButton, SIGNAL(clicked()), this, SLOT(addStockpile()));
    addNewStockpileButton->setObjectName("addNewStockpileButton");

    stockpileLayout = new QVBoxLayout();
    stockpileLayout->addWidget(stockpileTitle);
    stockpileLayout->addWidget(stockpileScrollArea);
    stockpileLayout->addWidget(addNewStockpileButton);

    productScrollArea = new ProductScrollArea();
    productTitle = new QLabel("Список продуктов");
    productTitle->setObjectName("product-title");
    addNewProductButton = new QPushButton("Добавить новый продукт");
    addNewProductButton->setEnabled(0);
    connect(addNewProductButton, SIGNAL(clicked()), this, SLOT(addProduct()));

    productLayout = new QVBoxLayout();
    productLayout->addWidget(productTitle);
    productLayout->addWidget(productScrollArea);
    productLayout->addWidget(addNewProductButton);

    stockpileInformationWidget = new StockpileInformation();
    productInformationWidget = new ProductInformationWidget();
    informationTitle = new QLabel("Информация");
    informationTitle->setObjectName("information-title");

    deleteStockpileButton = new QPushButton("Удалить склад");
    connect(deleteStockpileButton, SIGNAL(clicked()), this, SLOT(deleteStockpile()));
    deleteProductButton = new QPushButton("Удалить продукт");
    connect(deleteProductButton, SIGNAL(clicked()), this, SLOT(deleteProduct()));

    informationLayout = new QVBoxLayout();
    informationLayout->addWidget(informationTitle);
    informationLayout->addWidget(stockpileInformationWidget);
    informationLayout->addWidget(deleteStockpileButton);
    informationLayout->addWidget(productInformationWidget);
    informationLayout->addWidget(deleteProductButton);

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

    connect(stockpileInformationWidget->getNameWidget(), SIGNAL(editingFinished()), this, SLOT(stockpileNameChanged()));
    connect(stockpileInformationWidget->getCapacityWidget(), SIGNAL(editingFinished()), this, SLOT(stockpileCapacityChanged()));
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

    connect(productInformationWidget->getProductName(), SIGNAL(editingFinished()),
            productInformationWidget, SLOT(nameLineEditDataChanged()));
    connect(productInformationWidget, SIGNAL(nameChanged(QString,int)),
            this, SLOT(productNameChanged(QString,int)));

    connect(productInformationWidget->getProductWeight(), SIGNAL(editingFinished()),
            productInformationWidget, SLOT(weightLineEditDataChanged()));
    connect(productInformationWidget, SIGNAL(weightChanged(double,int)),
            this, SLOT(productWeightChanged(double,int)));

    connect(productInformationWidget->getProductCost(), SIGNAL(editingFinished()),
            productInformationWidget, SLOT(costLineEditDataChanged()));
    connect(productInformationWidget, SIGNAL(costChanged(int,int)),
            this, SLOT(productCostChanged(int,int)));

    connect(productInformationWidget->getProductCount(), SIGNAL(editingFinished()),
            productInformationWidget, SLOT(countLineEditDataChanged()));
    connect(productInformationWidget, SIGNAL(countChanged(int,int)),
            this, SLOT(productCountChanged(int,int)));

    connect(productInformationWidget->getProductSupplierId(), SIGNAL(editingFinished()),
            productInformationWidget, SLOT(supplierIdLineEditDataChanged()));
    connect(productInformationWidget, SIGNAL(supplierIdChanged(int,int)),
            this, SLOT(productSupplierIdChanged(int,int)));

    connect(productInformationWidget->getProductStockpileId(), SIGNAL(editingFinished()),
            productInformationWidget, SLOT(stockpileIdLineEditDataChanged()));
    connect(productInformationWidget, SIGNAL(stockpileIdChanged(int,int)),
            this, SLOT(productStockpileIdChanged(int,int)));
}

void MainWindow::makeConnection() {
    db = QSqlDatabase::addDatabase("QODBC");

    db.setConnectOptions();

    db.setDatabaseName("DRIVER={SQL Server}; SERVER=MATEBOOK\\SQLEXPRESS; DATABASE=Employees; Trusted_Connection=Yes");
    db.setUserName("nick");
    db.setPassword("12345678");

    if (!db.open()){
        qDebug() << db.lastError();
        exit(1);
    }
}

void MainWindow::makeTest() {
    QSqlQuery beginQuery;
    beginQuery.exec("DELETE FROM products");
    beginQuery.exec("DELETE FROM employees");
    beginQuery.exec("DELETE FROM suppliers");
    beginQuery.exec("DELETE FROM stockpiles");

    for(int i = 0; i < 1000; i++) {
        QSqlQuery query;
        QString queryCode = QString("INSERT INTO products(PRODUCT_ID, PRODUCT_NAME, PRODUCT_WEIGHT, PRODICT_COST, PRODUCT_COUNT, SUPPLIER_ID, STOCKPILE_ID) VALUES (%1, '%2', %3, %4, %5, %6, %7);")
                .arg(QString::number(i), wordGenerate(), QString::number(static_cast<double>(QRandomGenerator::global()->bounded(0, 100))/10),
                     QString::number(QRandomGenerator::global()->bounded(1, 10000)),
                     QString::number(QRandomGenerator::global()->bounded(1, 1000)),
                     QString::number(QRandomGenerator::global()->bounded(0, 20)), QString::number(QRandomGenerator::global()->bounded(0, 4)));

        query.exec(queryCode);
    }

    for(int i = 0; i < 20; i++) {
        QSqlQuery query;
        QString queryCode = QString("INSERT INTO employees(EMPLOYEE_ID, EMPLOYEE_NAME, STOCKPILE_ID) VALUES (%1, '%2', %3);")
                .arg(QString::number(i), wordGenerate() + "bek", QString::number(QRandomGenerator::global()->bounded(0, 4)));

        query.exec(queryCode);
    }

    for(int i = 0; i < 4; i++) {
        QSqlQuery query;
        QString queryCode = QString("INSERT INTO suppliers(SUPPLIER_ID, SUPPLIER_NAME) VALUES (%1, '%2');")
                .arg(QString::number(i), wordGenerate() + "zud");

        query.exec(queryCode);
    }

    for(int i = 0; i < 4; i++) {
        QSqlQuery query;

        QSqlQuery tmpQuery;
        tmpQuery.prepare(QString("select SUM(PRODUCT_COUNT) from products where STOCKPILE_ID = " + QString::number(i) + ";"));
        tmpQuery.exec(); tmpQuery.first();

        int productCount = tmpQuery.value(0).toInt();
        int maxSpace = QRandomGenerator::global()->bounded(productCount, productCount * 2);

        QString queryCode = QString("INSERT INTO stockpiles(STOCKPILE_ID, STOCKPILE_NAME, STOCKPILE_PRODUCTS_COUNT, STOCKPILE_CAPACITY, STOCKPILE_SPACE_REMAINING) VALUES (%1, '%2', %3, %4, %5);")
                .arg(QString::number(i), wordGenerate() + "ovo", QString::number(productCount),
                     QString::number(maxSpace), QString::number(maxSpace - productCount));

        query.exec(queryCode);
    }
}

QString MainWindow::wordGenerate() {
    QString vowels = "eyuioa";
    QString consonant = "qwrtpsdfghjklzxcvbnm";
    QString result = "";
    for(int i = QRandomGenerator::global()->bounded(2, 5); i > 0; i--) {
        result += consonant[QRandomGenerator::global()->bounded(0, 20)];
        result += vowels[QRandomGenerator::global()->bounded(0, 5)];
    }

    return result;
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

//----------------------------SLOTS-------------------------//

void MainWindow::stockpileButtonClicked(int getId) {
    makeStockpileInformationLayout(getId);
    makeProductLayout(getId);
}

void MainWindow::productButtonClicked(int getId) {
    makeProductInformationLayout(getId);
}

void MainWindow::stockpileNameChanged() {
    stockpileScrollArea->getWidget(currentStockpileId)->setStockpileName(stockpileInformationWidget->getNameWidget()->text());

    QString queryText = QString("UPDATE stockpiles set STOCKPILE_NAME = '%1' where STOCKPILE_ID = %2").arg(stockpileInformationWidget->getNameWidget()->text(), QString::number(currentStockpileId));
    QSqlQuery query;
    query.exec(queryText);
}
void MainWindow::stockpileCapacityChanged() {
    stockpileScrollArea->getWidget(currentStockpileId)->setStockpileCapacity(stockpileInformationWidget->getCapacityWidget()->text().toInt());

    QString queryText = QString("UPDATE stockpiles set STOCKPILE_CAPACITY = '%1' where STOCKPILE_ID = %2").arg(stockpileInformationWidget->getCapacityWidget()->text(), currentStockpileId);
    QSqlQuery query;
    query.exec(queryText);
}

void MainWindow::addStockpile() {
    QSqlQuery query;
    query.exec("select * from stockpiles");
    stockpileScrollArea->addStockpile(1, 0, 1, query.numRowsAffected(), "new stockpile");
    QString queryText = QString("INSERT INTO stockpiles(STOCKPILE_ID, STOCKPILE_NAME, STOCKPILE_PRODUCTS_COUNT, STOCKPILE_CAPACITY, STOCKPILE_SPACE_REMAINING) VALUES (%1, '%2', %3, %4, %5);")
            .arg(QString::number(query.numRowsAffected()), "new stockpile", QString::number(0), QString::number(1), QString::number(1));
    query.exec(queryText);
    connect(stockpileScrollArea->getWidget(stockpileScrollArea->getSize() - 1)->getOutputButton(), SIGNAL(clicked()),
            stockpileScrollArea->getWidget(stockpileScrollArea->getSize() - 1), SLOT(stockpileButtonClickedToId()));
    connect(stockpileScrollArea->getWidget(stockpileScrollArea->getSize() - 1), SIGNAL(stockpileButtonIdReturn(int)),
            this, SLOT(stockpileButtonClicked(int)));
}
void MainWindow::addProduct() {
    QSqlQuery query;
    query.exec("select * from products");
    productScrollArea->addProduct(query.numRowsAffected(), "new product", 1);
    QString queryText = QString("INSERT INTO products(PRODUCT_ID, PRODUCT_NAME, PRODUCT_WEIGHT, PRODICT_COST, PRODUCT_COUNT, SUPPLIER_ID, STOCKPILE_ID)"
                " VALUES (%1, '%2', %3, %4, %5, %6, %7);").arg(QString::number(query.numRowsAffected()),
                                                               "new product", "0.0", "0", "0", "0", "0");
    query.exec(queryText);
    connect(productScrollArea->getWidget(productScrollArea->getSize() - 1)->getOutputButton(), SIGNAL(clicked()),
            productScrollArea->getWidget(productScrollArea->getSize() - 1), SLOT(productButtonClickedToId()));
    connect(productScrollArea->getWidget(productScrollArea->getSize() - 1), SIGNAL(productButtonIdReturn(int)),
            this, SLOT(productButtonClicked(int)));
}

void MainWindow::deleteStockpile() {
    if(currentStockpileId == -1) {
        return;
    }

    stockpileScrollArea->removeStockpile(currentStockpileId);
    QSqlQuery query;
    QString queryText = QString("delete from stockpiles where STOCKPILE_ID = " + QString::number(currentStockpileId) + ";");
    query.exec(queryText);

    if(stockpileScrollArea->getWidget(0) == nullptr) {
        return;
    }

    makeStockpileInformationLayout(stockpileScrollArea->getWidget(0)->getStockpileId());
    makeProductLayout(stockpileScrollArea->getWidget(0)->getStockpileId());
}
void MainWindow::deleteProduct() {
    if(currentProductId == -1) {
        return;
    }

    productScrollArea->removeProduct(currentProductId);
    QSqlQuery query;
    QString queryText = QString("delete from products where PRODUCT_ID = " + QString::number(currentProductId) + ";");
    query.exec(queryText);

    if(productScrollArea->getWidget(0) == nullptr) {
        return;
    }

    makeProductInformationLayout(productScrollArea->getWidget(0)->getProductId());
}

void MainWindow::workerNameChanged(QString setName, int setId) {
    QSqlQuery query;
    query.exec("update employees set EMPLOYEE_NAME = '" + setName + "' where PRODUCT_ID = " + QString::number(setId) + ";");
}
void MainWindow::workerStockpileChanged(int setStockpileId, int setId) {
    QSqlQuery query;
    query.exec("update employees set STOCKPILE_ID = " + QString::number(setStockpileId) + " where PRODUCT_ID = " + QString::number(setId) + ";");
}

void MainWindow::productNameChanged(QString setName, int setId) {
    QSqlQuery query;
    query.exec("update products set PRODUCT_NAME = '" + setName + "' where PRODUCT_ID = " + QString::number(setId) + ";");
    qDebug() << query.lastError();
}
void MainWindow::productWeightChanged(double setWeight, int setId) {
    QSqlQuery query;
    query.exec("update products set PRODUCT_WEIGHT = " + QString::number(setWeight) + " where PRODUCT_ID = " + QString::number(setId) + ";");
    qDebug() << query.lastError();
}
void MainWindow::productCostChanged(int setCost, int setId){
    QSqlQuery query;
    query.exec("update products set PRODICT_COST = " + QString::number(setCost) + " where PRODUCT_ID = " + QString::number(setId) + ";");
    qDebug() << query.lastError();
}
void MainWindow::productCountChanged(int setCount, int setId){
    QSqlQuery query;
    query.exec("update products set PRODUCT_COUNT = " + QString::number(setCount) + " where PRODUCT_ID = " + QString::number(setId) + ";");
    qDebug() << query.lastError();
}
void MainWindow::productSupplierIdChanged(int setSupplierId, int setId){
    QSqlQuery query;
    query.exec("update products set SUPPLIER_ID = " + QString::number(setSupplierId) + " where PRODUCT_ID = " + QString::number(setId) + ";");
    qDebug() << query.lastError();
}
void MainWindow::productStockpileIdChanged(int setStockpileId, int setId){
    QSqlQuery query;
    query.exec("update products set STOCKPILE_ID = " + QString::number(setStockpileId) + " where PRODUCT_ID = " + QString::number(setId) + ";");
    qDebug() << query.lastError();
}
