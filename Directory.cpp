#include "Directory.h"

void Directory::сreateDirectory()
{
	char NameDirectory[256];
	std::cout << "Введите путь для создания папки: ";
	std::cin >> NameDirectory;
	if (_mkdir(NameDirectory) == -1)
	{
		std::cout << "Ошибка создания папки" << std::endl;
	}
	else
	{
		std::cout << "Папка удачно создана" << std::endl;
	}
}

void Directory::renameDirectory()
{
	char oldName[256];
	char newName[256];
	std::cout << "Введите старое имя папки: ";
	std::cin >> oldName;
	std::cout << "Введите новое имя папки: ";
	std::cin >> newName;
	if (rename(oldName, newName) != 0)
	{
		std::cout << "Ошибка переименования папки";
	}
	else
	{
		std::cout << "Папка переименована";
	}
}

void Directory::removeDirectory()
{
	char Name[256];
	std::cout << "Введите имя удаляемой папки: ";
	std::cin >> Name;
	if (std::filesystem::exists(Name))
	{
		if (!std::filesystem::is_empty(Name))
		{
			std::cout << "Осторожно,вы хотите удалить непустую папку,вы уверены: " << std::endl;
			std::cout << "1-Да" << std::endl;
			std::cout << "2-Heт" << std::endl;
			int i;
			std::cin >> i;
			switch (i)
			{
			case 1:
				std::filesystem::remove_all(Name);
				std::cout << "Папка удалена" << std::endl;
				break;
			case 2:
				break;
			}
		}
		else
		{
			std::cout << "Папка удалена" << std::endl;
		}
	}
	else { std::cout << "Такой папки не существует,попробуйте ещё раз"; }
}

bool Directory::ShowDir()
{
	setlocale(LC_ALL, "");
	char path[256];
	std::cout << "Введите путь просмотра папки: ";
	std::cin >> path;
	char pathfind[MAX_PATH];
	strcpy_s(pathfind, path);
	strcat_s(pathfind, "\\*.*");
	char info[MAX_PATH];
	uint64_t result = _findfirst(pathfind, &find);
	system("cls");
	int flag = result;
	if (flag == -1)
	{
		std::cout << "Нет такой папки";
		return false;
	}
	while (flag != -1) {
		if (strcmp(find.name, ".") && strcmp(find.name, ".."))
		{
			find.attrib& _A_SUBDIR ? strcpy_s(info, " Папка ") : strcpy_s(info, " Файл ");
			std::cout << '\t' << find.name << info << std::endl;
		}
		flag = _findnext(result, &find);
	}
	_findclose(result);
	return true;
}
