#ifndef LISTELEMENT_H
#define LISTELEMENT_H

class ListElement
{
public:
	ListElement();

	int data;
	ListElement *next, *prev;
};

#endif