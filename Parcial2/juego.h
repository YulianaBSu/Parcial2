#ifndef JUEGO_H
#define JUEGO_H
#include "jugador.h"
#include "tablero.h"

class Juego
{
private:
    Jugador* jugadores[2];
    Tablero* tablero;
    int contador=0;

public:
    Juego();
    ~Juego();
    void start();
    void partida();
    void turno();
    int finpartida();

};

#endif // JUEGO_H
