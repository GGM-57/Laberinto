#include <iostream>
#include "Controlador.h"
using namespace std;

int main() {
    Controlador app; //crea una instancia de la clase Controlador - app
    //dentro de controlador se inicializa Tablero, Avatar, Vista
    app.ejecutar();//ejecuta la logica del juego: mostrar tablero, mover avatar, buscar salida
    return 0;
}
