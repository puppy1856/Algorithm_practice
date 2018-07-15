#include <iostream>
#include <stdlib.h>
using namespace std;

const int NUMBER_OF_QUEENS = 8;
int queens[NUMBER_OF_QUEENS];
//確認皇后位置是否合法, row->列, col->行
bool isValid(int row,int col)
{
    for (int i = 1; i <= row; i++)
    {
        if (queens[row - i] == col //皇后上方有皇后
        || queens[row - i] == (col - i) //皇后左上方有皇后
        || queens[row - i] == (col + i)) //皇后右上方有皇后
            return false;
    }
    return true;
}
//搜尋八皇后解
bool searchAns(int row)
{   //搜尋到最後一列,完成搜尋
    if(row == NUMBER_OF_QUEENS)
        return true;
    for (int col = 0; col < NUMBER_OF_QUEENS; col++)
    {   //窮舉放置皇后位置"第一個皇后永遠放在第一行"
        queens[row] = col;
        //確認皇后位置合法性 && 每一列放置1個皇后
        if(isValid(row,col) && searchAns(row + 1))
            return true;
    }
    //此列沒有合法的皇后位置
    return false;
}
//列印棋盤解
void printResult()
{
    cout << "\n---------------------------------\n";
    for (int row = 0; row < NUMBER_OF_QUEENS; row++)
    {
        for (int col = 0; col < NUMBER_OF_QUEENS; col++)
            cout << (col == queens[row] ? "| Q " : "|   ");
        cout << "|\n---------------------------------\n";
    }
}

int main()
{   //重置陣列
    for (int index = 0; index <= NUMBER_OF_QUEENS; index++)
        queens[index] = -1;
    //搜尋解法,從第一列開始搜尋至最後一列
    searchAns(0);
    printResult();

    system("pause");
    return 0;
}
