#include "Tablica_dynamiczna.h"
using namespace std;


	Tablica_dynamiczna::Tablica_dynamiczna() : tablica(nullptr), rozmiar(0), pojemnoœæ(0){

	}  // konstruktor

	Tablica_dynamiczna::~Tablica_dynamiczna() {
		delete[] tablica;
	}  // destruktor


	void Tablica_dynamiczna::dodawanie(int wartoœæ, char pkl) {
	
	}  // dodawanie nowego elementu (char pocz¹tek/koniec/losowo)

	void Tablica_dynamiczna::usuwanie(char pkl) {
	
	}  // usuwanie elementu (char pocz¹tek/koniec/losowo)

	int Tablica_dynamiczna::szukanie(int wartoœæ) {
	
	}  // wyszukiwanie danej wartoœæi

	void Tablica_dynamiczna::zwiêkszanie() {
	
	} // podwajanie pojemnoœci tablicy
