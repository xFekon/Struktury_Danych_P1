#pragma once
class Tablica_dynamiczna
{
private:
	int* tablica;
	int rozmiar, pojemnoœæ;

public:
	Tablica_dynamiczna();  // konstruktor
	~Tablica_dynamiczna();  // destruktor

	void dodawanie(int wartoœæ, char pkl);  // dodawanie nowego elementu (char pocz¹tek/koniec/losowo)
	void usuwanie(char pkl);  // usuwanie elementu (char pocz¹tek/koniec/losowo)
	int szukanie(int wartoœæ);  // wyszukiwanie danej wartoœæi
	vector<int> szukanie_wszystkich(int wartoœæ);  // 
	void zwiêkszanie(); // podwajanie pojemnoœci tablicy
	void zmniejszanie(); // podwajanie pojemnoœci tablicy
};

