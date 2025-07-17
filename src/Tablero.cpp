#include "Tablero.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//constructor
Tablero::Tablero() {
    generarLaberinto();
}

void Tablero::generarLaberinto() {
    srand(time(0));
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            celdas[i][j] = (rand() % 100 < 75) ? 1 : 0; // 75% chance de ser camino

    celdas[9][9] = 1; // La salida siempre es accesible
}

void Tablero::mostrar() const {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j)
            cout << celdas[i][j] << " ";
        cout << endl;
    }
}

bool Tablero::esValido(int x, int y) const {
    return (x >= 0 && x < 10 && y >= 0 && y < 10 && celdas[x][y] == 1);
}

int Tablero::getValor(int x, int y) const {
    return celdas[x][y];
}



Tablero::~Tablero()
{
    //dtor
}
