#pragma once
#include <iostream>
#include <filesystem>
#include "File.h"
#include "Directory.h"
#include <Windows.h>
class Menu
{
public:
	File a;
	Directory b;
	int i = 1;
	void menu();
};

