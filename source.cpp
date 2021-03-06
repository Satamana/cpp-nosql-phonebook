#include "stdafx.h"
#include "contact.h"
#include "phoneb.h"
void main()
{
	setlocale(0, "rus");
	phoneb b;
	int n = 0;
	char ch;
	do
	{
		system("cls");
		std::cout << "Меню:\n";
		std::cout << "1 - Добавить абонента.\n";
		std::cout << "2 - Удалить абонента\n";
		std::cout << "3 - Вывод списка абонентов.\n";
		std::cout << "4 - Поиск абонента по ФИО.\n";
		std::cout << "5 - Загрузить информацию из файла.\n";
		std::cout << "6 - Сохранить информацию в файл.\n";
		std::cout << "esc Выход\n";
		ch = _getch();
		switch (ch)
		{
		case '1':
		{
			system("cls");
			if (n != 0)
			{
				b.add();
				std::cout << "Операция успешно завершена.\n";
				n = b.getsize();
			}
			else std::cout << "Телефонная книга пуста\n";
			Sleep(1000);
			break;
		}
		case '2':
		{
			system("cls");
			if (n != 0)
			{
				b.remove();
				std::cout << "Операция успешно завершена.\n";
				n = b.getsize();
			}
			else std::cout << "Телефонная книга пуста\n";
			Sleep(1000);
			break;
		}
		case '3':
		{
			system("cls");
			if (n != 0)
			{
				b.print();
				system("pause");
			}
			else
			{
				std::cout << "Телефонная книга пуста\n";
				Sleep(1000);
			}
			break;
		}
		case '4':
		{
			system("cls");
			if (n != 0)
			{
				b.find();
				system("pause");
			}
			else
			{
				std::cout << "Телефонная книга пуста\n";
				Sleep(1000);
			}
			break;
		}
		case '5':
		{
			system("cls");
			std::cout << "Укажите путь к файлу: ";
			char *path;
			get(path);
			b.readf(path);
			std::cout << "Операция успешно завершена.\n";
			n = b.getsize();
			Sleep(1000);
			break;
		}
		case '6':
		{
			system("cls");
			std::cout << "Укажите путь к файлу: ";
			char *path;
			get(path);
			b.wfitef(path);
			std::cout << "Операция успешно завершена.\n";
			n = b.getsize();
			Sleep(1000);
			break;
		}
		}
	} while (ch != 27);
}