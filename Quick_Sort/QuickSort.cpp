#include <iostream>
#include <stdlib.h>
using namespace std;

/*
從數列找出一個元素作為 pivot
將 pivot 移動到數列末端
設定一個指標指向數列前端，用來記錄小於 pivot 的元素的放置位置
接下來開始遍歷所有元素（除了 pivot）
若當前元素小於 pivot，就將該元素換到指標所指向的位置，且將指標往下一個位置移動
若當前元素大於等於 pivot 則跳過不做任何動作
當所有元素遍歷後，再將 pivot 與指標作指向的最後一個位置的元素交換
*/
void Swap(int* array, int a, int b)
{
    int temp;
    temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void QuickSort(int* array, int first, int end)
{
    if(first == end)
        return;
    else
    {
        int index = first;
        for (int count = index; count < end-1; count++)
        {
            if(array[count] < array[end-1])
            {
                Swap(array, index++, count);
            }
        }
        Swap(array, index, end-1);

        QuickSort(array, first, index);
        QuickSort(array, (index + 1), end);
    }
}

void printArray(int* array,int size)
    {
        cout << endl;
        for (int a = 0; a < size; a++)
            cout << "[" << array[a] << "] ";
        cout << endl;
    }


int main()
{
    cout << "Please enter the Size of Array : ";
    int sizeOfArray;
    cin >> sizeOfArray;
    int *array = new int[sizeOfArray];

    for (int a = 0; a < sizeOfArray; a++)
    {
        cout << "Enter the array[" << a << "] : ";
        cin >> array[a];
    }
    cout << "Before sort:";
    printArray(array, sizeOfArray);

    QuickSort(array, 0, sizeOfArray);

    cout << "After sort:";
    printArray(array, sizeOfArray);

    delete[] array;

    system("pause");
	return 0;
}
