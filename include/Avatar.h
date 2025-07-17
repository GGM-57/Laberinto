#ifndef AVATAR_H
#define AVATAR_H
#include "Tablero.h"
#include <utility>
using namespace std;

class Avatar //representa el soldado
{
    public:
        //metodo constructor
        Avatar(Tablero* t); //recibe un puntero al tablero para que el avatar consulte
        void colocarAleatoriamente();//colaca al avatar en una posicion aleatoria valida
        void mover();
        void buscarSalida();
        pair<int, int> getPosicion() const;

        virtual ~Avatar();

    protected:

    private:
        int x, y;
        Tablero* tablero;

};

#endif // AVATAR_H
