#include <iostream>
#include <stdlib.h>
using namespace std;

//遞推法
unsigned long long fib(int index)
{
    if (index == 0)
        return 0;
    else if (index <= 2)
        return 1;
    //每次將fib1,fib2相加，再把原fib2推至fib1,答案推至fib2
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
