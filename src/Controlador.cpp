#include "Controlador.h"
#include <iostream>
using namespace std;

Controlador::Controlador(): avatar(&tablero)
{
    //ctor
}

void Controlador::ejecutar() {
    vista.mostrarTablero(tablero, avatar);
    avatar.buscarSalida();
    vista.mostrarTablero(tablero, avatar);
}

Controlador::~Controlador()
{
    //dtor
}
