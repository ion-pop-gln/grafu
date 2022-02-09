// Se citesc:
//      n - nr de noduri al unui arbore
//      r - radacina
// int t[50]; - vectorul de tati
// 1) sa se afiseze frunzele (nodurile care nu apar in t)
// 2) pornind de la radacina sa se afiseze nodurile pe fiecare nivel:
// nivel 0: rad
// nivel 1: ...
// nivel 2: ...
// 3) sa se determine inaltimea arborelui
// 4) sa se det ordinul arborelui
// 5) se citesc doua nr a, b <= n. Sa se afiseze lantul ce pleaca
// din a si ajunge in b.

#include <iostream>
#include <fstream>

using namespace std;

void citire(int& n, int& r, int tati[]) {
    ifstream f("gafu.in");
    f >> n >> r;
    for (int i = 1; i <= n; i++)
        f >> tati[i];
}

void rezolva1(int& n, int& r, int tati[]) {
    cout << "1) ";
    int aparitii[50] {};
    for (int i = 1; i <= n; i++)
        aparitii[tati[i]] = 1;
    for (int i = 1; i <= n; i++)
        if (!aparitii[i])
            cout << i << " ";
    cout << endl;
}

void calcnivel(int r, int nod, int tati[], int nivele[]) {
    if (nod == r) {
        nivele[nod] = 1;
        return;
    }

    int tata = tati[nod];

    if (nivele[tata] == 0)
        calcnivel(r, tata, tati, nivele);
    
    nivele[nod] = nivele[tata] + 1;
}

void afisnivel(int n, int nivel, int nivele[]) {
    cout << "Nivel " << nivel << ": ";
    for (int i = 1; i <= n; i++)
        if (nivele[i] - 1 == nivel)
            cout << i << " ";
    cout << endl;
}

void rezolva2_si_3(int n, int r, int tati[]) {
    cout << "2)\n";
    int nivele[50] {};
    int nivelmax = 0;
    for (int i = 1; i <= n; i++) {
        calcnivel(r, i, tati, nivele);
        if (nivele[i] > nivelmax)
            nivelmax = nivele[i];
    }

    for (int i = 0; i < nivelmax; i++)
        afisnivel(n, i, nivele);

    cout << "3) " << (nivelmax-1) << endl;
}

void rezolva4(int& n, int& r, int tati[]) {
    cout << "4) ";
    int aparitii[50] {};
    for (int i = 1; i <= n; i++)
        ++aparitii[tati[i]];
    int aparmax = 0;
    for (int i = 1; i <= n; i++)
        if (aparitii[i] > aparmax)
            aparmax = aparitii[i];
    cout << aparmax << endl;
}

void rezolva5(int& n, int& r, int tati[]) {
    int a, b;
    cin >> a >> b;

    int lant_a[50], lant_b[50];

    int i_a = 0, curent_a = a;
    while (curent_a != r) {
        lant_a[i_a++] = curent_a;
        curent_a = tati[curent_a];
    }
    lant_a[i_a] = curent_a;

    int i_b = 0, curent_b = b;
    while (curent_b != r) {
        lant_b[i_b++] = curent_b;
        curent_b = tati[curent_b];
    }
    lant_b[i_b] = curent_b;

    while (i_a > 0 &&
        i_b > 0 &&
        lant_a[i_a - 1] == lant_b[i_b - 1]
    ) i_a--, i_b--;

    if (i_a == 0 && i_b == 0) {
        cout << "Nu exista.\n";
        return;
    }

    cout << "5) ";
    for (int i = 0; i <= i_a; i++)
        cout << lant_a[i] << " ";
    for (int i = i_b-1; i >= 0; i--)
        cout << lant_b[i] << " ";
    cout << endl;
}

int main() {
    int n, r, t[50];
    citire(n, r, t);

    rezolva1(n, r, t);
    rezolva2_si_3(n, r, t);
    rezolva4(n, r, t);
    rezolva5(n, r, t);
}