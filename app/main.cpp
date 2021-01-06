#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <memory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if (!createConnection())
        return EXIT_FAILURE;

    MainWindow w;
    w.show();

    return a.exec();
}
