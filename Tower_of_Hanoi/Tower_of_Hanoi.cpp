#include <iostream>
#include <stdlib.h>
using namespace std;

void Towers(int Disk, string Src, string Dest, string Aux)
{
    if (Disk == 1)
        cout << "Move Disk " << Disk << " from " << Src << " to " << Dest << endl;
    else
    {
        //���N���p���L�l���컲�U���
        Towers(Disk - 1, Src, Aux, Dest);

        //���̤j���L�l��ت�
        cout << "Move Disk " << Disk << " from " << Src << " to " << Dest << endl;

        //�N���p���L�l����ت�
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
