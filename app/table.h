#ifndef TABLE_H
#define TABLE_H

#include <QWidget>
#include <QtSql>
#include <QTableView>

namespace Ui {
class Table;
}

class Table : public QWidget
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = nullptr);
    ~Table();

private slots:
    void on_refreshButton_clicked();

private:
    Ui::Table *ui;
    void createRelationalTables();
    void initializeModel(QSqlRelationalTableModel *model);
    QTableView *table;
    QSqlRelationalTableModel model;
};

#endif // TABLE_H
