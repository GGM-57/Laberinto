#include "Vista.h"
#include <iostream> 
using namespace std;

// Implementación del constructor
Vista::Vista()
{
    // Constructor vacío ya que la clase no necesita inicializar nada
}

// Implementación del método para mostrar el tablero
void Vista::mostrarTablero(const Tablero& t, const Avatar& a) {
    // Obtiene la posición actual del avatar usando getPosicion()
    auto pos = a.getPosicion();  // pos es un pair<int,int> con coordenadas (x,y)

    // Dibuja encabezado con números de columnas (1-10)
    cout << "    ";  // Espacios para alinear
    for (int j = 0; j < 10; ++j) {
        cout << j + 1 << "  ";  // Números de columna
    }
    cout << endl;

    // Dibuja borde superior del tablero
    cout << "   +" << string(10 * 3, '-') << "+" << endl;

    // Recorre cada fila del tablero
    for (int i = 0; i < 10; ++i) {
        // Muestra número de fila (1-10) con formato
        cout << (i + 1 < 10 ? " " : "") << i + 1 << " |"; 
        
        // Recorre cada columna de la fila actual
        for (int j = 0; j < 10; ++j) {
            // Si es la posición del avatar
            if (i == pos.first && j == pos.second) {
                cout << " ♞ ";  // Símbolo de caballo (avatar)
            }   
            // Si es la entrada (0,0)
            else if (i == 0 && j == 0){
                cout << " E ";  // 'E' de Entrada
            }
            // Si es la salida (9,9)
            else if (i==9 && j==9){
                cout << " S ";  // 'S' de Salida
            }
            // Si es un camino (valor 1)
            else if (t.getValor(i,j) == 1) {
                cout << " . ";  // Punto para camino
            }
            // Si es una pared (valor 0)
            else {
                cout << " █ ";  // Bloque sólido para pared
            }
        }
        cout << "|" << endl;  // Cierra el borde derecho
    }

    // Dibuja borde inferior del tablero
    cout << "   +" << string(10 * 3, '-') << "+" << endl;
}

// Implementación del destructor
Vista::~Vista()
{
    // No hay recursos que liberar
}
