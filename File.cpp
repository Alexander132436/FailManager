#include "File.h"

void File::createFile()
{
	char PATH[256];
	std::cout << "Введите название файла: ";
	std::cin >> PATH;
	if (fopen_s(&f, PATH, "w") != NULL)
	{
		std::cout << "Файл не создан";
	}
	else
	{
		std::cout << "Файл успешно создан" << std::endl;
	}
	if (fclose(f) == EOF)
	{
		std::cout << "Файл не закрыт" << std::endl;
	}
	else { std::cout << "Файл закрыт" << std::endl; }
}

void File::deleteFile()
{
	char PATH[256];
	std::cout << "Введите путь для уданения файла: ";
	std::cin >> PATH;
	if (remove(PATH) == 0)
	{
		std::cout << "Файл удалён" << std::endl;
	}
	else { std::cout << "Файл не удалён,попробуйте ещё раз"; }
}

void File::renameAndRemove()
{
	char Name[256];
	char NewName[256];
	std::cout << "Введите старое имя файла: ";
	std::cin >> Name;
	std::cout << "Введите новое имя файла: ";
	std::cin >> NewName;
	if (rename(Name, NewName) == 0)
	{
		std::cout << "Файл успешно переименован";
	}
	else
	{
		std::cout << "Ошибка переименования файла";
	}
}

void File::findFileInCatalog()
{
	char PATH[256];
	std::cout << "Введите полный путь к папке: ";
	std::cin >> PATH;
	char MASKA[10];
	std::cout << "Введите параметры поиска по маске: ";
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
	std::cout << "Было найдено " << fileCount << " в " << PATH << std::endl;
	_findclose(done);
	delete file;
}

