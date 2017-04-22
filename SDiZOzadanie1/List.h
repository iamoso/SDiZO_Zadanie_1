#ifndef LIST_H
#define LIST_H
#include "ListElement.h"


class List
{
public:
	List();
	~List();
	void AddAtTheBeginning(int data);
	void AddAtTheEnd(int data);
	void AddInRandomPlace(int data, int place);

	void DeleteFromBeginning();
	void DeleteFromEnd();
	void DeleteFromRandomPlace(int place);

	void WriteAll();

	int Search(int value);
	
	int size;
	ListElement *head, *tail;
};

#endif