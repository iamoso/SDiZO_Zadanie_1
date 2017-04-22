#include "Menu.h"
#include <Windows.h>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <limits>
#undef max

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::fstream;
using std::ios_base;

Menu::Menu()
{
	srand(time(NULL));
	MenuShow();
}

long long int Menu::ReadQPC()
{
		LARGE_INTEGER count;
		QueryPerformanceCounter(&count);
		return((long long int)count.QuadPart);
}

void Menu::MenuShow()
{
	do
	{
		cout << MENU_TEXT;
		menuInput = CheckInput();
		switch (menuInput)
		{
		case 1:
			TableTest();
			break;
		case 2:
			ListTest();
			break;
		case 3:
			HeapTest();
			break;
		case 4:
			TableTimeTest();
			break;
		case 5:
			ListTimeTest();
			break;
		case 6:
			HeapTimeTest();
			break;
		default:
			break;
		}
	} while (menuInput != 0);
}

void Menu::TableTest()
{
	do
	{
		cout << TABLE_MENU;
		input = CheckInput();
		if (input >= 0 && input <= 9)
		{
			switch (input)
			{
			case 1:
				TableAddAtTheBeginning();
				break;
			case 2:
				TableAddAtTheEnd();
				break;
			case 3:
				TableAddInPlace();
				break;
			case 4:
				TableDeleteFromBeginning();
				break;
			case 5:
				TableDeleteFromEnd();
				break;
			case 6:
				TableDeleteFromPlace();
				break;
			case 7:
				TableSearch();
				break;
			case 8:
				TableWriteAll();
				break;
			case 9:
				TableReadFromFile();
				break;
			default:
				break;
			}
		}
	} while (input != 0);
}

void Menu::ListTest()
{
	do
	{
		cout << LIST_MENU;
		input = CheckInput();
		if (input >= 0 && input <= 9)
		{
			switch (input)
			{
			case 1:
				ListAddAtTheBeginning();
				break;
			case 2:
				ListAddAtTheEnd();
				break;
			case 3:
				ListAddInPlace();
				break;
			case 4:
				ListDeleteFromBeginning();
				break;
			case 5:
				ListDeleteFromEnd();
				break;
			case 6:
				ListDeleteFromPlace();
				break;
			case 7:
				ListSearch();
				break;
			case 8:
				ListWriteAll();
				break;
			case 9:
				ListReadFromFile();
				break;
			default:
				break;
			}
		}
	} while (input != 0);
}

void Menu::HeapTest()
{
	do
	{
		cout << HEAP_MENU;
		input = CheckInput();
		if (input >= 0 && input <= 5)
		{
			switch (input)
			{
			case 1:
				HeapAdd();
				break;
			case 2:
				HeapDeleteRoot();
				break;
			case 3:
				HeapSearch();
				break;
			case 4:
				HeapWriteAll();
				break;
			case 5:
				HeapReadFromFile();
				break;
			default:
				break;
			}
		}
	} while (input != 0);
}

void Menu::TableTimeTest()
{
	do
	{
		cout << TIME_MENU;
		input = CheckInput();
		if (input >= 0 && input <= 2)
		{
			switch (input)
			{
			case 1:
				TableTestAll();
				break;
			case 2:
				TableTimeSearch();
				break;
			default:
				break;
			}
		}
	} while (input != 0);
}

void Menu::ListTimeTest()
{
	do
	{
		cout << TIME_MENU;
		input = CheckInput();
		if (input >= 0 && input <= 2)
		{
			switch (input)
			{
			case 1:
				ListTestAll();
				break;
			case 2:
				ListTimeSearch();
				break;
			default:
				break;
			}
		}
	} while (input != 0);
}

void Menu::HeapTimeTest()
{
	do
	{
		cout << TIME_MENU;
		input = CheckInput();
		if (input >= 0 && input <= 2)
		{
			switch (input)
			{
			case 1:
				HeapTestAll();
				break;
			case 2:
				HeapTimeSearch();
			default:
				break;
			}
		}
	} while (input != 0);
}

void Menu::TableAddAtTheBeginning()
{
	cout << DATA_QUESTION;
	dataInput = CheckInput();
	table.AddAtTheBeginning(dataInput);
}

void Menu::TableAddAtTheEnd()
{
	cout << DATA_QUESTION;
	dataInput = CheckInput();
	table.AddAtTheEnd(dataInput);
}

void Menu::TableAddInPlace()
{
	cout << DATA_QUESTION;
	dataInput = CheckInput();
	cout << PLACE_QUESTION;
	placeInput = CheckInput();
	table.AddInRandomPlace(dataInput, placeInput);
}

void Menu::TableDeleteFromBeginning()
{
	table.DeleteFromBeginning();
}

void Menu::TableDeleteFromEnd()
{
	table.DeleteFromEnd();
}

void Menu::TableDeleteFromPlace()
{
	cout << PLACE_DELETE_QUESTION;
	placeInput = CheckInput();
	table.DeleteFromRandomPlace(placeInput);
}

void Menu::TableSearch()
{
	cout << DATA_SEARCH_QUESTION;
	dataInput = CheckInput();
	int searchScore = table.Search(dataInput);
	if (searchScore >= 0)
		cout << SEARCH_FOUND_PLACE << searchScore << endl;
	else
		cout << SEARCH_FAILED << endl;
}

void Menu::TableWriteAll()
{
	table.WriteAll();
}

void Menu::TableReadFromFile()
{
	fstream file("table.txt", ios_base::in);
	int size, data;
	file >> size;
	for (int i = 0; i < size; i++)
	{
		file >> data;
		table.AddAtTheEnd(data);
	}
	file.close();
}

void Menu::ListAddAtTheBeginning()
{
	cout << DATA_QUESTION;
	dataInput = CheckInput();
	list.AddAtTheBeginning(dataInput);
}

void Menu::ListAddAtTheEnd()
{
	cout << DATA_QUESTION;
	dataInput = CheckInput();
	list.AddAtTheEnd(dataInput);
}

void Menu::ListAddInPlace()
{
	cout << DATA_QUESTION;
	dataInput = CheckInput();
	cout << PLACE_QUESTION;
	placeInput = CheckInput();
	list.AddInRandomPlace(dataInput, placeInput);
}

void Menu::ListDeleteFromBeginning()
{
	list.DeleteFromBeginning();
}

void Menu::ListDeleteFromEnd()
{
	list.DeleteFromEnd();
}

void Menu::ListDeleteFromPlace()
{
	cout << PLACE_DELETE_QUESTION;
	placeInput = CheckInput();
	list.DeleteFromRandomPlace(placeInput);
}

void Menu::ListSearch()
{
	cout << DATA_SEARCH_QUESTION;
	dataInput = CheckInput();
	int searchScore = list.Search(dataInput);
	if (searchScore >= 0)
		cout << SEARCH_FOUND_PLACE << searchScore << endl;
	else
		cout << SEARCH_FAILED << endl;
}

void Menu::ListWriteAll()
{
	list.WriteAll();
}

void Menu::ListReadFromFile()
{
	fstream file("list.txt", ios_base::in);
	int size, data;
	file >> size;
	for (int i = 0; i < size; i++)
	{
		file >> data;
		list.AddAtTheEnd(data);
	}
	file.close();
}

void Menu::HeapAdd()
{
	cout << DATA_QUESTION;
	dataInput = CheckInput();
	heap.Add(dataInput);
}

void Menu::HeapDeleteRoot()
{
	heap.DeleteRoot();
}

void Menu::HeapSearch()
{
	cout << DATA_SEARCH_QUESTION;
	dataInput = CheckInput();
	if (heap.Search(dataInput))
		cout << SEARCH_FOUND << endl;
	else
		cout << SEARCH_FAILED << endl;
}

void Menu::HeapWriteAll()
{
	heap.WriteAll("","",0);
}

void Menu::HeapReadFromFile()
{
	fstream file("heap.txt", ios_base::in);
	int size, data;
	file >> size;
	for (int i = 0; i < size; i++)
	{
		file >> data;
		heap.Add(data);
	}
	file.close();
}

void Menu::TableTimeAddAtTheBeginning()
{
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	dataInput = GenerateRandomNumber();
	start = ReadQPC();
	for (int i = 0; i < 1000; i++)
	{
		table.AddAtTheBeginning(dataInput);
	}
	elapsed = ReadQPC() - start;
	elapsed = (elapsed * 1000000000) / frequency;
}

void Menu::TableTimeAddAtTheEnd()
{
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	dataInput = GenerateRandomNumber();
	start = ReadQPC();
	for (int i = 0; i < 1000; i++)
	{
		table.AddAtTheEnd(dataInput);
	}
	elapsed = ReadQPC() - start;
	elapsed = (elapsed * 1000000000) / frequency;
}

void Menu::TableTimeAddInPlace()
{
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	dataInput = GenerateRandomNumber();
	start = ReadQPC();
	for (int i = 0; i < 1000; i++)
	{
		if (table.GetSize() != 0)
			table.AddInRandomPlace(dataInput, rand() % table.GetSize());
		else
			table.AddAtTheBeginning(rand() % 100000);
	}
	elapsed = ReadQPC() - start;
	elapsed = (elapsed * 1000000000) / frequency;
}

void Menu::TableTimeDeleteFromBeginning()
{
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	start = ReadQPC();
	int size = table.GetSize();
	for (int i = 0; i < size; i++)
	{
		table.DeleteFromBeginning();
	}
	elapsed = ReadQPC() - start;
	elapsed = (elapsed * 1000000000) / frequency;
}

void Menu::TableTimeDeleteFromEnd()
{
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	start = ReadQPC();
	int size = table.GetSize();
	for (int i = 0; i < size; i++)
	{
		table.DeleteFromEnd();
	}
	elapsed = ReadQPC() - start;
	elapsed = (elapsed * 1000000000) / frequency;
}

void Menu::TableTimeDeleteFromPlace()
{
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	start = ReadQPC();
	int size = table.GetSize();
	for (int i = 0; i < size; i++)
	{
		if (table.GetSize() != 0)
			table.DeleteFromRandomPlace(rand() % table.GetSize());
		else
			table.DeleteFromBeginning();
	}
	elapsed = ReadQPC() - start;
	elapsed = (elapsed * 1000000000) / frequency;
}

void Menu::TableTimeSearch()
{
	for (int i = 0; i < 100; i++)
	{
		TableTimeAddAtTheBeginning();
		dataInput = GenerateRandomNumber();
		QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
		start = ReadQPC();
		int searchScore = table.Search(dataInput);
		elapsed = ReadQPC() - start;
		elapsed = (elapsed * 1000000000) / frequency;
		addAtBeginningTimes[i] = elapsed;
		TableTimeDeleteFromBeginning();
	}
	cout << "Sredni czas wyszukiwania wartoœci wyniosl: " << Average(addAtBeginningTimes) << " [ns]" << endl;
}

void Menu::TableTestAll()
{
	for (int i = 0; i < 100; i++)
	{
		TableTimeAddAtTheBeginning();
		addAtBeginningTimes[i] = elapsed;
		TableTimeDeleteFromBeginning();
		deleteFromBeginningTimes[i] = elapsed;
		TableTimeAddAtTheEnd();
		addAtEndTimes[i] = elapsed;
		TableTimeDeleteFromEnd();
		deleteFromEndTimes[i] = elapsed;
		TableTimeAddInPlace();
		addInPlaceTimes[i] = elapsed;
		TableTimeDeleteFromPlace();
		deleteFromPlaceTimes[i] = elapsed;
	}
	cout << "Sredni czas dodawania 1000 elementow na poczatek tablicy [ns]: " << setprecision(0) << Average(addAtBeginningTimes) << endl;
	cout << "Sredni czas usuwania 1000 elementow z poczatku tablicy [ns]: " << setprecision(0) << Average(deleteFromBeginningTimes) << endl;
	cout << "Sredni czas dodawania 1000 elementow na koniec tablicy [ns]: " << setprecision(0) << Average(addAtEndTimes) << endl;
	cout << "Sredni czas usuwania 1000 elementow z konca tablicy [ns]: " << setprecision(0) << Average(deleteFromEndTimes) << endl;
	cout << "Sredni czas dodawania 1000 elementow w losowym miejscu w tablicy [ns]: " << setprecision(0) << Average(addInPlaceTimes) << endl;
	cout << "Sredni czas usuwania 1000 elementow z losowego miejsca w tablicy [ns]: " << setprecision(0) << Average(deleteFromPlaceTimes) << endl;
}

void Menu::ListTimeAddAtTheBeginning()
{
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	dataInput = GenerateRandomNumber();
	start = ReadQPC();
	for (int i = 0; i < 5000; i++)
	{
		list.AddAtTheBeginning(dataInput);
	}
	elapsed = ReadQPC() - start;
	elapsed = (elapsed * 1000000000) / frequency;
}

void Menu::ListTimeAddAtTheEnd()
{
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	dataInput = GenerateRandomNumber();
	start = ReadQPC();
	for (int i = 0; i < 5000; i++)
	{
		list.AddAtTheEnd(dataInput);
	}
	elapsed = ReadQPC() - start;
	elapsed = (elapsed * 1000000000) / frequency;
}

void Menu::ListTimeAddInPlace()
{
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	dataInput = GenerateRandomNumber();
	start = ReadQPC();
	for (int i = 0; i < 5000; i++)
	{
		if (list.size != 0)
			list.AddInRandomPlace(dataInput, rand() % list.size);
		else
			list.AddAtTheBeginning(rand() % 1000);
	}
	elapsed = ReadQPC() - start;
	elapsed = (elapsed * 1000000000) / frequency;
}

void Menu::ListTimeDeleteFromBeginning()
{
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	start = ReadQPC();
	int size = list.size;
	for (int i = 0; i < size; i++)
	{
		list.DeleteFromBeginning();
	}
	elapsed = ReadQPC() - start;
	elapsed = (elapsed * 1000000000) / frequency;
}

void Menu::ListTimeDeleteFromEnd()
{
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	start = ReadQPC();
	int size = list.size;
	for (int i = 0; i < size; i++)
	{
		list.DeleteFromEnd();
	}
	elapsed = ReadQPC() - start;
	elapsed = (elapsed * 1000000000) / frequency;
}

void Menu::ListTimeDeleteFromPlace()
{
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	start = ReadQPC();
	int size = list.size;
	for (int i = 0; i < size; i++)
	{
		if (list.size != 0)
			list.DeleteFromRandomPlace(rand() % list.size);
		else
			list.DeleteFromBeginning();
	}
	elapsed = ReadQPC() - start;
	elapsed = (elapsed * 1000000000) / frequency;
}

void Menu::ListTimeSearch()
{
	for (int i = 0; i < 100; i++)
	{
		ListTimeAddAtTheBeginning();
		srand(time(NULL));
		dataInput = GenerateRandomNumber();
		QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
		start = ReadQPC();
		int searchScore = list.Search(dataInput);
		elapsed = ReadQPC() - start;
		elapsed = (elapsed * 1000000000) / frequency;
		addAtBeginningTimes[i] = elapsed;
		ListTimeDeleteFromBeginning();
	}
	cout << "Sredni czas wyszukiwania wartoœci wyniosl: " << Average(addAtBeginningTimes) << " [ns]" << endl;
}

void Menu::ListTestAll()
{
	for (int i = 0; i < 100; i++)
	{
		ListTimeAddAtTheBeginning();
		addAtBeginningTimes[i] = elapsed;
		ListTimeDeleteFromBeginning();
		deleteFromBeginningTimes[i] = elapsed;
		ListTimeAddAtTheEnd();
		addAtEndTimes[i] = elapsed;
		ListTimeDeleteFromEnd();
		deleteFromEndTimes[i] = elapsed;
		ListTimeAddInPlace();
		addInPlaceTimes[i] = elapsed;
		ListTimeDeleteFromPlace();
		deleteFromPlaceTimes[i] = elapsed;
	}
	cout << "Sredni czas dodawania 1000 elementow na poczatek listy [ns]: " << setprecision(0) << Average(addAtBeginningTimes) << endl;
	cout << "Sredni czas usuwania 1000 elementow z poczatku listy [ns]: " << setprecision(0) << Average(deleteFromBeginningTimes) << endl;
	cout << "Sredni czas dodawania 1000 elementow na koniec listy [ns]: " << setprecision(0) << Average(addAtEndTimes) << endl;
	cout << "Sredni czas usuwania 1000 elementow z konca listy [ns]: " << setprecision(0) << Average(deleteFromEndTimes) << endl;
	cout << "Sredni czas dodawania 1000 elementow w losowym miejscu w liscie [ns]: " << setprecision(0) << Average(addInPlaceTimes) << endl;
	cout << "Sredni czas usuwania 1000 elementow z losowego miejsca w liscie [ns]: " << setprecision(0) << Average(deleteFromPlaceTimes) << endl;
}

void Menu::HeapTimeAdd()
{
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	dataInput = GenerateRandomNumber();
	start = ReadQPC();
	for (int i = 0; i < 1000; i++)
	{
		heap.Add(dataInput);
	}
	elapsed = ReadQPC() - start;
	elapsed = (elapsed * 1000000000) / frequency;
}

void Menu::HeapTimeDeleteRoot()
{
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	start = ReadQPC();
	int size = heap.size;
	for (int i = 0; i < size; i++)
	{
		heap.DeleteRoot();
	}
	elapsed = ReadQPC() - start;
	elapsed = (elapsed * 1000000000) / frequency;
}

void Menu::HeapTimeSearch()
{
	for (int i = 0; i < 100; i++)
	{
		HeapTimeAdd();
		srand(time(NULL));
		dataInput = GenerateRandomNumber();
		QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
		start = ReadQPC();
		bool searchScore = heap.Search(dataInput);
		elapsed = ReadQPC() - start;
		elapsed = (elapsed * 1000000000) / frequency;
		addAtBeginningTimes[i] = elapsed;
		HeapTimeDeleteRoot();
	}
	cout << "Sredni czas wyszukiwania wartoœci wyniosl: " << Average(addAtBeginningTimes) << " [ns]" << endl;
}

void Menu::HeapTestAll()
{
	for (int i = 0; i < 100; i++)
	{
		HeapTimeAdd();
		addAtBeginningTimes[i] = elapsed;
		HeapTimeDeleteRoot();
		deleteFromBeginningTimes[i] = elapsed;
	}
	cout << "Sredni czas dodawania 1000 elementow do kopca [ns]: " << setprecision(0) << Average(addAtBeginningTimes) << endl;
	cout << "Sredni czas usuwania 1000 elementow z kopca [ns]: " << setprecision(0) << Average(deleteFromBeginningTimes) << endl;
}

long long int Menu::Average(long long int table[])
{
	long long int average = 0;

	for  (int i = 0; i < 100; i++)
	{
		average += table[i];
	}
	return average / 100;
}

int Menu::CheckInput()
{
	int input;
	cin >> input;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cout << "Zle dane wejsciowe. Wprowadz liczbe: ";
		cin >> input;
	}
	return input;
}

int Menu::GenerateRandomNumber()
{
	int randomNumber = 100000 * ((rand() % 11000) + 10000);
	//int randomNumber = (rand() % 20000);
	return randomNumber;
}
