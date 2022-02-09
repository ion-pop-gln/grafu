#include <iostream>
#include <fstream>

int a[20][20];
int n, k;
int x[22];

void init() {
    x[k] = 0;
}

int succesor() {
    if (x[k] < n) {
        x[k]++;
        return 1;
    }

    return 0;
}

int valid() {
    int i;
    for (i = 1; i < k; i++)
        if (x[i] == x[k]) return 0;
    
    if (a[x[k]][x[k - 1]] == 0)
        return 0;

    if (k == n && x[k] != 1)
        return 0;

    return 1;
}

void citire() {
    std::ifstream f("matrice.in");
    int i, j;
    f >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            f >> a[i][j];
}

int solutie() {
    return k == n;
}

void tipar() {
    int i;
    for (i = 0; i <= n; i++)
        std::cout << x[i] << " ";
    std::cout << std::endl;
    std::exit(0);
}

void back() {
    int as;
    k = 1;
    init();
    while (k > 0) {
        do {
            as = succesor();
        } while (as && !valid());
        if (as) {
            if (solutie())
                tipar();
            else {
                k++;
                init();
            }
        } else k--;
    }
}

int main() {
    x[0] = 1;
    citire();
    back();
}