#pragma once
#include "stdafx.h"
class contact
{
	char *fio = nullptr;
	int num = 0;
public:
	contact() = default;
	contact(char *, int);
	void setcont();
	char *getfio()
	{
		return this->fio;
	}
	int getnum()
	{
		return this->num;
	}
	void copy(contact &);
	void wfitef(FILE *f);
	void readf(FILE *f);
	~contact();
};
void get(char *&);