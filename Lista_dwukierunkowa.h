#pragma once
#ifndef LISTA_DWUKIERUNKOWA_H
#define LISTA_DWUKIERUNKOWA_H
#include <string>
#include <vector>

struct DoubleNode {
    int wartoœæ;
    DoubleNode* next;
    DoubleNode* prev;
    DoubleNode(int val);
};

class Lista_dwukierunkowa
{
private:
    DoubleNode* head;
    DoubleNode* tail;
    int rozmiar;

public:
    Lista_dwukierunkowa();
    ~Lista_dwukierunkowa();

    void dodawanie(int wartoœæ, char pkl);
    void usuwanie(char pkl);
    int szukanie(int wartoœæ);
    std::vector<int> szukanie_wszystkich(int wartoœæ);
    void wyœwietl() const;
    void wczytaj_z_pliku(const std::string& nazwa_pliku);
    void utwórz_losowo(int rozmiar);
    void wyczysc();
};

#endif

