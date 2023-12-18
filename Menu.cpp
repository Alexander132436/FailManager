#include "Menu.h"

void Menu::menu()
{
	std::cout << "Файловый менеджер created by Alexander Kolpakov" << std::endl;
	Sleep(2000);
	system("cls");

	while (i)
	{
		std::cout << "С чем вы хотите работать?" << std::endl;
		std::cout << "1-Файлы" << std::endl;
		std::cout << "2-Папки" << std::endl;
		std::cout << "0-Выход из программы" << std::endl;
		std::cin >> i;
		system("cls");
		switch (i)
		{
		case 1:
			std::cout << "Выберите пункт работы с файлом: " << std::endl;
			std::cout << "1-Создать файл" << std::endl;
			std::cout << "2-Переименовать/перенести файл" << std::endl;
			std::cout << "3-Удалить файл" << std::endl;
			std::cout << "4-Поиск файла в каталоге" << std::endl;
			std::cout << "0-Выйти в предыдущее меню" << std::endl;
			int j;
			std::cin >> j;
			switch (j)
			{
			case 1:
				a.createFile();
				break;
			case 2:
				a.renameAndRemove();
				break;
			case 3:
				a.deleteFile();
				break;
			case 4:
				a.findFileInCatalog();
				break;
			case 0:
				break;
			}
			break;
		case 2:
			std::cout << "Выберите пункт работы с папкой: " << std::endl;
			std::cout << "1-Создать папку" << std::endl;
			std::cout << "2-Переименовать папку" << std::endl;
			std::cout << "3-Удалить папку" << std::endl;
			std::cout << "4-Просмотреть папку" << std::endl;
			std::cout << "0-Выйти в предыдущее меню" << std::endl;
			int k;
			std::cin >> k;
			switch (k)
			{
			case 1:
				b.сreateDirectory();
				break;
			case 2:
				b.renameDirectory();
				break;
			case 3:
				b.removeDirectory();
				break;
			case 4:
				b.ShowDir();
				break;
			case 0:
				break;
			}
			break;
		case 3:
			break;
		}
	}
}
