#include "juego.h"
#include "jugador.h"
#include <iostream>
using namespace std;

Juego::Juego()
{
    jugadores[0] = nullptr;
    jugadores[1] = nullptr;
    tablero = new Tablero();

}


Juego::~Juego() {
    delete jugadores[0];
    delete jugadores[1];
    delete tablero;

}

void Juego::start(){

    jugadores[0] = new Jugador("Jugador1", '-');
    jugadores[1] = new Jugador("Jugador2", '*');

    cout << "  ************ OTHELLO ************" << endl;
    tablero->startb();

}
void Juego::turno() {

    tablero->imprimir();

    cout << "\nTurno:" << jugadores[0]->getn()<< " - Ficha:'"<< jugadores[0]->getf()<<"'"<<endl;

    int fila;
    char columna;
    cout << "\nIngrese posicion: Columna (A-H) y fila (1-8). Ej (A1 | C7): ";
    cin >> columna >> fila;
    fila = fila-1;
    int convcol = columna - 'A';

    if (tablero->movimiento(fila, convcol, jugadores[0]->getf())) {
        tablero->giro(fila, convcol, jugadores[0]->getf());
        swap(jugadores[0], jugadores[1]);
        contador++;
    }
    else {
        cout << "Movimiento no valido. Intente nuevamente." << endl;
    }
}
int Juego::finpartida() {
    return contador;
}

