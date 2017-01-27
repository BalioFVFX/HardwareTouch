#pragma comment(lib,"Winmm.lib")
#include <iostream>
#include <windows.h> 
#include <mmsystem.h>

using namespace std;
bool isOpen = false;


int main()
{
	while (true)
	{
		int choice;
		cout << "Select from below functions:" << endl;
		cout << "1 - Open CD" << endl;
		cout << "2 - Close CD" << endl;
		cout << "3 - Exit" << endl;
		cin >> choice;
		if (choice == 1)
		{
			isOpen == true;
			mciSendString("open CDAudio", NULL, 0, NULL);
			mciSendString("set CDAudio door open", NULL, 1, NULL);


		}


		if (choice == 2)
		{
			isOpen == false;
			mciSendString("open CDAudio", NULL, 0, NULL);
			mciSendString("set CDAudio door closed", NULL, 1, NULL);

		}
		if (choice == 3)
		{
			cout << "Exiting the program" << endl;
			Sleep(1000);
			break;
		}
	}

	return 0;
}