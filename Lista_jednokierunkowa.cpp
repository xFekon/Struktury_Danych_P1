#include "Lista_jednokierunkowa.h"
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

Node::Node(int val) : wartoœæ(val), next(nullptr) {}

Lista_jednokierunkowa::Lista_jednokierunkowa() : head(nullptr), tail(nullptr), rozmiar(0) {}

Lista_jednokierunkowa::~Lista_jednokierunkowa() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
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
        if (indeks == 0) {
            dodawanie(wartoœæ, 'p');
            return;
        }
        Node* temp = head;
        for (int i = 0; i < indeks - 1; i++) {
            temp = temp->next;
        }
        nowy->next = temp->next;
        temp->next = nowy;
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
    rozmiar--;
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

void Lista_jednokierunkowa::wyœwietl() {
    Node* temp = head;
    while (temp) {
        cout << temp->wartoœæ << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
