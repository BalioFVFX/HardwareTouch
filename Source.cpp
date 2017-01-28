#pragma comment(lib,"Winmm.lib")
#include <iostream>
#include <windows.h> 
#include <string>
#ifndef NOMINMAX
#define NOMINMAX
#endif
using namespace std;
bool isOpen = false;

//Open file dialog


int main()
{
	while (true)
	{
		int choice;
		cout << "Select from below functions:" << endl;
		cout << "1 - Open CD" << endl;
		cout << "2 - Close CD" << endl;
		cout << "3 - Change desktop wallpaper" << endl;
		cout << "4 - Exit" << endl;
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
			char filename[MAX_PATH];

			OPENFILENAME ofn;
			ZeroMemory(&filename, sizeof(filename));
			ZeroMemory(&ofn, sizeof(ofn));
			ofn.lStructSize = sizeof(ofn);
			ofn.hwndOwner = NULL;  
			ofn.lpstrFilter = "Any File\0*.*\0";
			ofn.lpstrFile = filename;
			ofn.nMaxFile = MAX_PATH;
			ofn.lpstrTitle = "Select your background";
			if (GetOpenFileNameA(&ofn))
			{
				std::cout << "Your desktop wallpaper has been changed!" << endl;
			}
			SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, filename, SPIF_SENDCHANGE);
			
			
		}
		if (choice == 4)
		{
			cout << "Exiting the program" << endl;
			Sleep(1000);
			break;
		}
	}

	return 0;
}