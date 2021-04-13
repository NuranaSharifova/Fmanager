#pragma once
#include <iostream>
#include<Windows.h>
#include <fstream>
#include <io.h>
#include<direct.h>
//#include<stdio.h>
#include<string>

using namespace std;

class Farmanager {
	_finddata_t* fd;
	ifstream* ifs;
	ofstream* ofs;
public:
	Farmanager()
	{
		this->fd = new _finddata_t;
		ifs = new ifstream;
		ofs = new ofstream;
	}
	void Createfile();
	void CreateDir();
	void Remove();
	void RenameFile();
	void SearchDir();
	void ShowDir(char path[]);
	void Copy(string name1, string name2);
	void Sum();
	~Farmanager() {

		delete fd;
		delete ifs;
		delete ofs;
	}
	
};

