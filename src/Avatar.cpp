#include "Avatar.h"
#include <iostream>
#include <cstdlib>  
#include <ctime>  
#include <queue>  
#include <vector>   
using namespace std;

// Constructor - inicializa el puntero tablero y coloca al avatar
Avatar::Avatar(Tablero* t) : tablero(t) {  // Inicializa el puntero tablero con t
    colocarAleatoriamente();  // Coloca al avatar en posición inicial aleatoria
}

void Avatar::colocarAleatoriamente() {
    srand(time(0));  // Semilla para números aleatorios
    do {
        x = rand() % 10;  // Coordenada x aleatoria (0-9)
        y = rand() % 10;  // Coordenada y aleatoria (0-9)
    } while (!tablero->esValido(x, y));  // Usa el PUNTERO tablero para verificar validez
    cout << "Avatar iniciado en: [" << (x+1) << "," << (y+1) << "]" << endl;
}

void Avatar::mover() {
    // Posibles movimientos: arriba, abajo, izquierda, derecha
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    // Intenta moverse en las 4 direcciones posibles
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];  // Nueva posición x
        int ny = y + dy[i];  // Nueva posición y
        
        // Usa el PUNTERO tablero para verificar si el movimiento es válido
        if (tablero->esValido(nx, ny)) {
            x = nx;  // Actualiza posición x
            y = ny;  // Actualiza posición y
            break;   // Solo se mueve una vez
        }
    }
}

void Avatar::buscarSalida() {
    // Estructuras para BFS:
    queue<pair<int, int>> cola;           // Cola para nodos por visitar
    bool visitado[10][10] = {false};      // Matriz de nodos visitados
    pair<int, int> padre[10][10];         // Matriz para reconstruir la ruta
    
    // Inicia BFS desde la posición actual
    cola.push({x, y});
    visitado[x][y] = true;
    padre[x][y] = {-1, -1};  // La posición inicial no tiene padre

    // Movimientos posibles (arriba, abajo, izquierda, derecha)
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!cola.empty()) {
        // Extrae coordenadas del frente de la cola
        auto [cx, cy] = cola.front(); cola.pop();  // Desestructuración C++17

        // Si llegamos a la salida (9,9)
        if (cx == 9 && cy == 9) {
            cout << "¡Salida encontrada!" << endl;
            
            // Reconstruye la ruta desde la salida hasta el inicio
            vector<pair<int,int>> ruta;
            while (cx != -1 && cy != -1) {  // Mientras no lleguemos al inicio
                ruta.push_back({cx, cy});
                tie(cx, cy) = padre[cx][cy];  // Usamos tie para desempaquetar el padre
            }

            // Mueve el avatar siguiendo la ruta (del final al inicio)
            for (auto it = ruta.rbegin(); it != ruta.rend(); ++it) {
                x = it->first;   // Accede al primer elemento del par con ->
                y = it->second; // Accede al segundo elemento del par con ->
                cout << "Paso: [" << (x+1) << "," << (y+1) << "]" << endl;
            }
            return;
        }

        // Explora vecinos
        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            // Verifica si el vecino es válido y no visitado
            if (tablero->esValido(nx, ny) && !visitado[nx][ny]) {
                visitado[nx][ny] = true;
                padre[nx][ny] = {cx, cy};  // Registra el padre para reconstruir ruta
                cola.push({nx, ny});        // Agrega a la cola para visitar después
            }
        }
    }
    cout << "No hay camino hacia la salida." << endl;
}

// Devuelve la posición actual como un par de enteros
pair<int, int> Avatar::getPosicion() const {
    return {x, y};  // Crea y retorna un pair con las coordenadas
}

// Destructor - no necesita liberar memoria ya que tablero es manejado externamente
Avatar::~Avatar()
{
    // No hay recursos dinámicos que liberar
}
