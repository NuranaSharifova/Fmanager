#include <iostream>
#include<Windows.h>
#include <fstream>
#include <list>
#include <io.h>
#include<direct.h>
#include<stdio.h>
using namespace std;

//class Guest {
//	string name;
//	string surname;
//	string fathername;
//	string address;
//	int mobile;
//	string loginname;
//	int password;
//
//public:
//	Guest()
//	{
//		this->name = "";
//		this->surname = "";
//		this->fathername = "";
//		this->address = "";
//		this->mobile = 0;
//		
//	}
//	Guest(string name,string surname,string fathername,string adress,int mobile,string loginname,int password)
//	{
//		this->name = name;
//		this->surname = surname;
//		this->fathername = fathername;
//		this->address = address;
//		this->mobile = mobile;
//		this->loginname = loginname;
//		this->password = password;
//	}
//	//void Register();
//	void Savetofile();
//	void Register(Guest &g);
//	void Print();
//};
//
//
//
//void Guest::Savetofile()
//{
//	int size;
//	fstream file("guest.txt", ios::out | ios::binary | ios::app);
//	if (!file)
//	{
//		cout << "File not open for write" << endl;
//		exit(1);
//	}
//
//	file.write((char*)&mobile, sizeof(int));
//	file.write((char*)&password, sizeof(int));
//	size = name.length();
//	file.write((char*)&size, sizeof(size));
//	file.write(name.c_str(), size * sizeof(char));
//	size = surname.length();
//	file.write((char*)&size, sizeof(size));
//	file.write(surname.c_str(), size * sizeof(char));
//	size = fathername.length();
//	file.write((char*)&size, sizeof(size));
//	file.write(fathername.c_str(), size * sizeof(char));
//	size = address.length();
//	file.write((char*)&size, sizeof(size));
//	file.write(address.c_str(), size * sizeof(char));
//	size = loginname.length();
//	file.write((char*)&size, sizeof(size));
//	file.write(loginname.c_str(), size * sizeof(char));
//	file.close();
//
//
//}
//
//void Guest::Register(Guest &g)
//{
//	fstream file("guest.txt", ios::in | ios::binary);
//	if (!file)
//	{
//		cout << "File not open for read" << endl;
//		exit(1);
//	}
//	char* n, * s, * f, * a,*l;
//	int temp;
//	int m,p;
//	while (file.read((char*)&m, sizeof(n)))
//	{
//		file.read((char*)&p, sizeof(int));
//		file.read((char*)&temp, sizeof(int));
//		n = new char[temp + 1];
//		if (!n)
//		{
//			cout << "Memmory allocation error" << endl;
//			exit(1);
//		}
//		file.read(n, temp * sizeof(char));
//		n[temp] = '\0';
//	
//	
//		file.read((char*)&temp, sizeof(int));
//		s = new char[temp + 1];
//		if (!s)
//		{
//			cout << "Memmory allocation error" << endl;
//			exit(1);
//		}
//		file.read(s, temp * sizeof(char));
//		s[temp] = '\0';
//	
//
//		file.read((char*)&temp, sizeof(int));
//		f = new char[temp + 1];
//		if (!f)
//		{
//			cout << "Memmory allocation error" << endl;
//			exit(1);
//		}
//		file.read(f, temp * sizeof(char));
//		f[temp] = '\0';
//	
//		file.read((char*)&temp, sizeof(int));
//		a = new char[temp + 1];
//		if (!a)
//		{
//			cout << "Memmory allocation error" << endl;
//			exit(1);
//		}
//		file.read(a, temp * sizeof(char));
//		a[temp] = '\0';
//	
//
//		file.read((char*)&temp, sizeof(int));
//		l= new char[temp + 1];
//		if (!a)
//		{
//			cout << "Memmory allocation error" << endl;
//			exit(1);
//		}
//		file.read(l, temp * sizeof(char));
//		l[temp] = '\0';
//
//		cout << "Name: ";
//		cin >> name;
//		cout << "Surname: ";
//		cin >> surname;
//		cout << "FatherName: ";
//		cin >> fathername;
//		cout << "Address: ";
//		cin >> address;
//		cout << "Mobile number: ";
//		cin >> mobile;
//		cout << "Loginname:";
//		cin >> loginname;
//		while(l == loginname) {
//
//			cout << "Such loginname already exists, PLease try again";
//			cin >> loginname;
//		}
//		cout << "Password: ";
//		cin >> password;
//	
//
//		delete[] n;
//		delete[] s;
//		delete[] f;
//		delete[] a;
//		delete[] l;
//	}
//
//}
//
//void Guest::Print()
//{
//	cout << "Name: " << name << endl;
//	cout << "Surname: " << surname << endl;
//	cout << "FatherName: " << fathername << endl;
//	cout << "Address: " << address << endl;
//	cout << "Email: " << mobile<< endl;
//}
//
//void main() {
//	int choice;
//	Guest g;
//	
//	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hconsole, 11);
//	
//	cout << " Welcome to Testing program!!!\n ";
//	system("pause");
//	system("cls");
//	g.Register(g);
//	g.Savetofile();
//
//	//do {
//	//	system("cls");
//	//	cout << "1 - Register \n2- Login" << endl;
//	//	cin >> choice;
//	//	if (choice == 1) {
//	//		system("cls");
//	//		cout << "1- Register as admin\n2-Register as guest\n3-Return back" << endl;
//	//		cin >> choice;
//	//		SetConsoleTextAttribute(hconsole, 15);
//
//	//		switch (choice)
//	//		{
//	//		case 1:
//	//			system("cls");
//	//	
//	//			break;
//	//		case 2:
//	//			system("cls");
//	//			g.Register();
//	//			g.Savetofile();
//	//			break;
//	//		case 3:
//	//			
//	//			break;
//	//		case 4:
//	//			break;
//	//			
//	//		default:
//	//			cout << "Not correct input" << endl;
//	//			break;
//	//		}
//
//	//	}
//	//	else if (choice == 2) { 
//	//		
//	//		cout << "1- Login as admin\n2-Login as guest" << endl; 
//	//	
//	//	
//	//	
//	//	
//	//	
//	//	}
//	//	
//
//	//} while (true);
//
//
//
//}

class Farmanager {

public:
	Farmanager()
	{
		
	}
	void Createfile();
	void RenameFile();
	void CreateDir();
};
void Farmanager::Createfile()
{
	fstream f;
	string path;
	cout << "Enter the file name you want create:";
	cin >> path;
	f.open(path,fstream::app);
	if(!f.is_open()) {
		cout << "Such file name already exists!";
	}
	else {
		cout << "File created!";
	}

}
void Farmanager::RenameFile()
{
	{
		char oldName[50];
		char newName[50];
		cout << "Old Name:";
		cin >> oldName;
		cout << "New Name:";
		cin >> newName;
		if (rename(oldName, newName) != 0) {
			cout << "Error..." << endl;
		}
		else {

			cout << "Complete..." << endl;
		}
	}
}
void Farmanager::CreateDir()
{
	{
		char name[50];
		cout << "Enter dir name:";
		cin >> name;
		if (_mkdir(name) == -1) {
			cout << "Error..." << endl;
		}
		else {

			cout << "Complete..." << endl;
		}
	}
}
void main() {

	Farmanager f;
	/*f.RenameFile();*/
	f.Createfile();



}


