#include <iostream>
#include <stdlib.h>
using namespace std;

const int NUMBER_OF_QUEENS = 8;
int queens[NUMBER_OF_QUEENS];
//�T�{�ӦZ��m�O�_�X�k, row->�C, col->��
bool isValid(int row,int col)
{
    for (int i = 1; i <= row; i++)
    {
        if (queens[row - i] == col //�ӦZ�W�観�ӦZ
        || queens[row - i] == (col - i) //�ӦZ���W�観�ӦZ
        || queens[row - i] == (col + i)) //�ӦZ�k�W�観�ӦZ
            return false;
    }
    return true;
}
//�j�M�K�ӦZ��
bool searchAns(int row)
{   //�j�M��̫�@�C,�����j�M
    if(row == NUMBER_OF_QUEENS)
        return true;
    for (int col = 0; col < NUMBER_OF_QUEENS; col++)
    {   //�a�|��m�ӦZ��m"
        queens[row] = col;
        //�T�{�ӦZ��m�X�k�� && �C�@�C��m1�ӬӦZ
        if(isValid(row,col) && searchAns(row + 1))
            return true;
    }
    //���C�S���X�k���ӦZ��m
    return false;
}
//�C�L�ѽL��
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
{
    for (int i = 0; i < NUMBER_OF_QUEENS; i++)
    {
        //���m�}�C
        for (int index = 0; index <= NUMBER_OF_QUEENS; index++)
            queens[index] = -1;
        //�a�|�Ĥ@�ӬӦZ����m(�]���S������)
        queens[0] = i;
        //�j�M�Ѫk,�q�ĤG�C�}�l�j�M�̫ܳ�@�C
        searchAns(1);
        printResult();
    }
    system("pause");
    return 0;
}
