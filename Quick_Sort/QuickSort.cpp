#include <iostream>
#include <stdlib.h>
using namespace std;

/*
QuickSort
�q�ƦC��X�@�Ӥ����@�� pivot,���{�������ϥμƦC�̥�������
�N pivot ���ʨ�ƦC����
�]�w�@�ӫ��Ы��V�ƦC�e�ݡA�ΨӰO���p�� pivot ����������m��m
���U�Ӷ}�l�M���Ҧ������]���F pivot�^
�Y��e�����p�� pivot�A�N�N�Ӥ���������Щҫ��V����m�A�B�N���Щ��U�@�Ӧ�m����
�Y��e�����j�󵥩� pivot �h���L��������ʧ@
��Ҧ������M����A�A�N pivot �P���Ч@���V���̫�@�Ӧ�m�������洫
�Npivot�����ݵ����t�@���ƦC(�k�ݦP�W)�A���i��Sort,���ܵL�k��������
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
        for (int count = index; count < (end-1); count++)
        {
            if(array[count] < array[end-1])
                Swap(array, index++, count);
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
    cout << "Please enter the size of array : ";
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
