//Geraldin Guerrero, Dana Gomez, Hilary Herrera. LABORATORIO 3
#ifndef VISTA_H
#define VISTA_H
// Protección contra inclusiones múltiples del archivo de cabecera

#include "Tablero.h"  // Necesario para mostrar el tablero
#include "Avatar.h"   // Necesario para mostrar la posición del avatar

class Vista
{
    public:
        Vista();  // Constructor básico
        
        // Método para mostrar gráficamente el tablero con el avatar
        // Recibe referencias constantes al tablero y al avatar
        void mostrarTablero(const Tablero& t, const Avatar& a);
        
        virtual ~Vista();  // Destructor virtual para posible herencia

    private:
        // No tiene atributos privados, solo funciona como interfaz visual
};

#endif // VISTA_H
