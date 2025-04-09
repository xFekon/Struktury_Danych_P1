// Struktury_Danych_P1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <vector>
#include "Lista_jednokierunkowa.h"
#include "Tablica_dynamiczna.h"
#include "Lista_dwukierunkowa.h"
#include <string>
#include <chrono>
#include <fstream>
#include <sstream>
#include <random>

using namespace std;



vector<vector<int>> wczytaj_dane(const string& nazwa_pliku, int rozmiar) {
    ifstream plik(nazwa_pliku);
    vector<vector<int>> zbiory;
    for (int i = 0; i < 10; ++i) {
        vector<int> zbior;
        for (int j = 0; j < rozmiar; ++j) {
            int liczba;
            plik >> liczba;
            zbior.push_back(liczba);
        }
        zbiory.push_back(zbior);
    }
    return zbiory;
}
//lista.dodawanie(125466, 'l');  // lub 'p' dla początku, 'l' dla losowo
/*
random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<> distrib(0, 1000000);
                int losowa_liczba = distrib(gen);
*/
void test() {
    vector<int> rozmiary = { 5000, 8000, 10000, 16000, 20000, 40000, 60000, 100000 };
    string operacja = "l2_usuwanie_l"; // zmień dla różnych testów

    ofstream csv("wyniki_" + operacja + ".csv");
    csv << "rozmiar,czas_usredniony_ns\n";

    for (int rozmiar : rozmiary) {
        string plik_danych = "dane_" + to_string(rozmiar) + ".txt";
        vector<vector<int>> zbiory = wczytaj_dane(plik_danych, rozmiar);

        long long suma_czasu = 0;

        for (const auto& zbior : zbiory) {
            for (int i = 0; i < 100; ++i) {
                Lista_dwukierunkowa lista_2k;
                for (int liczba : zbior) {
                    lista_2k.dodawanie(liczba, 'k');
                }

                
                // Testowana operacja (dodanie jednego elementu na koniec)
                auto start = chrono::high_resolution_clock::now();
                lista_2k.usuwanie('l');
                auto end = chrono::high_resolution_clock::now();

                auto czas = duration_cast<chrono::nanoseconds>(end - start).count();
                suma_czasu += czas;
            }
        }

        double sredni_czas = static_cast<double>(suma_czasu) / (zbiory.size() * 100);
        csv << rozmiar << "," << sredni_czas << "\n";
        cout << "Zakonczono: " << rozmiar << " - średni czas: " << sredni_czas << " ns\n";
    }

    csv.close();
}

void menu_tablica() {
    Tablica_dynamiczna tablica;

    while (true) {
        int opcja;
        cout << "\nMenu Tablica Dynamiczna\n";
        cout << "1. Zbuduj z pliku\n";
        cout << "2. Usuń element\n";
        cout << "3. Dodaj element\n";
        cout << "4. Znajdź element\n";
        cout << "5. Utwórz losowo\n";
        cout << "6. Wyświetl\n";
        cout << "7. Wróć do głównego menu\n";
        cout << "Wybierz opcję: ";
        cin >> opcja;

        switch (opcja) {
        case 1: {
            tablica.wyczysc();
            string nazwa_pliku;
            cout << "Podaj nazwę pliku: ";
            cin >> nazwa_pliku;
            tablica.wczytaj_z_pliku(nazwa_pliku);
            break;
        }
        case 2: {
            char tryb;
            cout << "Podaj gdzie usunąć: ";
            cin >> tryb;
            tablica.usuwanie(tryb); // Zakładając, że masz odpowiednią metodę usuwania
            break;
        }
        case 3: {
            int wartosc;
            char tryb;
            cout << "Podaj wartość do dodania: ";
            cin >> wartosc;
            cout << "Podaj gdzie dodac(p, k, l): ";
            cin >> tryb;
            tablica.dodawanie(wartosc, tryb);
            break;
        }
        case 4: {
            int wartosc;
            cout << "Podaj wartość do znalezienia: ";
            cin >> wartosc;
            int wynik = tablica.szukanie(wartosc);
            if (wynik != -1) {
                cout << "Znaleziono element na pozycji " << wynik << endl;
            }
            else {
                cout << "Element nie został znaleziony." << endl;
            }
            break;
        }
        case 5: {
            tablica.wyczysc();
            int rozmiar;
            cout << "Podaj rozmiar do wygenerowania: ";
            cin >> rozmiar;
            tablica.utwórz_losowo(rozmiar);
            break;
        }
        case 6: {
            tablica.wyswietl();
            break;
        }
        case 7:
            return;
        default:
            cout << "Niepoprawna opcja. Spróbuj ponownie." << endl;
        }
    }
}

void menu_lista() {
    Lista_jednokierunkowa lista;

    while (true) {
        int opcja;
        cout << "\nMenu Lista Jednokierunkowa\n";
        cout << "1. Zbuduj z pliku\n";
        cout << "2. Usun element\n";
        cout << "3. Dodaj element\n";
        cout << "4. Znajdz element\n";
        cout << "5. Utworz losowo\n";
        cout << "6. Wyswietl\n";
        cout << "7. Wroc do glownego menu\n";
        cout << "Wybierz opcje: ";
        cin >> opcja;

        switch (opcja) {
        case 1: {
            lista.wyczysc();
            string nazwa_pliku;
            cout << "Podaj nazwe pliku: ";
            cin >> nazwa_pliku;
            lista.wczytaj_z_pliku(nazwa_pliku);
            break;
        }
        case 2: {
            char tryb;
            cout << "Podaj gdzie usunac: ";
            cin >> tryb;
            lista.usuwanie(tryb); // Zakładając, że masz odpowiednią metodę usuwania
            break;
        }
        case 3: {
            int wartosc;
            char tryb;
            cout << "Podaj wartosc do dodania: ";
            cin >> wartosc;
            cout << "Podaj gdzie dodac(p, k, l): ";
            cin >> tryb;
            lista.dodawanie(wartosc, tryb);
            break;
        }
        case 4: {
            int wartosc;
            cout << "Podaj wartosc do znalezienia: ";
            cin >> wartosc;
            int wynik = lista.szukanie(wartosc);
            if (wynik != -1) {
                cout << "Znaleziono element na pozycji " << wynik << endl;
            }
            else {
                cout << "Element nie zostal znaleziony." << endl;
            }
            break;
        }
        case 5: {
            lista.wyczysc();
            int rozmiar;
            cout << "Podaj rozmiar do wygenerowania: ";
            cin >> rozmiar;
                lista.utwórz_losowo(rozmiar);
            
            break;
        }
        case 6: {
            lista.wyświetl();
            break;
        }
        case 7:
            return;
        default:
            cout << "Niepoprawna opcja. Sprobuj ponownie." << endl;
        }
    }
}

void menu_lista_dwukierunkowa() {
    Lista_dwukierunkowa lista_2k;

    while (true) {
        int opcja;
        cout << "\nMenu Lista Dwukierunkowa\n";
        cout << "1. Zbuduj z pliku\n";
        cout << "2. Usuń element\n";
        cout << "3. Dodaj element\n";
        cout << "4. Znajdź element\n";
        cout << "5. Utwórz losowo\n";
        cout << "6. Wyswietl\n";
        cout << "7. Wroc do glownego menu\n";
        cout << "Wybierz opcje: ";
        cin >> opcja;

        switch (opcja) {
        case 1: {
            lista_2k.wyczysc();
            string nazwa_pliku;
            cout << "Podaj nazwe pliku: ";
            cin >> nazwa_pliku;
            lista_2k.wczytaj_z_pliku(nazwa_pliku);
            break;
        }
        case 2: {
            char tryb;
            cout << "Podaj gdzie usunac (p - początek, k - koniec, l - losowo): ";
            cin >> tryb;
            lista_2k.usuwanie(tryb);
            break;
        }
        case 3: {
            int wartosc;
            char tryb;
            cout << "Podaj wartosc do dodania: ";
            cin >> wartosc;
            cout << "Podaj gdzie dodać (p - poczatek, k - koniec, l - losowo): ";
            cin >> tryb;
            lista_2k.dodawanie(wartosc, tryb);
            break;
        }
        case 4: {
            int wartosc;
            cout << "Podaj wartosc do znalezienia: ";
            cin >> wartosc;
            int wynik = lista_2k.szukanie(wartosc);
            if (wynik != -1) {
                cout << "Znaleziono element na pozycji " << wynik << endl;
            }
            else {
                cout << "Element nie został znaleziony." << endl;
            }
            break;
        }
        case 5: {
            lista_2k.wyczysc();
            int rozmiar;
            cout << "Podaj rozmiar do wygenerowania: ";
            cin >> rozmiar;
            lista_2k.utwórz_losowo(rozmiar);
            break;
        }
        case 6: {
            lista_2k.wyświetl();
            break;
        }
        case 7:
            return;
        default:
            cout << "Niepoprawna opcja. Sprobuj ponownie." << endl;
        }
    }
}

int main()
{
    while (true) { // Operująca całe Menu, dopóki nie wybierzemy opcji 3
        int opcja;
        cout << "Menu Glowne\n";
        cout << "1. Wykonaj test\n";
        cout << "2. Testuj funkcjonalnosci\n";
        cout << "3. Zakoncz program\n";
        cout << "Wybierz opcje: ";
        cin >> opcja;

        if (opcja == 1) {
            test();  // Wykonanie testu
        }
        else if (opcja == 2) {
            int struktura;
            cout << "Wybierz strukture:\n";
            cout << "1. Tablica Dynamiczna\n";
            cout << "2. Lista Jednokierunkowa\n";
            cout << "3. Lista Dwukierunkowa\n";
            cout << "Wybierz opcje: ";
            cin >> struktura;

            if (struktura == 1) {
                menu_tablica();  // Menu dla tablicy
            }
            else if (struktura == 2) {
                menu_lista();  // Menu dla listy jednokierunkowej
            }
            else if (struktura == 3) {
                menu_lista_dwukierunkowa(); // Menu dla listy dwukierunkowej
            }
            else {
                cout << "Niepoprawny wybor.\n";
            }
        }
        else if(opcja == 3){
            return 0;
        }
        else {
            cout << "Niepoprawna opcja.\n";
        }
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
