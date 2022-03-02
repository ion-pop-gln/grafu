#include <iostream>
#include <fstream>

int n {};
int adiacenta[100][100] {};
int tati[100] {};

void umple_tati(int rad, int tata) {
    tati[rad] = tata;
    adiacenta[rad][tata] = adiacenta[tata][rad] = 0;
    for (int i = 1; i <= n; i++)
        if (adiacenta[i][rad])
            umple_tati(i, rad);
}

int main() {
    std::ifstream fisier { "muchii.in" };

    fisier >> n;

    int rad {};
    fisier >> rad;

    for (int x {}, y {}; fisier >> x >> y;)
        adiacenta[x][y] = adiacenta[y][x] = 1;

    umple_tati(rad, 0);

    for (int i = 1; i <= n; i++)
        std::cout << tati[i] << " ";
    std::cout << std::endl;
}