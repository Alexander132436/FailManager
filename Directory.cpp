#include "Directory.h"

void Directory::�reateDirectory()
{
	char NameDirectory[256];
	std::cout << "������� ���� ��� �������� �����: ";
	std::cin >> NameDirectory;
	if (_mkdir(NameDirectory) == -1)
	{
		std::cout << "������ �������� �����" << std::endl;
	}
	else
	{
		std::cout << "����� ������ �������" << std::endl;
	}
}

void Directory::renameDirectory()
{
	char oldName[256];
	char newName[256];
	std::cout << "������� ������ ��� �����: ";
	std::cin >> oldName;
	std::cout << "������� ����� ��� �����: ";
	std::cin >> newName;
	if (rename(oldName, newName) != 0)
	{
		std::cout << "������ �������������� �����";
	}
	else
	{
		std::cout << "����� �������������";
	}
}

void Directory::removeDirectory()
{
	char Name[256];
	std::cout << "������� ��� ��������� �����: ";
	std::cin >> Name;
	if (std::filesystem::exists(Name))
	{
		if (!std::filesystem::is_empty(Name))
		{
			std::cout << "���������,�� ������ ������� �������� �����,�� �������: " << std::endl;
			std::cout << "1-��" << std::endl;
			std::cout << "2-He�" << std::endl;
			int i;
			std::cin >> i;
			switch (i)
			{
			case 1:
				std::filesystem::remove_all(Name);
				std::cout << "����� �������" << std::endl;
				break;
			case 2:
				break;
			}
		}
		else
		{
			std::cout << "����� �������" << std::endl;
		}
	}
	else { std::cout << "����� ����� �� ����������,���������� ��� ���"; }
}

bool Directory::ShowDir()
{
	setlocale(LC_ALL, "");
	char path[256];
	std::cout << "������� ���� ��������� �����: ";
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
		std::cout << "��� ����� �����";
		return false;
	}
	while (flag != -1) {
		if (strcmp(find.name, ".") && strcmp(find.name, ".."))
		{
			find.attrib& _A_SUBDIR ? strcpy_s(info, " ����� ") : strcpy_s(info, " ���� ");
			std::cout << '\t' << find.name << info << std::endl;
		}
		flag = _findnext(result, &find);
	}
	_findclose(result);
	return true;
}
