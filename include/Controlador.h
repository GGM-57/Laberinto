//Geraldin Guerrero, Dana Gomez, Hilary Herrera. LABORATORIO 3
#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Tablero.h"  // Para gestionar el laberinto
#include "Avatar.h"   // Para controlar el personaje
#include "Vista.h"    // Para mostrar la interfaz visual

class Controlador
{
    public:
        Controlador();  // Constructor
        
        // Método principal que ejecuta el flujo del programa
        void ejecutar();
        
        virtual ~Controlador();  // Destructor virtual para posible herencia

    private:
        Tablero tablero;  // Objeto que representa el laberinto
        Avatar avatar;    // Objeto que representa el personaje
        Vista vista;      // Objeto que maneja la visualización
};

#endif // CONTROLADOR_H
