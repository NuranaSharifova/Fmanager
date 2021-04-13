#include "Farmanager.h"

void Farmanager::Createfile()
{
	
	string path;
	cout << "Enter the file name you want create:";
	cin >> path;
	ifs->open(path,ios::app);
	if (!ifs->is_open()) {
		cout << "Such file name already exists...\n";
	}
	else {
		cout << "File created...\n";
	}
	
}
void Farmanager::CreateDir()
{
		char name[50];
		cout << "Enter dir name:";
		cin >> name;
		if (_mkdir(name) == -1) {
			cout << "Error...\n" << endl;
		}
		else {

			cout << "Complete...\n" << endl;
		}
}
void Farmanager::Remove()
{
	cout << "Enter full path the file or directory name you want delete: ";
	char name[MAX_PATH];
	cin >> name;
	
	long done = _findfirst(name, fd);
	if (fd->attrib & _A_SUBDIR) {
		if (_rmdir(fd->name) == -1) { cout << "Error...\n";  }
		else { cout << "Complete...\n"; }
	}
	else {
	
		if (remove(name) == -1) { cout << "Error...\n"; }
		else { cout << "Complete...\n"; }

 }
		

}
void Farmanager::RenameFile()
{
	char oldPath[MAX_PATH];
	char newPath[MAX_PATH];
	string old;
	cout << "Old Name:";
	cin >> oldPath;
	cout << "New Name:";
	cin >> newPath;
	if (rename(oldPath, newPath) != 0) {
		cout << "Error..." << endl;
	}
	else {

		cout << "Complete..." << endl;
	}
}


void Farmanager::SearchDir() {
	char path[MAX_PATH];
	char mask[MAX_PATH];

	
	cout << "Enter path:";
	cin >> path;
	cout << "Enter mask:";
	cin >> mask;
	strcat_s(path, mask);
	long done = _findfirst(path, fd);
	
	int isReadeble = done;
	int count = 0;
	while (isReadeble != -1)
	{
		count++;
		cout << count << " - " << fd->name << " " <<endl;
		isReadeble = _findnext(done, fd);
	}

	cout << count << " files finded" << endl;
	_findclose(done);
	
}

void Farmanager::ShowDir(char path[])
{
	
	char pathfind[MAX_PATH];
	strcpy_s(pathfind, MAX_PATH,path);
	strcat_s(pathfind, "*.*");
	long done = _findfirst(pathfind, fd);

	int isReadeble = done;
	int count = 0;
	while (isReadeble != -1)
	{
		count++;
		cout << count << " - " << fd->name << "\n"; 
		isReadeble = _findnext(done, fd);
	}
	_findclose(done);

}

void Farmanager::Copy(string name1, string name2)
{
	string sourcePath, copyPath;
	sourcePath = name1;
	copyPath = name2;

	ifs->open(sourcePath, ios::binary);
	ofs->open(copyPath, ios::binary);
	string buffer;
	while (!ifs->eof())
	{
		buffer = " ";
		getline(*ifs, buffer);
		*ofs << buffer << endl;
	}
	ifs->close();
	ofs->close();
}

void Farmanager::Sum()
{
	long double sum = 0;
	char path[MAX_PATH];
	char mask[MAX_PATH];

	const double asize = 0.001;
	cout << "Enter path:";
	cin >> path;
	cout << "Enter mask:";
	cin >> mask;
	strcat_s(path, mask);
	long done = _findfirst(path, fd);

	int isReadeble = done;
	int count = 0;
	while (isReadeble != -1)
	{
		sum = sum + (fd->size * asize);
		isReadeble = _findnext(done, fd);
	}

	cout << "Size of directory is :" <<sum <<"bytes" <<endl;
	_findclose(done);
}
