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

	//����� c������� �����
	void �reateDirectory();
	
	//����� �������������� ������ �����
	void renameDirectory();
	
	//����� �������� �����
	void removeDirectory();
	
	//����� ��������� �����
	bool ShowDir();
};
