#include "File.h"

void File::createFile()
{
	char PATH[256];
	std::cout << "������� �������� �����: ";
	std::cin >> PATH;
	if (fopen_s(&f, PATH, "w") != NULL)
	{
		std::cout << "���� �� ������";
	}
	else
	{
		std::cout << "���� ������� ������" << std::endl;
	}
	if (fclose(f) == EOF)
	{
		std::cout << "���� �� ������" << std::endl;
	}
	else { std::cout << "���� ������" << std::endl; }
}

void File::deleteFile()
{
	char PATH[256];
	std::cout << "������� ���� ��� �������� �����: ";
	std::cin >> PATH;
	if (remove(PATH) == 0)
	{
		std::cout << "���� �����" << std::endl;
	}
	else { std::cout << "���� �� �����,���������� ��� ���"; }
}

void File::renameAndRemove()
{
	char Name[256];
	char NewName[256];
	std::cout << "������� ������ ��� �����: ";
	std::cin >> Name;
	std::cout << "������� ����� ��� �����: ";
	std::cin >> NewName;
	if (rename(Name, NewName) == 0)
	{
		std::cout << "���� ������� ������������";
	}
	else
	{
		std::cout << "������ �������������� �����";
	}
}

void File::findFileInCatalog()
{
	char PATH[256];
	std::cout << "������� ������ ���� � �����: ";
	std::cin >> PATH;
	char MASKA[10];
	std::cout << "������� ��������� ������ �� �����: ";
	std::cin >> MASKA;
	strcat_s(PATH, MASKA);
	file = new _finddata_t;
	uint64_t done = _findfirst(PATH, file);
	int res = done;
	int fileCount = 0;
	while (res != -1)
	{
		fileCount++;
		std::cout << file->name << std::endl;
		res = _findnext(done, file);
	}
	std::cout << "���� ������� " << fileCount << " � " << PATH << std::endl;
	_findclose(done);
	delete file;
}

