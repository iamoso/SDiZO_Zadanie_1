#include "Table.h"
#include <iostream>

using std::cout;
using std::endl;

Table::Table()
{
	size = 0;
	table = new int[0];
}

Table::Table(int size)
{
	size = size;
	table = new int[size];
}

Table::~Table()
{
	delete[] table;
}

void Table::AddAtTheBeginning(int data)
{
	int *temp = new int[size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = table[i];
	}
	delete[] table;
	table = new int[size + 1];
	table[0] = data;
	for (int i = 0; i < size; i++)
	{
		table[i + 1] = temp[i];
	}
	size++;
	delete[] temp;
}

void Table::AddAtTheEnd(int data)
{
	int *temp = table;
	table = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		table[i] = temp[i];
	}
	table[size] = data;
	size++;
	delete[] temp;
}

void Table::AddInRandomPlace(int data, int place)
{
	if (place == 0)
	{
		AddAtTheBeginning(data);
	}
	else if (place == size)
	{
		AddAtTheEnd(data);
	}
	else if (place < 0 || place > size)
	{
		cout << "Niepoprawne miejsce do wstawienia danej." << endl;
	}
	else
	{
		int *temp = table;
		table = new int[size + 1];
		for (int i = 0; i < place; i++)
		{
			table[i] = temp[i];
		}
		table[place] = data;
		for (int i = place; i < size; i++)
		{
			table[i + 1] = temp[i];
		}
		size++;
		delete[] temp;
	}
}

void Table::DeleteFromBeginning()
{
	if (size == 0)
	{
		cout << "Tablica jest juz pusta." << endl;
	}
	else
	{
		int *temp = new int[size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = table[i];
		}
		size--;
		delete[] table;
		table = new int[size];
		for (int i = 0; i < size; i++)
		{
			table[i] = temp[i + 1];
		}
		delete[] temp;
	}
}

void Table::DeleteFromEnd()
{
	if (size == 0)
	{
		cout << "Tablica jest juz pusta." << endl;
	}
	else
	{
		int *temp = table;
		size--;
		table = new int[size];
		for (int i = 0; i < size; i++)
		{
			table[i] = temp[i];
		}
		delete[] temp;
	}
}

void Table::DeleteFromRandomPlace(int place)
{
	if (size == 0)
	{
		cout << "Tablica jest juz pusta." << endl;
	}
	else
	{
		if (place >= size || place < 0)
		{
			cout << "Blednie wprowadzone dane." << endl;
		}
		else
		{
			int *temp = new int[size];
			for (int i = 0; i < size; i++)
			{
				temp[i] = table[i];
			}
			size--;
			delete[] table;
			table = new int[size];
			for (int i = 0; i < place; i++)
			{
				table[i] = temp[i];
			}
			for (int i = place; i < size; i++)
			{
				table[i] = temp[i + 1];
			}
			delete[] temp;
		}
	}
}

void Table::WriteAll()
{
	for (int *i = table; i < (table + size); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

int Table::Search(int value)
{
	for (int i = 0; i < size; i++)
	{
		if (table[i] == value)
			return i;
	} 
	return -1;
}

int Table::GetSize()
{
	return size;
}
