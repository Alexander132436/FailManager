#include "Menu.h"

void Menu::menu()
{
	std::cout << "�������� �������� created by Alexander Kolpakov" << std::endl;
	Sleep(2000);
	system("cls");

	while (i)
	{
		std::cout << "� ��� �� ������ ��������?" << std::endl;
		std::cout << "1-�����" << std::endl;
		std::cout << "2-�����" << std::endl;
		std::cout << "0-����� �� ���������" << std::endl;
		std::cin >> i;
		system("cls");
		switch (i)
		{
		case 1:
			std::cout << "�������� ����� ������ � ������: " << std::endl;
			std::cout << "1-������� ����" << std::endl;
			std::cout << "2-�������������/��������� ����" << std::endl;
			std::cout << "3-������� ����" << std::endl;
			std::cout << "4-����� ����� � ��������" << std::endl;
			std::cout << "0-����� � ���������� ����" << std::endl;
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
			std::cout << "�������� ����� ������ � ������: " << std::endl;
			std::cout << "1-������� �����" << std::endl;
			std::cout << "2-������������� �����" << std::endl;
			std::cout << "3-������� �����" << std::endl;
			std::cout << "4-����������� �����" << std::endl;
			std::cout << "0-����� � ���������� ����" << std::endl;
			int k;
			std::cin >> k;
			switch (k)
			{
			case 1:
				b.�reateDirectory();
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
