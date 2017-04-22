#ifndef TABLE_H
#define TABLE_H

class Table
{
public:
	Table();
	Table(int size);
	~Table();
	void AddAtTheBeginning(int data);
	void AddAtTheEnd(int data);
	void AddInRandomPlace(int data, int place);

	void DeleteFromBeginning();
	void DeleteFromEnd();
	void DeleteFromRandomPlace(int place);

	void WriteAll();

	int Search(int value);

	int GetSize();

private:
	int size;
	int *table;
};

#endif