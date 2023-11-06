#include "juego.h"
#include "jugador.h"
#include <iostream>
using namespace std;

Juego::Juego()
{
    jugadores[0] = nullptr;
    jugadores[1] = nullptr;
    tablero = new Tablero();
    partida = new Partida();

}


Juego::~Juego() {
    delete jugadores[0];
    delete jugadores[1];
    delete tablero;
    delete partida;

}

void Juego::start(){

    jugadores[0] = new Jugador("Jugador1", '-');
    jugadores[1] = new Jugador("Jugador2", '*');

}


void Juego::partidaj() {
    cout << "  ************ OTHELLO ************" << endl;
    tablero->startb(jugadores[0]->getf(), jugadores[1]->getf());

}

void Juego::turno() {

    tablero->imprimir();

    cout << "\nTurno:" << jugadores[0]->getn()<< " - Ficha:'"<< jugadores[0]->getf()<<"'"<<endl;

    if (!tablero->ifmovalid(jugadores[0]->getf())) {
        cout << "No hay movimientos validos. El jugador cede el turno." << endl;
        swap(jugadores[0], jugadores[1]);
        return;
    }

    int fila;
    char columna;
    cout << "\nIngrese posicion: Columna (A-H) y fila (1-8). Ej (A1 | C7): ";
    cin >> columna >> fila;
    fila = fila-1;
    int convcol = columna - 'A';


    if (tablero->movimiento(fila, convcol, jugadores[0]->getf())) {
        tablero->giro(fila, convcol, jugadores[0]->getf());
        tablero->cfichas(jugadores[0]->getf(), jugadores[1]->getf());
        swap(jugadores[0], jugadores[1]);
        contador++;
    }
        else {
            cout << "Movimiento no valido. Intente nuevamente." << endl;
        }
    }


void Juego::resfinal() {
    tablero->imprimir();
    cout << "\nPartida terminada\n"<< endl;

}

bool Juego::findejuego() {
    return !tablero->ifmovalid(jugadores[0]->getf()) &&
           !tablero->ifmovalid(jugadores[1]->getf());

    cout << "Partida terminada, fin del juego" << endl;
}

int Juego::finpartida() {
    string resultadospartida = "Fecha y hora :" + partida->reghorayfecha() + tablero->ganadorp(jugadores[0]->getn(), jugadores[1]->getn());
    partida->sresultadop(resultadospartida);

    return contador;
}

