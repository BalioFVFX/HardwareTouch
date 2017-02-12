#pragma comment(lib,"Winmm.lib")
#include <iostream>
#include <windows.h> 
#include <string>
#ifndef NOMINMAX
#define NOMINMAX
#endif
using namespace std;
bool isOpen = false;

POINT cursorPos;
int x = cursorPos.x;
int y = cursorPos.y;
//Open file dialog

void changeVolume()
{
	INPUT ip = { 0 };
	ip.type = INPUT_KEYBOARD;
	VK_VOLUME_MUTE;
	SendInput(1, &ip, sizeof(INPUT));
}

void freezeMouse()
{
	//Get position of the mouse
	GetCursorPos(&cursorPos);
	while (true)
	{
		SetCursorPos(cursorPos.x, cursorPos.y);
	}
}

int main()
{
	while (true)
	{
		int choice;
		cout << "Select from below functions:" << endl;
		cout << "1 - Open CD" << endl;
		cout << "2 - Close CD" << endl;
		cout << "3 - Change desktop wallpaper" << endl;
		cout << "4 - Turn off sound" << endl;
		cout << "5 - Freeze mouse" << endl;
		cout << "6 - Exit" << endl;
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
				SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, filename, SPIF_SENDCHANGE);
				std::cout << "Your desktop wallpaper has been changed!" << endl;
			}
	
		}
		if (choice == 4)
		{
			changeVolume();
		}

		if (choice == 5)
		{
			freezeMouse();
		}
		if (choice == 6)
		{
			cout << "Exiting the program" << endl;
			Sleep(1000);
			break;
		}
		if (choice == 10)
		{
		
		}
	}

	return 0;
}


