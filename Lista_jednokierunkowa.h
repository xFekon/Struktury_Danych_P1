#pragma once
#ifndef LISTA_JEDNOKIERUNKOWA_H
#define LISTA_JEDNOKIERUNKOWA_H

#include <vector>

struct Node {
    int wartoœæ;
    Node* next;
    Node(int val);
};

class Lista_jednokierunkowa
{
private:
    Node* head;
    Node* tail;
    int rozmiar;

public:
    Lista_jednokierunkowa();
    ~Lista_jednokierunkowa();

    void dodawanie(int wartoœæ, char pkl);
    void usuwanie(char pkl);
    int szukanie(int wartoœæ);
    std::vector<int> szukanie_wszystkich(int wartoœæ);
    void wyœwietl();
};



#endif