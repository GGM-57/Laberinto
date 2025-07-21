#include "Vista.h"
#include <iostream>
using namespace std;

Vista::Vista()
{
    //ctor
}

void Vista::mostrarTablero(const Tablero& t, const Avatar& a) {
    auto pos = a.getPosicion();

    /*
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (i == pos.first && j == pos.second)
                cout << "A ";
            else
                cout << t.getValor(i, j) << " ";
        }
        cout << endl;
    }*/

    cout << "    ";
    for (int j = 0; j < 10; ++j) {
        cout << j + 1 << "  ";
    }
    cout << endl;

    cout << "   +" << string(10 * 3, '-') << "+" << endl;

    for (int i = 0; i < 10; ++i) {
        cout << (i + 1 < 10 ? " " : "") << i + 1 << " |"; // Índice de fila
        for (int j = 0; j < 10; ++j) {
            if (i == pos.first && j == pos.second) {
                cout << " ♞ ";
            }   
            else if (i == 0 && j == 0){
                cout << "E";
            }
            else if (i==9 && j==9){
                cout<< "S";
            }
            else if (t.getValor(i,j)== 1) {
                cout << ". ";
            }
            else {
                cout << "█";
            }
        }
        cout << endl;
    }

    cout << "   +" << string(10 * 3, '-') << "+" << endl;
}


Vista::~Vista()
{
    //dtor
}
