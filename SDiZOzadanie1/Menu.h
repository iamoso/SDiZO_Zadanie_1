#ifndef MENU_H
#define MENU_H
#include "Table.h"
#include "List.h"
#include "Heap.h"

class Menu
{
private:
	int input, dataInput, placeInput, menuInput;
	long long int frequency, start, elapsed,
				addAtBeginningTimes[100], addAtEndTimes[100], addInPlaceTimes[100],
				deleteFromBeginningTimes[100], deleteFromEndTimes[100], deleteFromPlaceTimes[100];
	Table table;
	List list;
	Heap heap;

	string MENU_TEXT = "---------------------------------\n1. Tablica\n2. Lista\n3. Kopiec\n4. Testy czasowe tablicy\n5. Testy czasowe listy\n6. Testy czasowe kopca\n0. Wyjscie\n---------------------------------\n";
	string TABLE_MENU = "-------------TABLICA-------------\n1. Dodawanie na poczatku\n2. Dodawanie na koncu\n3. Dodawanie na wybranym miejscu\n4. Usuwanie z poczatku\n5. Usuwanie z konca\n6. Usuwanie z wybranego miejsca\n7. Wyszukiwanie\n8. Wypisanie zawartosci\n9. Wczytywanie z pliku\n0. Wyjscie\n---------------------------------\n";
	string LIST_MENU = "--------------LISTA--------------\n1. Dodawanie na poczatku\n2. Dodawanie na koncu\n3. Dodawanie na wybranym miejscu\n4. Usuwanie z poczatku\n5. Usuwanie z konca\n6. Usuwanie z wybranego miejsca\n7. Wyszukiwanie\n8. Wypisanie zawartosci\n9. Wczytywanie z pliku\n0. Wyjscie\n---------------------------------\n";
	string HEAP_MENU = "--------------KOPIEC-------------\n1. Dodawanie\n2. Usuwanie korzenia\n3. Wyszukiwanie\n4. Wypisanie zawartosci\n5. Wczytywanie z pliku\n0. Wyjscie\n---------------------------------\n";

	string TIME_MENU = "--------------------------------\n1. Przeprowadz testy\n2. Test wyszukiwania\n0. Wyjscie\n--------------------------------\n";

	string DATA_QUESTION = "Podaj wartosc do wprowadzenia: ";
	string DATA_SEARCH_QUESTION = "Podaj wartosc do wyszukania: ";
	string PLACE_QUESTION = "Podaj miejsce na ktore chcesz wprowadzic dana: ";
	string PLACE_DELETE_QUESTION = "Podaj miejsce z ktorego chcesz usunac dane: ";

	string SEARCH_FOUND = "Wartosc znaleziona.";
	string SEARCH_FOUND_PLACE = "Wartosc znaleziona na miejscu: ";
	string SEARCH_FAILED = "Wartosci nie znaleziono.";

public:
	Menu();

	long long int ReadQPC();

	void MenuShow();
	void TableTest();
	void ListTest();
	void HeapTest();

	void TableTimeTest();
	void ListTimeTest();
	void HeapTimeTest();

	void TableAddAtTheBeginning();
	void TableAddAtTheEnd();
	void TableAddInPlace();
	void TableDeleteFromBeginning();
	void TableDeleteFromEnd();
	void TableDeleteFromPlace();
	void TableSearch();
	void TableWriteAll();
	void TableReadFromFile();

	void ListAddAtTheBeginning();
	void ListAddAtTheEnd();
	void ListAddInPlace();
	void ListDeleteFromBeginning();
	void ListDeleteFromEnd();
	void ListDeleteFromPlace();
	void ListSearch();
	void ListWriteAll();
	void ListReadFromFile();

	void HeapAdd();
	void HeapDeleteRoot();
	void HeapSearch();
	void HeapWriteAll();
	void HeapReadFromFile();

	void TableTimeAddAtTheBeginning();
	void TableTimeAddAtTheEnd();
	void TableTimeAddInPlace();
	void TableTimeDeleteFromBeginning();
	void TableTimeDeleteFromEnd();
	void TableTimeDeleteFromPlace();
	void TableTimeSearch();
	void TableTestAll();

	void ListTimeAddAtTheBeginning();
	void ListTimeAddAtTheEnd();
	void ListTimeAddInPlace();
	void ListTimeDeleteFromBeginning();
	void ListTimeDeleteFromEnd();
	void ListTimeDeleteFromPlace();
	void ListTimeSearch();
	void ListTestAll();

	void HeapTimeAdd();
	void HeapTimeDeleteRoot();
	void HeapTimeSearch();
	void HeapTestAll();

	long long int Average(long long int table[]);
	int CheckInput();
	int GenerateRandomNumber();
};

#endif