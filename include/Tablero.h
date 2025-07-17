#ifndef TABLERO_H
#define TABLERO_H


class Tablero
{
    public:
        Tablero();
        void generarLaberinto(); // llena celdas con 1 y algunos 0
        void mostrar() const;
        bool esValido(int x, int y) const;
        int getValor(int x, int y) const;

        virtual ~Tablero();

    protected:

    private:
       int celdas[10][10];

};

#endif // TABLERO_H
