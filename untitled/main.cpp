#include "mainwindow.h"
#include "Sudoku.h"
#include <QApplication>
#include <QLabel>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel label;
    label.setText("這是標籤2");
    label.show();
    MainWindow w;
    w.show();

    /*int map[81] = {0,1,4,7,0,0,0,0,0,
                   0,0,0,0,2,6,0,9,0,
                   0,0,0,3,4,0,7,0,5,

                   8,0,0,0,0,0,9,7,0,
                   0,2,0,9,3,8,0,6,0,
                   0,9,6,0,0,0,0,0,3,

                   6,0,2,0,9,1,0,0,0,
                   0,4,0,6,5,0,0,0,0,
                   0,0,0,0,0,3,2,4,0
                  };*/
    int map[81] = {5,3,4,6,7,8,9,1,2,
                   6,7,2,1,9,5,3,4,8,
                   0,9,8,3,0,2,5,6,0,

                   8,5,9,7,6,1,4,2,3,
                   4,0,6,8,0,3,7,9,0,
                   7,1,3,9,2,4,8,5,6,

                   9,6,0,5,3,7,0,8,4,
                   2,8,7,4,1,9,6,3,5,
                   3,4,5,2,0,6,1,7,9,
                   };
    Sudoku j(map);
    j.solve();
    cout<<"gg"<<endl;
    j.print();

    cout<<"gg"<<endl;
    return a.exec();
}
