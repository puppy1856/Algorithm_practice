#include <iostream>
#include <stdlib.h>
using namespace std;

unsigned long long fib(int index, unsigned long long *array)
{
    if(array[index] != -1)
        return array[index];
    
    else if(index == 0)
    {
        array[0] = 0;
        return 0;
    }
    else if(index == 1)
    {
        array[1] = 1;
        return 1;
    }
    else
    {
        unsigned long long ans = fib(index - 2, array) + fib(index - 1, array);
        array[index] = ans;
        return ans;
    }
}
void fib()
{
    int index;
    cout << "Please enter the Fibonacci\'s index(0~90):";
    try
    {
    cin >> index;

    if(index < 0 || index > 90)
        throw -1;
    //�إߵ��װ}�C
    unsigned long long *fibArray = new unsigned long long[index];
    //���m���װ}�C
    for (int scan = 0; scan <= index; scan++)
        fibArray[scan] = -1;
    
    cout << "Fibonacci : " << index << " answer is " << fib(index, fibArray) << endl;

    /* �C�L�L�{
    for (int a = 0; a <= index; a++)
        cout << fib(a, fibArray) << endl;
    */

    delete[] fibArray;
    }
    catch(int ex)
    {
        cout << "Index is illgal!" << endl;
        fib();
    }
}
//�ʺA�W����Fibonacci�ƦC�p��
int main()
{
    fib();

    system("pause");
    return 0;
}