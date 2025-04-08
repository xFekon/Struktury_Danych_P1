#include "Tablica_dynamiczna.h"
#include <iostream>
#include <cstdlib>
#include <vector>  // dla wyszukiwania wszystkich indeksów
#include <fstream>

using namespace std;


//private:
//int* tablica;
//int rozmiar, pojemnoœæ;

	Tablica_dynamiczna::Tablica_dynamiczna() : tablica(nullptr), rozmiar(0), pojemnoœæ(0){

	}  // konstruktor

	Tablica_dynamiczna::~Tablica_dynamiczna() {
		delete[] tablica;
	}  // destruktor


	void Tablica_dynamiczna::dodawanie(int wartoœæ, char pkl) {
		if (rozmiar == pojemnoœæ) {
			zwiêkszanie();
		}
		if (pkl == 'p') {
			for (int i = rozmiar; i > 0; i--) {
				tablica[i] = tablica[i - 1];
			}
			tablica[0] = wartoœæ;
		}
		else if (pkl == 'k') {
			tablica[rozmiar] = wartoœæ;
		}
		else if (pkl == 'l') {
			int indeks = rand() % (rozmiar + 1);
			for (int i = rozmiar; i > indeks; i--) {
				tablica[i] = tablica[i - 1];
			}
			tablica[indeks] = wartoœæ;
		}
		rozmiar++;
	}  // dodawanie nowego elementu (char pocz¹tek/koniec/losowo)

	void Tablica_dynamiczna::usuwanie(char pkl) {
		if (rozmiar == 0) return;
		if (pkl == 'p') {
			for (int i = 0; i < rozmiar - 1; i++) {
				tablica[i] = tablica[i + 1];
			}
		}
		else if (pkl == 'k') {
			// Nic nie trzeba robiæ, po prostu zmniejszamy rozmiar
		}
		else if (pkl == 'l') {
			int indeks = rand() % rozmiar;
			for (int i = indeks; i < rozmiar - 1; i++) {
				tablica[i] = tablica[i + 1];
			}
		}
		rozmiar--;
		zmniejszanie();
	}  // usuwanie elementu (char pocz¹tek/koniec/losowo)

	int Tablica_dynamiczna::szukanie(int wartoœæ) {
		for (int i = 0; i < rozmiar; i++) {
			if (tablica[i] == wartoœæ) {
				return i;
			}
		}
		return -1;
	}  // wyszukiwanie danej wartoœæi

	vector<int> Tablica_dynamiczna::szukanie_wszystkich(int wartoœæ) {
		vector<int> indeksy;
		for (int i = 0; i < rozmiar; i++) {
			if (tablica[i] == wartoœæ) {
				indeksy.push_back(i);
			}
		}
		return indeksy;
	}

	void Tablica_dynamiczna::zwiêkszanie() {
		int nowa_pojemnosc = (pojemnoœæ == 0) ? 1 : pojemnoœæ * 2;
		int* nowa_tablica = new int[nowa_pojemnosc];
		for (int i = 0; i < rozmiar; i++) {
			nowa_tablica[i] = tablica[i];
		}
		delete[] tablica;
		tablica = nowa_tablica;
		pojemnoœæ = nowa_pojemnosc;
	} // podwajanie pojemnoœci tablicy

	void Tablica_dynamiczna::zmniejszanie() {
		if (rozmiar <= pojemnoœæ / 4 && pojemnoœæ > 1) {
			int nowa_pojemnosc = pojemnoœæ / 2;
			int* nowa_tablica = new int[nowa_pojemnosc];
			for (int i = 0; i < rozmiar; i++) {
				nowa_tablica[i] = tablica[i];
			}
			delete[] tablica;
			tablica = nowa_tablica;
			pojemnoœæ = nowa_pojemnosc;
		}
	} // podwójne zmniejszanie pojemnoœci tablicy przy 25% pojemnoœci


	void Tablica_dynamiczna::wczytaj_z_pliku(const std::string& nazwa_pliku) {
		ifstream plik(nazwa_pliku);
		if (plik.is_open()) {
			int liczba;
			while (plik >> liczba) {
				this->dodawanie(liczba,'k');
			}
		}
		else {
			cout << "Nie uda³o siê otworzyæ pliku!" << endl;
		}
	}

	void Tablica_dynamiczna::utwórz_losowo(int rozmiar) {
		// Zak³adamy, ¿e mamy rozmiar do wype³nienia
		for (int i = 0; i < rozmiar; ++i) {
			// Generowanie losowej liczby ca³kowitej w przedziale od 0 do 100
			int losowa_liczba = rand() % 101;  // Zmienna w zakresie [0, 100]
			dodawanie(losowa_liczba, 'k');  // Dodawanie liczby do tablicy
		}
	}

	void Tablica_dynamiczna::wyczysc() {
		delete[] tablica;
		tablica = new int[1];
		rozmiar = 0;
		pojemnoœæ = 1;
	}

	void Tablica_dynamiczna::wyswietl() const {
		if (rozmiar == 0) {
			std::cout << "Tablica jest pusta." << std::endl;
			return;
		}

		std::cout << "Zawartoœæ tablicy: ";
		for (int i = 0; i < rozmiar; ++i) {
			std::cout << tablica[i] << " ";
		}
		std::cout << std::endl;
	}