#include "Controlador.h"
#include <iostream> 
using namespace std;

// Implementación del constructor
Controlador::Controlador(): avatar(&tablero)
{
    /*
     * Lista de inicialización:
     * - avatar se inicializa pasando la dirección del tablero (&tablero)
     * - tablero y vista se inicializan con sus constructores por defecto
     */
}

// Implementación del método principal que coordina todo el flujo del programa
void Controlador::ejecutar() {
    // 1. Muestra el tablero inicial con la posición del avatar
    vista.mostrarTablero(tablero, avatar);
    
    // 2. Ejecuta el algoritmo para buscar la salida (BFS)
    avatar.buscarSalida();
    
    // 3. Muestra el tablero final con el camino encontrado
    vista.mostrarTablero(tablero, avatar);
}

// Implementación del destructor
Controlador::~Controlador()
{
    // No hay recursos dinámicos que liberar
    // Los objetos miembro (tablero, avatar, vista) se destruyen automáticamente
}
