#include <iostream>
#include <tablero.h>
#include <jugador.h>
#include <partida.h>
#include <juego.h>

using namespace std;

int main()
{

    Juego juego;
    Partida partida;

    juego.start();
    juego.partidaj();
    while (!juego.findejuego()) {
        juego.turno();

        cout << "\nCasillas disponibles: " << (bsize * bsize - 4) - juego.finpartida() << endl;
    }

    juego.resfinal();
    juego.finpartida();
    partida.resultados();

    return 0;
}
