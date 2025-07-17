#ifndef VISTA_H
#define VISTA_H
#include "Tablero.h"
#include "Avatar.h"

class Vista
{
    public:
        Vista();
        void mostrarTablero(const Tablero& t, const Avatar& a);
        virtual ~Vista();

    protected:

    private:
};

#endif // VISTA_H
