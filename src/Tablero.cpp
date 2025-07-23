//Geraldin Guerrero, Dana Gomez, Hilary Herrera. LABORATORIO 3
#include "Tablero.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// constructor
Tablero::Tablero() {
    generarLaberinto(); // Al crear un tablero, genera el laberinto automáticamente
}

// Genera un laberinto aleatorio
void Tablero::generarLaberinto() {
    srand(time(0)); // Semilla para números aleatorios basada en el tiempo actual
    
    // Llena la matriz con 75% de probabilidad de camino (1) y 25% de pared (0)
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            celdas[i][j] = (rand() % 100 < 75) ? 1 : 0; 
        }
    }
    celdas[9][9] = 1; // La salida siempre es accesible
}

// Muestra el laberinto en consola
void Tablero::mostrar() const {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << celdas[i][j] << " "; // Imprime cada celda seguida de espacio
        }
        cout << endl; // Salto de línea al final de cada fila
    }
}

// Verifica si una posición es válida para moverse
bool Tablero::esValido(int x, int y) const {
    // Comprueba:
    // 1. Que esté dentro de los límites (0-9)
    // 2. Que sea un camino (valor 1)
    return (x >= 0 && x < 10 && y >= 0 && y < 10 && celdas[x][y] == 1);
}

// Devuelve el valor de una celda específica
int Tablero::getValor(int x, int y) const {
    return celdas[x][y]; // Retorna 1 (camino) o 0 (pared)
}



Tablero::~Tablero()
{
    //dtor
}
