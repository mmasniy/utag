#include <iomanip>
#include <string>
#include <iostream>
#include <dirent.h>

#include "src/mainwindow.h"

#include <QApplication>
int main( int argc, char **argv ) {
    QApplication app(argc, argv);
    MainWindow window((QString(argv[1])));
    window.show();
    return app.exec();
}

