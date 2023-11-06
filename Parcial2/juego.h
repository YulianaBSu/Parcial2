#ifndef JUEGO_H
#define JUEGO_H
#include "jugador.h"
#include "tablero.h"
#include "partida.h"

class Juego
{
private:
    Jugador* jugadores[2];
    Tablero* tablero;
    Partida* partida;
    int contador=0;
    string resultadospartida;

public:
    Juego();
    ~Juego();
    void start();
    void partidaj();
    void turno();
    void resfinal();
    int finpartida();
    bool findejuego();
    Partida* gpartida() {
        return partida;
    }
};

#endif // JUEGO_H
