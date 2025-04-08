#include "Lista_jednokierunkowa.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

Node::Node(int val) : wartoœæ(val), next(nullptr) {}

Lista_jednokierunkowa::Lista_jednokierunkowa() : head(nullptr), tail(nullptr), rozmiar(0) {}

/*
Lista_jednokierunkowa::Lista_jednokierunkowa(const Lista_jednokierunkowa& inna) : head(nullptr), tail(nullptr), rozmiar(0) {
    Node* temp = inna.head;
    while (temp) {
        this->dodawanie(temp->wartoœæ, 'k');  // dodawanie na koniec
        temp = temp->next;
    }
}
*/

Lista_jednokierunkowa::~Lista_jednokierunkowa() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void Lista_jednokierunkowa::dodawanie(int wartoœæ, char pkl) {
    Node* nowy = new Node(wartoœæ);
    if (!head) {
        head = tail = nowy;
    }
    else if (pkl == 'p') {
        nowy->next = head;
        head = nowy;
    }
    else if (pkl == 'k') {
        tail->next = nowy;
        tail = nowy;
    }
    else if (pkl == 'l') {
        int indeks = rand() % (rozmiar + 1);
        if (!head || indeks == 0) {
            dodawanie(wartoœæ, 'p');
            return;
        }
        Node* temp = head;
        for (int i = 0; i < indeks - 1; i++) {
            temp = temp->next;
        }
        nowy->next = temp->next;
        temp->next = nowy;
        if (nowy->next == nullptr) tail = nowy;  // poprawka: aktualizuj tail jeœli wstawiamy na koniec
    }
    rozmiar++;
}

void Lista_jednokierunkowa::usuwanie(char pkl) {
    if (!head) return;
    if (pkl == 'p') {
        Node* temp = head;
        head = head->next;
        delete temp;
        if (!head) tail = nullptr;
    }
    else if (pkl == 'k') {
        if (head == tail) {
            delete head;
            head = tail = nullptr;
			rozmiar = 0;
        }
        else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
    }
    else if (pkl == 'l') {
        int indeks = rand() % rozmiar;
        if (indeks == 0) {
            usuwanie('p');
            return;
        }
        Node* temp = head;
        for (int i = 0; i < indeks - 1; i++) {
            temp = temp->next;
        }
        Node* do_usuniecia = temp->next;
        temp->next = do_usuniecia->next;
        if (do_usuniecia == tail) tail = temp;
        delete do_usuniecia;
    }
	if (head) rozmiar--;
}

int Lista_jednokierunkowa::szukanie(int wartoœæ) {
    Node* temp = head;
    int indeks = 0;
    while (temp) {
        if (temp->wartoœæ == wartoœæ) return indeks;
        temp = temp->next;
        indeks++;
    }
    return -1;
}

vector<int> Lista_jednokierunkowa::szukanie_wszystkich(int wartoœæ) {
    vector<int> indeksy;
    Node* temp = head;
    int indeks = 0;
    while (temp) {
        if (temp->wartoœæ == wartoœæ) indeksy.push_back(indeks);
        temp = temp->next;
        indeks++;
    }
    return indeksy;
}

void Lista_jednokierunkowa::wyœwietl() const{
	if (!head) {
		cout << "Lista jest pusta." << endl;
		return;
	}
	Node* temp = head;
    while (temp) {
        cout << temp->wartoœæ << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void Lista_jednokierunkowa::wczytaj_z_pliku(const std::string& nazwa_pliku) {
    ifstream plik(nazwa_pliku);
    if (plik.is_open()) {
        int liczba;
        while (plik >> liczba) {
            this->dodawanie(liczba, 'k'); // Dodawanie na koniec
        }
    }
    else {
        cout << "Nie uda³o siê otworzyæ pliku!" << endl;
    }
}

void Lista_jednokierunkowa::utwórz_losowo(int rozmiar) {
    for (int i = 0; i < rozmiar; ++i) {
        // Generowanie losowej liczby ca³kowitej w przedziale od 0 do 100
        int losowa_liczba = rand() % 101;  // Zmienna w zakresie [0, 100]
        dodawanie(losowa_liczba, 'k');  // Dodawanie liczby na koniec listy
    }
}

void Lista_jednokierunkowa::wyczysc() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    rozmiar = 0;
}