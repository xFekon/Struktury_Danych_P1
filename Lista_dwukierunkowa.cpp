#include "Lista_dwukierunkowa.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

DoubleNode::DoubleNode(int val) : wartoœæ(val), next(nullptr), prev(nullptr) {}

Lista_dwukierunkowa::Lista_dwukierunkowa() : head(nullptr), tail(nullptr), rozmiar(0) {}

Lista_dwukierunkowa::~Lista_dwukierunkowa() {
    wyczysc();
}

void Lista_dwukierunkowa::dodawanie(int wartoœæ, char pkl) {
    DoubleNode* nowy = new DoubleNode(wartoœæ);
    if (!head) {
        head = tail = nowy;
    }
    else if (pkl == 'p') {
        nowy->next = head;
        head->prev = nowy;
        head = nowy;
    }
    else if (pkl == 'k') {
        tail->next = nowy;
        nowy->prev = tail;
        tail = nowy;
    }
    else if (pkl == 'l') {
        int indeks = rand() % (rozmiar + 1);
        if (indeks == 0) {
            dodawanie(wartoœæ, 'p');
            return;
        }
        if (indeks == rozmiar) {
            dodawanie(wartoœæ, 'k');
            return;
        }

        DoubleNode* temp;
        if (indeks <= rozmiar / 2) {
            temp = head;
            for (int i = 0; i < indeks - 1; i++) {
                temp = temp->next;
            }
        }
        else {
            temp = tail;
            for (int i = rozmiar - 1; i > indeks - 1; --i) {
                temp = temp->prev;
            }
        }
        nowy->next = temp->next;
        nowy->prev = temp;
        temp->next->prev = nowy;
        temp->next = nowy;
    }
    rozmiar++;
}

void Lista_dwukierunkowa::usuwanie(char pkl) {
    if (!head) return;

    if (pkl == 'p') {
        DoubleNode* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }
    else if (pkl == 'k') {
        DoubleNode* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
    }
    else if (pkl == 'l') {
        if (rozmiar == 1) {
            usuwanie('p');
            return;
        }
        int indeks = rand() % rozmiar;
        if (indeks == 0) {
            usuwanie('p');
            return;
        }
        if (indeks == rozmiar - 1) {
            usuwanie('k');
            return;
        }

        DoubleNode* temp;
        if (indeks <= rozmiar / 2) {
            temp = head;
            for (int i = 0; i < indeks; i++) {
                temp = temp->next;
            }
        }
        else {
            temp = tail;
            for (int i = rozmiar - 1; i > indeks; i--) {
                temp = temp->prev;
            }
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
    rozmiar--;
}

int Lista_dwukierunkowa::szukanie(int wartoœæ) { // koñczy siê po znalezieniu pierwszej zgadzaj¹cejsie wartoœci
    DoubleNode* temp = head;
    int indeks = 0;
    while (temp) {
        if (temp->wartoœæ == wartoœæ) return indeks;
        temp = temp->next;
        indeks++;
    }
    return -1;
}

vector<int> Lista_dwukierunkowa::szukanie_wszystkich(int wartoœæ) { // zwraca indeksy wszystkich wartoœæi zgadzaj¹cych siê
    vector<int> indeksy;
    DoubleNode* temp = head;
    int indeks = 0;
    while (temp) {
        if (temp->wartoœæ == wartoœæ) indeksy.push_back(indeks);
        temp = temp->next;
        indeks++;
    }
    return indeksy;
}

void Lista_dwukierunkowa::wyœwietl() const { // wyœwietla ka¿dy node listy
    if (!head) {
        cout << "Lista jest pusta." << endl;
        return;
    }
    DoubleNode* temp = head;
    while (temp) {
        cout << temp->wartoœæ << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void Lista_dwukierunkowa::wczytaj_z_pliku(const std::string& nazwa_pliku) { // u¿ywana w testach funkcjonalnoœci (plik: "wczytaj_zpf.txt")
    ifstream plik(nazwa_pliku);
    if (plik.is_open()) {
        int liczba;
        while (plik >> liczba) {
            this->dodawanie(liczba, 'k');
        }
    }
    else {
        cout << "Nie uda³o siê otworzyæ pliku!" << endl;
    }
}

void Lista_dwukierunkowa::utwórz_losowo(int rozmiar) {  // dodaje dan¹ iloœæ wêz³ów z losowymi wartoœciami (wykorzystywana z wyczysc())
    for (int i = 0; i < rozmiar; ++i) {
        int losowa_liczba = rand() % 1000001;  // 0 do 1 000 000
        dodawanie(losowa_liczba, 'k');
    }
}

void Lista_dwukierunkowa::wyczysc() { // usuwa wszystkie node'y z listy 
    while (head) {
        DoubleNode* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    rozmiar = 0;
}