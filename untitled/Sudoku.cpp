#include "Sudoku.h"


Sudoku::Sudoku()
{
    for(int i = 0;i<sudokuSize;++i)
        map[i]=0;
}
Sudoku::Sudoku(const int init_map[])
{
    for(int i = 0;i<sudokuSize;++i)
        map[i]=init_map[i];
    for(int i = 0;i<sudokuSize;++i)
    {
        if(map[i]!=0)
            ++toSolve;
    }
    print();
    cross();
    cell_Index();
    questionCorrect();
}
bool Sudoku::questionCorrect()
{
    int check[9];
    bool TF = true;
    int j = 0,number = 0;
    for(int i = 0;i<sudokuSize;i = i + 9) //row
    {
        j = 0;
        number = 0;
        for(int g = 0;g<9;++g)
            check[g] = 0;
        j = i;
        for(int k = 0;k<9;++k)
        {
            number = map[j+k] -1;
            check[number] = check[number] +1;
        }
        for(int  a = 0;a<9;++a)
        {
            if(check[a] >= 2)
                TF = false;
        }
    }
    for(int i = 0;i<9;++i) //colum
    {
        for(int g = 0;g<9;++g)
             check[g] = 0;
        for(int k = 0;k<9;++k)
        {
            number = map[9*k+i]-1;
            check[number] = check[number] + 1;
        }
        for(int  a = 0;a<9;++a)
        {
            if(check[a] >= 2)
                TF = false;
        }
    }
    int Ind[9] = {0,3,6,27,30,33,54,57,60};
    for(int i = 0;i<9;++i) //cell
    {
        for(int g = 0;g<9;++g)
             check[g] = 0;
        check[map[Ind[i]]-1] = check[map[Ind[i]]-1] +1;
        check[map[Ind[i]+1]-1] = check[map[Ind[i]+1]-1] +1;
        check[map[Ind[i]+2]-1] = check[map[Ind[i]+2]-1] +1;
        check[map[Ind[i]+9]-1] = check[map[Ind[i]+9]-1] +1;
        check[map[Ind[i]+10]-1] = check[map[Ind[i]+10]-1] +1;
        check[map[Ind[i]+11]-1] = check[map[Ind[i]+11]-1] +1;
        check[map[Ind[i]+18]-1] = check[map[Ind[i]+18]-1] +1;
        check[map[Ind[i]+19]-1] = check[map[Ind[i]+19]-1] +1;
        check[map[Ind[i]+20]-1] =  check[map[Ind[i]+20]-1] +1;
        for(int  k = 0;k<9;++k)
        {
            if(check[k] >= 2)
                TF = false;
        }
    }
    if(!TF)
        cout<<"booboo"<<endl;
}
void Sudoku::solve()
{
    int possible[sudokuSize];//map[index] have how many possible;
    int check[9];//[index][0,1,1,1,1,1,1,1,1]
    int what=0,index=0,number = 0,changeindex = 0,count,dd;






    const int Ind[9] = {0,3,6,27,30,33,54,57,60};
    const int Add[9] = {0,1,2,9,10,11,18,19,20};
    for(int i =0;i<9;++i)
    {
        number = 0;
        count = 0;
        what = 0;
        changeindex = 0;
        for(int g = 0;g<9;++g)
            check[g] = 0;

        for(int k = 0;k<9;++k)
        {
            number = map[Ind[i]+Add[k]] -1;
            check[number] = check[number] +1;
            number = map[Ind[i]+Add[k]] -1;
            if(number == -1)
                changeindex = k;
        }

        for (int k = 0;k<9;++k)
        {
            if(check[k]==1)
            {
                ++count;
            }else
            {
                what = k+1;
            }
        }
        if(count == 8)
        {
            map[Ind[i]+Add[changeindex]] = what;
            ++toSolve;
        }



    }


    for(int i = 0;i<sudokuSize;i = i + 9) //row
    {

        number = 0;
        count = 0;
        what = 0;
        changeindex = 0;
        for(int g = 0;g<9;++g)
            check[g] = 0;

        for(int k = 0;k<9;++k)
        {
            number = map[i+k] -1;
            check[number] = check[number] +1;
            number = map[i+k] -1;
            if(number == -1)
                changeindex = k;
        }

        for (int k = 0;k<9;++k)
        {
            if(check[k]==1)
            {
                ++count;
            }else
            {
                what = k+1;
            }
        }
        if(count == 8)
        {
            map[i+changeindex] = what;
            ++toSolve;
        }

    }

    for(int i = 0;i<9;i = i + 1) //colum
    {

        number = 0;
        count = 0;
        what = 0;
        changeindex = 0;
        for(int g = 0;g<9;++g)
            check[g] = 0;

        for(int k = 0;k<9;++k)
        {
            number = map[i+k*9] -1;
            check[number] = check[number] +1;
            number = map[i+k*9] -1;
            if(number == -1)
                changeindex = k;
        }

        for (int k = 0;k<9;++k)
        {
            if(check[k]==1)
            {
                ++count;
            }else
            {
                what = k+1;
            }
        }
        if(count == 8)
        {
            map[i+changeindex*9] = what;
            ++toSolve;
        }

    }







}

bool Sudoku::checkUnity(int arr[])
{
    int arr_unity[9];

    for(int i = 0;i<9;++i)
        arr_unity[i] = 0;
    for(int i = 0;i<9;++i)
        ++arr_unity[arr[i]-1];
    for(int i = 0;i<9;++i)
        if(arr_unity[i]!=1)
            return false;
    return true;
}
void Sudoku::print()
{
    for(int i = 0;i<81;++i)
    {
        cout<<map[i]<<" ";
        if(i%9==8)
            cout<<endl;
    }

}
bool Sudoku::isCorrect()
{
    bool check_result;
    int check_arr[9];
    int location;
    for(int i = 0;i < 81 ;i +=9)//check rows
    {
        for(int j = 0;j < 9;++j)
            check_arr[j] = map[i+j];
        check_result = checkUnity(check_arr);
        if(check_result == false)
            return false;
    }
    for(int i = 0;i<9;++i)//check col
    {
        for(int j = 0;j<9;++j)
            check_arr[j] = map[i+9*j];
        check_result = checkUnity(check_arr);
        if(check_result == false)
            return false;
    }
    for(int i =0;i<9;++i)
    {
        for(int j=0;j<9;++j)
        {
            location = 27*(i/3) + 3*(i%3)+9*(j/3)+(j%3);
            check_arr[j] = map[location];
        }
        check_result = checkUnity(check_arr);
        if(check_result == false)
            return false;
     }
    return true;
}
void Sudoku::cell_Index()
{
    for(int i = 0;i<sudokuSize;++i)
    {
        if((i/9)%3==0)
        {
            if(i%3==0)
                cellIndex[i] = 0;
            else if(i%3==1)
                cellIndex[i] = 1;
            else if(i%3==2)
                cellIndex[i] = 2;
        }else if((i/9)%3==1)
        {
            if(i%3==0)
                cellIndex[i] = 3;
            else if(i%3==1)
                cellIndex[i] = 4;
            else if(i%3==2)
                cellIndex[i] = 5;
        }else if((i/9)%3==2)
        {
            if(i%3==0)
                cellIndex[i] = 6;
            else if(i%3==1)
                cellIndex[i] = 7;
            else if(i%3==2)
                cellIndex[i] = 8;
        }
    }

}
void Sudoku::cross()
{
    for(int index = 0;index<sudokuSize;++index)
    {
        if(index % 9 == 0)
        {
            for(int i =0;i<9;++i)
                road[index][i]= index + i;
            for(int i =0;i<9;++i)
            {
                road[index][i+9]=i*9;

            }
            if((index/9)%3==0)
            {
                road[index][18] = index + 10;
                road[index][19] = index + 11;
                road[index][20] = index + 19;
                road[index][index%9] = index + 20;
            }else if ((index/9)%3==1)
            {
                road[index][18] = index - 8;
                road[index][19] = index - 7;
                road[index][20] = index + 10;
                road[index][index%9] = index + 11;
            }else if ((index/9)%3==2)
            {
                road[index][18] = index - 17;
                road[index][19] = index - 16;
                road[index][20] = index - 8;
                road[index][index%9] = index - 7;
            }
        }
        else if(index % 9 == 1)
        {
            for(int i =0;i<9;++i)
                road[index][i]= ((index/9)*9) + i;
            for(int i =0;i<9;++i)
                road[index][i+9]=i*9+1;
            if((index/9)%3==0)
            {
                road[index][18] = index + 8;
                road[index][19] = index + 10;
                road[index][20] = index + 17;
                road[index][index%9] = index + 19;
            }else if ((index/9)%3==1)
            {
                road[index][18] = index - 10;
                road[index][19] = index - 8;
                road[index][20] = index + 8;
                road[index][index%9] = index + 10;
            }else if ((index/9)%3==2)
            {
                road[index][18] = index - 19;
                road[index][19] = index - 17;
                road[index][20] = index - 10;
                road[index][index%9] = index + 1;
            }
        }
        else if(index % 9 == 2)
        {
                for(int i =0;i<9;++i)
                    road[index][i]= ((index/9)*9) + i;
                for(int i =0;i<9;++i)
                    road[index][i+9]=i*9+2;
                if((index/9)%3==0)
                {
                    road[index][18] = index + 7;
                    road[index][19] = index + 8;
                    road[index][20] = index + 16;
                    road[index][index%9] = index + 17;
                }else if ((index/9)%3==1)
                {
                    road[index][18] = index - 11;
                    road[index][19] = index - 10;
                    road[index][20] = index + 7;
                    road[index][index%9] = index + 8;
                }else if ((index/9)%3==2)
                {
                    road[index][18] = index - 20;
                    road[index][19] = index - 19;
                    road[index][20] = index - 11;
                    road[index][index%9] = index - 10;
                }
        }
        else if(index % 9 == 3)
        {
            for(int i =0;i<9;++i)
                road[index][i]= ((index/9)*9) + i;
            for(int i =0;i<9;++i)
                road[index][i+9]=i*9+3;
            if((index/9)%3==0)
            {
                road[index][18] = index + 10;
                road[index][19] = index + 11;
                road[index][20] = index + 19;
                road[index][index%9] = index + 20;
            }
            else if ((index/9)%3==1)
            {
                road[index][18] = index - 8;
                road[index][19] = index - 7;
                road[index][20] = index + 10;
                road[index][index%9] = index + 11;
            }else if ((index/9)%3==2)
            {
                road[index][18] = index - 17;
                road[index][19] = index - 16;
                road[index][20] = index - 8;
                road[index][index%9] = index - 7;
            }
        }
        else if(index % 9 == 4)
        {
                for(int i =0;i<9;++i)
                    road[index][i]= ((index/9)*9) + i;
                for(int i =0;i<9;++i)
                    road[index][i+9]=i*9+4;
                if((index/9)%3==0)
                {
                    road[index][18] = index + 8;
                    road[index][19] = index + 10;
                    road[index][20] = index + 17;
                    road[index][index%9] = index + 19;
                }else if ((index/9)%3==1)
                {
                    road[index][18] = index - 10;
                    road[index][19] = index - 8;
                    road[index][20] = index + 8;
                    road[index][index%9] = index + 10;
                }else if ((index/9)%3==2)
                {
                    road[index][18] = index - 19;
                    road[index][19] = index - 17;
                    road[index][20] = index - 10;
                    road[index][index%9] = index - 8;
                }
        }
        else if(index % 9 == 5)
        {
                for(int i =0;i<9;++i)
                    road[index][i]= ((index/9)*9) + i;
                for(int i =0;i<9;++i)
                    road[index][i+9]=i*9+5;
                if((index/9)%3==0)
                {
                    road[index][18] = index + 7;
                    road[index][19] = index + 8;
                    road[index][20] = index + 16;
                    road[index][index%9] = index + 17;
                }else if ((index/9)%3==1)
                {
                    road[index][18] = index - 11;
                    road[index][19] = index - 10;
                    road[index][20] = index + 7;
                    road[index][index%9] = index + 8;
                }else if ((index/9)%3==2)
                {
                    road[index][18] = index - 20;
                    road[index][19] = index - 19;
                    road[index][20] = index - 11;
                    road[index][index%9] = index - 10;
                }
        }
        else if(index % 9 == 6)
        {
                for(int i =0;i<9;++i)
                    road[index][i]= ((index/9)*9) + i;
                for(int i =0;i<9;++i)
                    road[index][i+9]=i*9+6;
                if((index/9)%3==0)
                {
                    road[index][18] = index + 10;
                    road[index][19] = index + 11;
                    road[index][20] = index + 19;
                    road[index][index%9] = index + 20;
                }else if ((index/9)%3==1)
                {
                    road[index][18] = index - 8;
                    road[index][19] = index - 7;
                    road[index][20] = index + 10;
                    road[index][index%9] = index + 11;
                }else if ((index/9)%3==2)
                {
                    road[index][18] = index - 17;
                    road[index][19] = index - 16;
                    road[index][20] = index - 8;
                    road[index][index%9] = index - 7;
                }
        }
        else if(index % 9 == 7)
        {
                for(int i =0;i<9;++i)
                    road[index][i]= ((index/9)*9) + i;
                for(int i =0;i<9;++i)
                    road[index][i+9]=i*9+7;
                if((index/9)%3==0)
                {
                    road[index][18] = index + 8;
                    road[index][19] = index + 10;
                    road[index][20] = index + 17;
                    road[index][index%9] = index + 19;
                }else if ((index/9)%3==1)
                {
                    road[index][18] = index - 10;
                    road[index][19] = index - 8;
                    road[index][20] = index + 8;
                    road[index][index%9] = index + 10;
                }else if ((index/9)%3==2)
                {
                    road[index][18] = index - 19;
                    road[index][19] = index - 17;
                    road[index][20] = index - 10;
                    road[index][index%9] = index - 8;
                }
        }
        else if(index % 9 == 8)
    {
            for(int i =0;i<9;++i)
                road[index][i]= ((index/9)*9) + i;
            for(int i =0;i<9;++i)
                road[index][i+9]=i*9+8;
            if((index/9)%3==0)
            {
                road[index][18] = index + 7;
                road[index][19] = index + 8;
                road[index][20] = index + 16;
                road[index][index%9] = index + 17;
            }else if ((index/9)%3==1)
            {
                road[index][18] = index - 11;
                road[index][19] = index - 10;
                road[index][20] = index + 7;
                road[index][index%9] = index + 8;
            }else if ((index/9)%3==2)
            {
                road[index][18] = index - 20;
                road[index][19] = index - 19;
                road[index][20] = index - 11;
                road[index][index%9] = index - 10;
            }
    }
    }
/*for(int i =0;i<81;++i)
{
    cout<<i<<": ";
    for(int j = 0;j<21;++j)
        cout<<road[i][j]<<" ";
    cout<<endl;
}*/

}




/*    for(int i = 0;i<sudokuSize;++i)
        possible[i] = 0;
    for(int i = 0;i<sudokuSize;++i)
    {
        for(int j = 0;j<=10;++j)
            check[i][j] = 0;
        possible[i] = 0;
        if(map[i] == 0)
        {

            for(int j = 0;j<10;++j)
            {
                index = road[i][j];
                number = map[index];
                ++check[i][number];//check[index][0,1,2,1,,2,1,1,]
            }
            for(int k = 1;k<=9;++k)
            {
                if(check[i][k] == 0)
                    ++possible[i];//[0,0,0,0,0,0,0,0,0,0,] =>9
            }
        }
        else
        {
            possible[i] = 0;
        }
    }

    while(toSolve != sudokuSize)
    {
         for(int i = 0;i<sudokuSize;++i)
         {
            if(possible[i] == 1)
            {
                for(int j = 1;j<=9;++j)
                {
                    if(check[i][j]==0)
                         what = j;
                }
                map[i] = what;
                ++toSolve;
                for(int j = 0;j<21;++j)
                {
                   if(check[road[i][j]][what]!=0)
                   {
                        --check[road[i][j]][what];
                   if(check[road[i][j]][what]==0)
                         --possible[road[i][j]];
                   }
                }
             }
           }
    }*/
