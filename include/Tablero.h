//Geraldin Guerrero, Dana Gomez, Hilary Herrera. LABORATORIO 3
#ifndef TABLERO_H
#define TABLERO_H


class Tablero
{
    public:
        Tablero();
        void generarLaberinto(); // llena celdas con 1 y algunos 0
        void mostrar() const; // Muestra el laberinto en consola (const indica que no modifica el objeto)
        bool esValido(int x, int y) const;
        int getValor(int x, int y) const;

        virtual ~Tablero();   // Destructor virtual (para posible herencia)

    protected:

    private:
       int celdas[10][10];        // Matriz 10x10 que almacena el laberinto (1 = camino, 0 = pared)

};

#endif // TABLERO_H
