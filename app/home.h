#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <QtSql>
#include "Entities/customer.h"
#include "GeneralManagers/addressmanager.h"

namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = nullptr);
    ~Home();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::Home *ui;
    AddressManager addressmanager;
    void AddSearchSuggestions(QString fullName);
    void FetchCustomer(QString fullName);
    void SetCustomerOnHome(Customer customer);
};

#endif // HOME_H
