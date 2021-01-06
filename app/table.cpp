#include "table.h"
#include "ui_table.h"
#include <QTableView>
#include "connection.h"
#include <QLayoutItem>
Table::Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);

    createRelationalTables();

    initializeModel(&model);

    // Call refresh once to get table
    on_refreshButton_clicked();
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
    query.exec("create table customer(id int primary key, firstname varchar(20), lastname varchar(20), phonenumber varchar(20), address int)");
    query.exec("insert into customer values(1, 'Espen', 'LastName1', '+331222345', 1)");
    query.exec("insert into customer values(2, 'Harald', 'LastName2', '+33433321', 2)");
    query.exec("insert into customer values(3, 'Sam', 'LastName3', '+339090909', 3)");

    query.exec("create table address(id int, country varchar(20), streetname varchar(20))");
    query.exec("insert into address values(1, 'Germany', 'Rue allemagne')");
    query.exec("insert into address values(2, 'France', 'Rue france')");
    query.exec("insert into address values(3, 'Italy', 'Rue italie')");

}

void Table::on_refreshButton_clicked()
{
    ui->tableView->setModel(&model);
    ui->tableView->hideColumn(0);
}

void Table::on_comboBox_currentIndexChanged(int index)
{
    switch (index)
    {

    case 0:
        a();
        break;
    case 2:
        b();
        d();
        [[fallthrough]]; // I meant to do this!
    case 3:
        c();
        break;
    default:
        d();
        break;
    }
}
