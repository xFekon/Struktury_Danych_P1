// Struktury_Danych_P1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include "Tablica_dynamiczna.h"
#include "Lista_jednokierunkowa.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	Lista_jednokierunkowa lista;

	cout << "Dodawanie elementów do listy...\n";
	lista.dodawanie(5, 'p');
	lista.dodawanie(10, 'p');
	lista.dodawanie(20, 'k');
	lista.dodawanie(15, 'l');
	lista.dodawanie(25, 'k');
	lista.dodawanie(30, 'p');
	lista.dodawanie(12, 'l');
	lista.wyświetl();

	cout << "\nUsuwanie pierwszego elementu...\n";
	lista.usuwanie('p');
	lista.wyświetl();

	cout << "\nUsuwanie ostatniego elementu...\n";
	lista.usuwanie('k');
	lista.wyświetl();

	cout << "\nUsuwanie losowego elementu...\n";
	lista.usuwanie('l');
	lista.wyświetl();

	cout << "\nWyszukiwanie elementów w liście...\n";
	int szukane[] = { 15, 25, 100 };
	for (int val : szukane) {
		int indeks = lista.szukanie(val);
		if (indeks != -1)
			cout << "Element " << val << " znaleziono na indeksie: " << indeks << endl;
		else
			cout << "Element " << val << " nie istnieje w liście." << endl;
	}

	cout << "\nDodawanie i wyszukiwanie duplikatów...\n";
	lista.dodawanie(15, 'p');
	lista.dodawanie(15, 'k');
	lista.dodawanie(15, 'l');
	lista.wyświetl();

	vector<int> indeksy = lista.szukanie_wszystkich(15);
	if (!indeksy.empty()) {
		cout << "Element 15 znaleziono na indeksach: ";
		for (int ind : indeksy) cout << ind << " ";
		cout << endl;
	}
	else {
		cout << "Element 15 nie istnieje w liście." << std::endl;
	}

	return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
