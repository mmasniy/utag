#include <iomanip>
#include <string>
#include <iostream>
#include <dirent.h>

#include "src/Application.h"
#include <QApplication>
#include <QLabel>
int main( int argc, char **argv )
{
    QApplication a( argc, argv );
    QLabel label("Привет");
//    QPushButton hello( "Hello world!", 0 );
//    hello.resize( 100, 30 );

//    a.setMainWidget( &hello );
//    hello.show();
    label.show();
    return a.exec();
}

//int main(int argc, char *argv[]) {
//    if (argc != 2) {
//        std::cerr << "usage: ./utag [dir name]\n";
//    }
//    DIR *d;
//    struct dirent *dr;
//    Application application;
//    if ((d = opendir(argv[1])) == 0) {
//        std::cerr << "Не могу открыть " << argv[1] << "\n";
//    }
//    FileTags file1("/Users/mmasniy/Desktop/utag/data/", "ape-id3v1.mp3");
//    while ((dr = readdir(d)) != 0) {
//        if (dr->d_name[0] == '.') {
//            continue;
//        }
//        FileTags file(std::string(argv[1]) + "/", std::string(dr->d_name));
//        application.setFileToInfo(file);
//        application.printInfo();
//        file.upgradeFileTags(file1);
//        std::cout << file;
//    }
////    application.printInfo();
//    return 0;
//}

