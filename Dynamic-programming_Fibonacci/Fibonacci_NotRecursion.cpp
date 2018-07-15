#include <iostream>
#include <stdlib.h>
using namespace std;

//�����k
unsigned long long fib(int index)
{
    if (index == 0)
        return 0;
    else if (index <= 2)
        return 1;
    //�C���Nfib1,fib2�ۥ[�A�A���fib2����fib1,���ױ���fib2
    unsigned long long temp, fib1 = 1, fib2 = 1;
    for (int count = 3; count <= index; count++)
    {
        temp = fib1 + fib2;
        fib1 = fib2;
        fib2 = temp;
    }
    return temp;
}

void printAns()
{
    int index;
    cout << "Please enter the Fibonacci\'s index(0~90):";
    try
    {
        cin >> index;

        if (index < 0 || index > 90)
            throw - 1;
        cout << "Fibonacci : " << index << " answer is " << fib(index) << endl;
    }
    catch(int ex)
    {
        cout << "Index is illgal!" << endl;
        printAns();
    }
}

int main()
{
    printAns();

    system("pause");
	return 0;
}
