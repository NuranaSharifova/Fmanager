#include <iostream>
#include<windows.h>
#include <fstream>
#include <io.h>
#include<direct.h>
#include<stdio.h>
#include<string>
#include "Farmanager.h"

using namespace std;


void main() {

	Farmanager f;

	string answer;
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
	while (answer.c_str())
	{
	
		SetConsoleTextAttribute(hconsole, 8);
		cout << "C:\\Windows\\system32>";
		cin >> answer;
		cout << endl ;

		SetConsoleTextAttribute(hconsole, 9);
		if (answer == "help")
		{
			SetConsoleTextAttribute(hconsole, 9);
			cout << "display";   SetConsoleTextAttribute(hconsole, 11);    cout << "\t\tShow disc content\n";
			SetConsoleTextAttribute(hconsole, 9);
			cout << "mkdir";  SetConsoleTextAttribute(hconsole, 11); cout<<"\t\tCreate directory \n";
			SetConsoleTextAttribute(hconsole, 9);
			cout << "mkfile";  SetConsoleTextAttribute(hconsole, 11); cout << "\t\tCreate file \n";
			SetConsoleTextAttribute(hconsole, 9);
			cout << "rmdir";   SetConsoleTextAttribute(hconsole, 11);  cout<<"\t\tDelete directory or file\n";
			SetConsoleTextAttribute(hconsole, 9);
			cout << "rename";  SetConsoleTextAttribute(hconsole, 11); cout<<"\t\tRename directory or file\n";
			SetConsoleTextAttribute(hconsole, 9);
			cout << "copy";    SetConsoleTextAttribute(hconsole, 11); cout<<"\t\tCopies file from one to another location\n";
			SetConsoleTextAttribute(hconsole, 9);
			cout << "move";    SetConsoleTextAttribute(hconsole, 11); cout<<"\t\tMoves file from one directory to another\n";
			SetConsoleTextAttribute(hconsole, 9);
			cout << "size";    SetConsoleTextAttribute(hconsole, 11); cout<<"\t\tCalculate size of file or directory\n";
			SetConsoleTextAttribute(hconsole, 9);
			cout << "find";   SetConsoleTextAttribute(hconsole, 11); cout<<"\t\tSearch by mask\n\n";
		
		}
		
		else if (answer == "display") {
			int count = 0;
	    	char action[MAX_PATH];
			char path[MAX_PATH];
			char temp[MAX_PATH];
			while (true) {
				SetConsoleTextAttribute(hconsole, 13);
				cout << "Enter commands to get Directory or exit to return back main menu: ";
				SetConsoleTextAttribute(hconsole, 9);
				cin >> action;
			
				if (strcmp(action, "exit") == 0) { system("cls"); break;  }
				else if (count==0 ) {
					if (_access(action, 00) == 0) {
						strcpy_s(path, MAX_PATH, action);
						f.ShowDir(path);
						count++;
					}
					else { cout << "Not such directory...\n"; }
				}
				else if (count != 0) {
					strcpy_s(temp, MAX_PATH, path);
					strcat_s(path, action);
					if (_access(path, 00) == 0) {
						system("cls");
						f.ShowDir(path);
					}
					else if(_access(path, 00) != 0) { cout << "Not such directory...\n"; strcpy_s(path,MAX_PATH,temp); }
				}
			}

		}
		else if (answer == "mkdir") {
			f.CreateDir();
		
		}
		else if (answer == "mkfile") {
			f.Createfile();
		
		}
		else if (answer == "rmdir") {
			f.Remove();
		
		}
		else if (answer == "rename") {
			f.RenameFile();
			system("pause");
		}
		if (answer == "copy") {
			string file1;
			string file2;
			cout << "Enter you path: ";
			cin >> file1;
			cout << "Enter you destination: ";
			cin >> file2;
			f.Copy(file1, file2);
		
		}
		if (answer == "move") {

			f.RenameFile();
			
		}
		if (answer == "size") {
			f.Sum();
	
		}
		if (answer == "find") {
			f.SearchDir();
	
		}

	}




}



