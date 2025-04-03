#include "Lista_jednokierunkowa.h"
#include <iostream>
#include <vector>

int main() {
	Lista_jednokierunkowa lista;

	std::cout << "Dodawanie elementów do listy...\n";
	lista.dodawanie(5, 'p');   
	lista.dodawanie(10, 'p');  
	lista.dodawanie(20, 'k');  
	lista.dodawanie(15, 'l');  
	lista.dodawanie(25, 'k');  
	lista.dodawanie(30, 'p');  
	lista.dodawanie(12, 'l');  
	lista.wyœwietl();

	std::cout << "\nUsuwanie pierwszego elementu...\n";
	lista.usuwanie('p');
	lista.wyœwietl();

	std::cout << "\nUsuwanie ostatniego elementu...\n";
	lista.usuwanie('k');
	lista.wyœwietl();

	std::cout << "\nUsuwanie losowego elementu...\n";
	lista.usuwanie('l');
	lista.wyœwietl();

	std::cout << "\nWyszukiwanie elementów w liœcie...\n";
	int szukane[] = { 15, 25, 100 };
	for (int val : szukane) {
		int indeks = lista.szukanie(val);
		if (indeks != -1)
			std::cout << "Element " << val << " znaleziono na indeksie: " << indeks << std::endl;
		else
			std::cout << "Element " << val << " nie istnieje w liœcie." << std::endl;
	}

	std::cout << "\nDodawanie i wyszukiwanie duplikatów...\n";
	lista.dodawanie(15, 'p');
	lista.dodawanie(15, 'k');
	lista.dodawanie(15, 'l');
	lista.wyœwietl();

	std::vector<int> indeksy = lista.szukanie_wszystkich(15);
	if (!indeksy.empty()) {
		std::cout << "Element 15 znaleziono na indeksach: ";
		for (int ind : indeksy) std::cout << ind << " ";
		std::cout << std::endl;
	}
	else {
		std::cout << "Element 15 nie istnieje w liœcie." << std::endl;
	}

	return 0;
}