#include <iostream>
#include "File.h"
#include "Directory.h"
#include <Windows.h>
#include <direct.h>
#include <stdio.h>
#include <io.h>
#include <filesystem>
#include "Menu.h"

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Menu a;
	a.menu();
	
}

