#include "stdafx.h"
#include "phoneb.h"
phoneb::phoneb()
{
	mas = NULL;
	size = 0;
}
void phoneb::add()
{
	contact *tmp = new contact[size + 1];
	for (int i = 0; i < size; i++) tmp[i].copy(mas[i]);
	tmp[size].setcont();
	size++;
	delete[] mas;
	mas = tmp;
}
void phoneb::remove()
{
	contact *tmp = new contact[size - 1];
	char *str;
	std::cout << "Введите ФИО искомого: ";
	get(str);
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (_stricmp(mas[i].getfio(), str) != 0)
		{
			tmp[j].copy(mas[i]);
			j++;
		}
	}
	size--;
	delete[] mas;
	mas = tmp;
}
void phoneb::find()
{
	char *str;
	std::cout << "Введите ФИО искомого: ";
	get(str);
	for (int i = 0; i < size; i++)
	{
		if (strstr(mas[i].getfio(), str))
		{
			std::cout << "ФИО: " << mas[i].getfio() << "\tНомер: " << mas[i].getnum() << "\n";
		}
	}
}
void phoneb::print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "ФИО: " << mas[i].getfio() << "\tНомер: " << mas[i].getnum() << "\n";
	}
}
void phoneb::wfitef(char *path)
{
	FILE *to;
	fopen_s(&to, path, "w");
	if (to)
	{
		fprintf_s(to, "%i\n", size);
		for (int i = 0; i < size; i++) mas[i].wfitef(to);
		fclose(to);
	}
	else std::cout << "Ошибка в открытии файла.\n";
}
void phoneb::readf(char *path)
{
	FILE *to;
	fopen_s(&to, path, "r");
	if (to)
	{
		fscanf_s(to, "%i", &size);
		if (mas != NULL) delete[] mas;
		mas = new contact[size];
		for (int i = 0; i < size; i++) mas[i].readf(to);
		fclose(to);
	}
	else std::cout << "Ошибка в открытии файла.\n";
}
phoneb::~phoneb()
{
	delete[] mas;
}