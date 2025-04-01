#pragma once
class Tablica_dynamiczna
{
private:
	int* tablica;
	int rozmiar, pojemnoœæ;

public:
	Tablica_dynamiczna();  // konstruktor
	~Tablica_dynamiczna();  // destruktor

	void dodawanie(int wartoœæ, int index);  // dodawanie nowego elementu
	void usuwanie(int index);  // usuwanie elementu 
	int szukanie(int wartoœæ);  // wyszukiwanie danej wartoœæi
	void zwiêkszanie(); // podwajanie pojemnoœci tablicy
};

