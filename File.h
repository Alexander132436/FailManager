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
	
	//����� �������� �����
	void createFile();

	//����� �������� �����
	void deleteFile();

	//����� �����������,�������������� �����
	void renameAndRemove();
	//����� ������ ����� ��� ������ �� �����
	void findFileInCatalog();
};

