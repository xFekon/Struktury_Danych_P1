// Struktury_Danych_P1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <vector>
#include <numeric> // std::accumulate
#include "Pomiar_czasu.h"
#include <string>
#include <chrono>
#include <fstream>
#include <sstream>

using namespace std;



vector<int> wczytaj_zestaw_z_pliku(const string& sciezka, int numer_zestawu) {
    ifstream plik(sciezka);
    string linia;
    int aktualna = 0;

    while (getline(plik, linia)) {
        if (++aktualna == numer_zestawu) {
            stringstream ss(linia);
            vector<int> dane;
            int liczba;
            while (ss >> liczba)
                dane.push_back(liczba);
            return dane;
        }
    }
    return {};  // pusty jeśli nie znaleziono
}

int main()
{
    vector<int> rozmiary = { 5000, 8000, 10000, 16000, 20000, 40000, 60000, 100000 };
    string wynik_csv = "wyniki.csv";

    // Nagłówek pliku CSV
    ofstream wynik_file(wynik_csv);
    wynik_file << "Rozmiar,ŚredniCzas(us)\n";
    wynik_file.close();

    char tryb_operacji = 'p';  // 'p', 'k', 'l' — ustawiasz ręcznie
    string operacja = "Dodawanie";  // np. Dodawanie, Usuwanie, Szukanie

    for (int rozmiar : rozmiary) {
        vector<long long> wszystkie_pomiary;

        string plik_nazwa = "dane/dane_" + to_string(rozmiar) + ".txt";

        for (int zestaw = 1; zestaw <= 10; ++zestaw) {
            // Wczytaj dane z pliku
            
            vector<int> dane = wczytaj_zestaw_z_pliku(plik_nazwa, zestaw);

            for (int i = 0; i < 100; ++i) {
                // Skopiuj dane do nowego kontenera — bez modyfikowania oryginału
                vector<int> dane_kopia = dane;

                auto start = chrono::high_resolution_clock::now();

                // Wstaw operację testową — tylko jedną na raz:
                // -----------------------------------------------
                //Lista_jednokierunkowa struktura;
                Tablica_dynamiczna struktura;  // lub Lista_jednokierunkowa struktura;

                for (int wartosc : dane_kopia) {
                    //struktura.dodawanie(wartosc, tryb_operacji);
                    struktura.szukanie(791182);
                }
                // -----------------------------------------------

                auto end = chrono::high_resolution_clock::now();
                long long czas = chrono::duration_cast<chrono::microseconds>(end - start).count();
                wszystkie_pomiary.push_back(czas);
            }
        }

        // Oblicz średni czas dla danego rozmiaru
        long long suma = accumulate(wszystkie_pomiary.begin(), wszystkie_pomiary.end(), 0LL);
        double srednia = static_cast<double>(suma) / wszystkie_pomiary.size();

        // Zapisz do CSV
        ofstream wynik_file(wynik_csv, ios::app);
        wynik_file << rozmiar << "," << static_cast<long long>(srednia) << "\n";
        wynik_file.close();

        cout << "Zakonczono pomiar dla rozmiaru " << rozmiar << ": Średni czas = " << srednia << " µs" << endl;
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
