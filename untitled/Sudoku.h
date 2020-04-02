#ifndef SUDOKU_H
#define SUDOKU_H
#include <iostream>
#include <vector>
using namespace std;

class Sudoku
{
public:
    Sudoku();
    Sudoku(const int init_map[]);
    bool isCorrect();
    bool questionCorrect();
    void solve();
    void print();
    static const int sudokuSize = 81;
    void cross();
    void cell_Index();

private:
     bool checkUnity(int arr[]);
     int toSolve;
     int map[sudokuSize];
     int road[sudokuSize][21];

     int cellIndex[sudokuSize];
  //   vector<int>
};

#endif // SODOKU_H
