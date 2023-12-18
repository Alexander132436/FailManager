#pragma once
#include <iostream>
#include <stdio.h>
#include <direct.h>
#include <io.h>
#include <Windows.h>
#include<filesystem>

class Directory
{
private:
	_finddata_t find;
public:
	Directory() = default;

	//Метод cоздание папки
	void сreateDirectory();
	
	//Метод переименование пустой папки
	void renameDirectory();
	
	//Метод удаления папки
	void removeDirectory();
	
	//Метод просмотра папки
	bool ShowDir();
};
