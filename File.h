#pragma once
#include <iostream>
#include <io.h>
#include <stdio.h>
#include <string.h>
class File
{
private:
	_finddata_t* file;
	FILE* f;

public:
	File() = default;
	
	//Метод создание файла
	void createFile();

	//Метод удаления файла
	void deleteFile();

	//Метод перемещения,переименования файла
	void renameAndRemove();
	//Метод поиска файла или файлов по маске
	void findFileInCatalog();
};

