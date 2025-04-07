#include "Pomiar_czasu.h"
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

void zapisz_wynik(const string& nazwa_pliku, const string& struktura, const string& operacja, char tryb, int rozmiar, long long czas) {
    ofstream plik(nazwa_pliku, ios::app);  // tryb dopisywania
    if (plik.is_open()) {
        plik << struktura << "," << operacja << "," << tryb << "," << rozmiar << "," << czas << "\n";
        plik.close();
    }
}

void Pomiar_czasu::testuj_dodawanie(const vector<int>& dane, char tryb, const string& wynik_csv) {
    // Tablica
    Tablica_dynamiczna tablica;
    auto start = high_resolution_clock::now();
    for (int wartosc : dane)
        tablica.dodawanie(wartosc, tryb);
    auto end = high_resolution_clock::now();
    zapisz_wynik(wynik_csv, "Tablica", "Dodawanie", tryb, dane.size(), duration_cast<microseconds>(end - start).count());

    // Lista
    Lista_jednokierunkowa lista;
    start = high_resolution_clock::now();
    for (int wartosc : dane)
        lista.dodawanie(wartosc, tryb);
    end = high_resolution_clock::now();
    zapisz_wynik(wynik_csv, "Lista", "Dodawanie", tryb, dane.size(), duration_cast<microseconds>(end - start).count());
}

void Pomiar_czasu::testuj_usuwanie(const vector<int>& dane, char tryb, const string& wynik_csv) {
    // Tablica
    Tablica_dynamiczna tablica;
    for (int w : dane) tablica.dodawanie(w, 'k');
    auto start = high_resolution_clock::now();
    for (size_t i = 0; i < dane.size(); ++i)
        tablica.usuwanie(tryb);
    auto end = high_resolution_clock::now();
    zapisz_wynik(wynik_csv, "Tablica", "Usuwanie", tryb, dane.size(), duration_cast<microseconds>(end - start).count());

    // Lista
    Lista_jednokierunkowa lista;
    for (int w : dane) lista.dodawanie(w, 'k');
    start = high_resolution_clock::now();
    for (size_t i = 0; i < dane.size(); ++i)
        lista.usuwanie(tryb);
    end = high_resolution_clock::now();
    zapisz_wynik(wynik_csv, "Lista", "Usuwanie", tryb, dane.size(), duration_cast<microseconds>(end - start).count());
}

void Pomiar_czasu::testuj_szukanie(const vector<int>& dane, const string& wynik_csv) {
    // Szukana wartoœæ — losowa z danych
    int wartosc = dane[dane.size() / 2];  // dla powtarzalnoœci

    // Tablica
    Tablica_dynamiczna tablica;
    for (int w : dane) tablica.dodawanie(w, 'k');
    auto start = high_resolution_clock::now();
    tablica.szukanie(wartosc);
    auto end = high_resolution_clock::now();
    zapisz_wynik(wynik_csv, "Tablica", "Szukanie", '-', dane.size(), duration_cast<microseconds>(end - start).count());

    // Lista
    Lista_jednokierunkowa lista;
    for (int w : dane) lista.dodawanie(w, 'k');
    start = high_resolution_clock::now();
    lista.szukanie(wartosc);
    end = high_resolution_clock::now();
    zapisz_wynik(wynik_csv, "Lista", "Szukanie", '-', dane.size(), duration_cast<microseconds>(end - start).count());
}