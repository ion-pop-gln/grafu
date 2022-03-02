#include <iostream>
#include <fstream>

int n {};
int adiacenta[100][100] {};
int coada[100] {};
int coada_prim { 0 }, coada_ultim { 0 };
int vazute[100] {};

bool urmatorul_nivel() {
    int coada_ultim_vechi { coada_ultim };
    
    // Trecem prin toate nodurile de pe nivel
    for (; coada_prim < coada_ultim_vechi; coada_prim++) {
        std::cout << coada[coada_prim] << " ";

        // Marcam nodul ca parcurs
        vazute[coada[coada_prim]] = 1;

        // Punem descendentii directi in coada
        for (int j = 1; j <= n; j++)
            if (adiacenta[coada[coada_prim]][j] && !vazute[j])
                coada[coada_ultim++] = j;
    }

    std::cout << std::endl;

    // Daca coada e goala, am terminat
    return coada_prim != coada_ultim;
}

int main() {
    std::ifstream fisier { "muchii.in" };

    fisier >> n >> coada[coada_ultim++];

    for (int x {}, y {}; fisier >> x >> y;)
        adiacenta[x][y] = adiacenta[y][x] = 1;

    int nivel = 0;

    do
        std::cout << nivel++ << ": ";
    while (urmatorul_nivel());
}