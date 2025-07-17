#include "Avatar.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <vector>
using namespace std;

Avatar::Avatar(Tablero* t) : tablero(t) {
    colocarAleatoriamente();
}

void Avatar::colocarAleatoriamente() {
    srand(time(0));
    do {
        x = rand() % 10;
        y = rand() % 10;
    } while (!tablero->esValido(x, y));
    cout << "Avatar iniciado en: [" << (x+1) << "," << (y+1) << "]" << endl;
}

void Avatar::mover() {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (tablero->esValido(nx, ny)) {
            x = nx;
            y = ny;
            break;
        }
    }
}

void Avatar::buscarSalida() {

    /* no encuentra la salida
    for (int i = 0; i < 100; ++i) {
        mover();
        if (x == 9 && y == 9) {
            cout << "¡Salida encontrada en [9,9]!" << endl;
            return;
        }
    }
    cout << "No se encontro la salida en 100 movimientos." << endl;*/

    //algotimo BFS
    queue<pair<int, int>> cola;
    bool visitado[10][10] = {false};
    pair<int, int> padre[10][10];

    cola.push({x, y});
    visitado[x][y] = true;
    padre[x][y] = {-1, -1};

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!cola.empty()) {
        auto [cx, cy] = cola.front(); cola.pop();

        if (cx == 9 && cy == 9) {
            cout << "¡Salida encontrada!" << endl;

            vector<pair<int,int>> ruta;
            while (cx != -1 && cy != -1) {
                ruta.push_back({cx, cy});
                tie(cx, cy) = padre[cx][cy];
            }

            // Mover el avatar al final de la ruta
            for (auto it = ruta.rbegin(); it != ruta.rend(); ++it) {
                x = it->first;
                y = it->second;
                cout << "Paso: [" << (x+1) << "," << (y+1) << "]" << endl;
            }

            return;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (tablero->esValido(nx, ny) && !visitado[nx][ny]) {
                visitado[nx][ny] = true;
                padre[nx][ny] = {cx, cy};
                cola.push({nx, ny});
            }
        }
    }

    cout << "No hay camino hacia la salida." << endl;

}

pair<int, int> Avatar::getPosicion() const {
    return {x, y};
}

Avatar::~Avatar()
{
    //dtor
}
