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

private:
    Ui::Table *ui;
    void createRelationalTables();
    void initializeModel(QSqlRelationalTableModel *model);
    std::unique_ptr<QTableView> createView(const QString &title, QSqlTableModel *model);
};

#endif // TABLE_H
