#pragma once
#include <string>
#include <vector>
#include "Tablica_dynamiczna.h"
#include "Lista_jednokierunkowa.h"

class Pomiar_czasu
{
public:
    static void testuj_dodawanie(const std::vector<int>& dane, char tryb, const std::string& wynik_csv);
    static void testuj_usuwanie(const std::vector<int>& dane, char tryb, const std::string& wynik_csv);
    static void testuj_szukanie(const std::vector<int>& dane, const std::string& wynik_csv);
};

