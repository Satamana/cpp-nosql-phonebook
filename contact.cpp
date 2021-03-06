#include "stdafx.h"
#include "contact.h"
contact::contact(char *str, int n) : num(n)
{
	fio = (char*)malloc(strlen(str) + 1);
	strcpy_s(fio, strlen(str) + 1, str);
}
void contact::setcont()
{
	if (fio != NULL) free(fio);
	std::cout << "Введите ФИО: ";
	get(fio);
	std::cout << "Введите номер телефона: ";
	std::cin >> num;
	std::cin.ignore();
}
void contact::copy(contact &copy)
{
	fio = (char*)malloc(strlen(copy.fio) + 1);
	strcpy_s(fio, strlen(copy.fio) + 1, copy.fio);
	num = copy.num;
}
void contact::wfitef(FILE *to)
{
	fprintf(to, "%s\n%i\n", fio, num);
}
void contact::readf(FILE *from)
{
	char str[20];
	getc(from);
	fgets(str, 20, from);
	str[strlen(str) - 1] = 0;
	fscanf_s(from, "%i", &num);
	fio = (char*)malloc(strlen(str) + 1);
	strcpy_s(fio, strlen(str) + 1, str);
}
contact::~contact()
{
	free(fio);
}
void get(char *&str)
{
	str = NULL;
	int n = 0;
	char ch;
	while ((ch = getchar()) != '\n')
	{
		str = (char*)realloc(str, n + 1);
		str[n++] = ch;
	}
	str = (char*)realloc(str, n + 1);
	str[n] = 0;
}