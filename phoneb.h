#pragma once
#include "contact.h"
class phoneb
{
	contact *mas;
	int size;
public:
	phoneb();
	void add();
	void print();
	void remove();
	void find();
	void wfitef(char *);
	void readf(char *);
	int getsize() { return this->size; }
	~phoneb();
};