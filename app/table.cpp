#include "table.h"
#include "ui_table.h"
#include <QTableView>
#include "connection.h"

Table::Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);

    createRelationalTables();

    QSqlRelationalTableModel model;

    initializeModel(&model);

    std::unique_ptr<QTableView> view = createView(QObject::tr("Relational Table Model"), &model);

    view->show();
}

Table::~Table()
{
    delete ui;
}


void Table::initializeModel(QSqlRelationalTableModel *model)
{
//! [0]
    model->setTable("customer");
//! [0]

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//! [1]
    model->setRelation(4, QSqlRelation("address", "id", "country"));
    model->setRelation(5, QSqlRelation("address", "id", "streetname"));

//! [1]

//! [2]
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("First name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Last name"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Phone number"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Country"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Address"));
//! [2]

    model->select();
}

void Table::createRelationalTables()
{
    QSqlQuery query;
    query.exec("create table employee(id int primary key, firstname varchar(20), lastname varchar(20), phonenumber varchar(20),"
               " address int)");
    query.exec("insert into employee values(1, 'Espen', 'LastName1', '+331222345', 1)");
    query.exec("insert into employee values(2, 'Harald', 'LastName2', '+33433321', 2)");
    query.exec("insert into employee values(3, 'Sam', 'LastName3', '+339090909', 3)");

    query.exec("create table address(id int, country varchar(20), streetname varchar(20))");
    query.exec("insert into city values(1, 'Germany', 'Rue allemagne')");
    query.exec("insert into city values(2, 'France', 'Rue france')");
    query.exec("insert into city values(3, 'Italy', 'Rue italie')");
}


std::unique_ptr<QTableView> Table::createView(const QString &title, QSqlTableModel *model)
{
//! [4]
    std::unique_ptr<QTableView> view{new QTableView};
    view->setModel(model);
    view->setItemDelegate(new QSqlRelationalDelegate(view.get()));
//! [4]
    view->setWindowTitle(title);
    return view;
}
