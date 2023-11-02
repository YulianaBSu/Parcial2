#include <iostream>
#include <tablero.h>
#include <jugador.h>
#include <partida.h>
#include <juego.h>

using namespace std;

int main()
{

    Juego juego;

    juego.start();
    while (juego.finpartida() < (bsize * bsize - 4)) {
        juego.turno();

        cout << "\nCasillas disponibles: " << (bsize * bsize - 4) - juego.finpartida() << endl;
    }
    cout << "\nJuego terminado\nSaliendo..."<< endl;

    return 0;
}
