#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <string>
#include <filesystem>

using namespace std;

// Generuje pojedynczy zestaw losowych liczb
vector<int> generuj_zestaw(int rozmiar, int min = 0, int max = 1000000) {
    vector<int> dane;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(min, max);

    for (int i = 0; i < rozmiar; ++i) {
        dane.push_back(distrib(gen));
    }

    return dane;
}

int main() {
    vector<int> rozmiary = { 5000, 8000, 10000, 16000, 20000, 40000, 60000, 100000 };
    int liczba_zestawow = 10;
    string folder = "dane";

    // Utwórz folder na dane, jeœli nie istnieje
    filesystem::create_directory(folder);

    for (int rozmiar : rozmiary) {
        string nazwa_pliku = folder + "/dane_" + to_string(rozmiar) + ".txt";
        ofstream plik(nazwa_pliku);

        for (int i = 0; i < liczba_zestawow; ++i) {
            vector<int> zestaw = generuj_zestaw(rozmiar);
            for (int j = 0; j < rozmiar; ++j) {
                plik << zestaw[j];
                if (j != rozmiar - 1)
                    plik << " ";
            }
            plik << "\n";  // nowy zestaw w nowej linii
        }

        plik.close();
        cout << "Wygenerowano: " << nazwa_pliku << endl;
    }

    return 0;
}