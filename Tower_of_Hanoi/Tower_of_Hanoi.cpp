#include <iostream>
#include <stdlib.h>
using namespace std;

//src->起始點, Dest->終點, Aux->輔助點
void Towers(int Disk, string Src, string Dest, string Aux)
{
    if (Disk == 1)
        cout << "Move Disk " << Disk << " from " << Src << " to " << Dest << endl;
    else
    {
        //先將較小的盤子移到輔助木棒
        Towers(Disk - 1, Src, Aux, Dest);

        //移最大的盤子到目的
        cout << "Move Disk " << Disk << " from " << Src << " to " << Dest << endl;

        //將較小的盤子移到目的
        Towers(Disk - 1, Aux, Dest, Src);
    }
}

int main()
{
    int Disk;
    cout << "Please enter the disk count: ";
    cin >> Disk;
    Towers(Disk, "start", "end", "support");

    system("pause");
	return 0;
}
