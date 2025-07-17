#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "Tablero.h"
#include "Avatar.h"
#include "Vista.h"

class Controlador
{
    public:
        Controlador();
        void ejecutar();
        virtual ~Controlador();

    protected:

    private:
        Tablero tablero;
        Avatar avatar;
        Vista vista;

};

#endif // CONTROLADOR_H
