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
    string jugadorganador;
    friend class Partida;

public:
    Juego();
    ~Juego();
    void start();
    void partidaj();
    void turno();
    int finpartida();

};

#endif // JUEGO_H
