#ifndef AVATAR_H
#define AVATAR_H
#include "Tablero.h"
#include <utility>  // Para usar la plantilla pair
using namespace std;

class Avatar // Clase que representa al personaje que navegará el laberinto
{
    public:
        // Constructor que recibe un PUNTERO al tablero
        // El puntero permite al avatar acceder y modificar el tablero
        Avatar(Tablero* t);
        
        // Coloca al avatar en una posición aleatoria válida (donde haya camino)
        void colocarAleatoriamente();
        
        // Mueve el avatar a una posición adyacente válida
        void mover();
        
        // Busca la salida (posición 9,9) usando BFS (Breadth-First Search)
        void buscarSalida();
        
        // Devuelve la posición actual como un par de coordenadas (x,y)
    //Permite almacenar dos valores juntos como un solo objeto. Es como una "pareja" de valores que pueden ser de tipos diferentes.
        pair<int, int> getPosicion() const;

        // Destructor virtual para posible herencia
        virtual ~Avatar();

    private:
        int x, y;           // Coordenadas actuales del avatar
        Tablero* tablero;   // PUNTERO al tablero donde se mueve el avatar
};

#endif // AVATAR_H
