#include <utility>

using namespace std;

// Ejercicio 15
// Incompleto, no tomá cumple todo lo pedido en las pociones.

// Juego

using Pos = pair<int, int>;

char ARRIBA = '^';
char ABAJO = 'v'; 
char DERECHA = '<';
char IZQUIERDA = '>';

class Juego {
    public:
        Juego(uint casilleros, Pos pos_inicial);
        Pos posicion_jugador();
        uint turno_actual();
        void mover_jugador(char dir);
        void ingerir_pocion(uint movimientos, uint turnos);
    private:
        uint _casilleros;
        Pos _posicion;
        uint _turno;
        uint _turnosRestantes;
        uint _movimientos;
};

Juego::Juego(uint casilleros, Pos pos_inicial):
    _casilleros(casilleros),
    _posicion(pos_inicial),
    _turno(0),
    _turnosRestantes(0),
    _movimientos(1) {};

Pos Juego::posicion_jugador() {
    return _posicion;
}

uint Juego::turno_actual() {
    return _turno;
}

void Juego::mover_jugador(char dir) {
    _turno++;
    _turnosRestantes--;
    if (_turnosRestantes == 0) {
        _movimientos = 1;
    }
    if (dir == ARRIBA) {
        if (_posicion.first > 0) {
            _posicion.first -= _movimientos;
        }
    } else if (dir == ABAJO) {
        if (_posicion.first < _casilleros - 1) {
            _posicion.first += _movimientos;
        }
    } else if (dir == DERECHA) {
        if (_posicion.second < _casilleros-1) {
            _posicion.second += _movimientos;
        }
    } else {
        if (_posicion.second > 0) {
            _posicion.second -= _movimientos;
        }
    }
}

void Juego::ingerir_pocion(uint movimientos, uint turnos) {
    _movimientos = movimientos;
    _turnosRestantes = turnos;
}


