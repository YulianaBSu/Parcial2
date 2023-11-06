#include <iostream>
#include <tablero.h>
#include <jugador.h>
#include <partida.h>
#include <juego.h>
#include <historial.h>

using namespace std;

int main()
{

    Juego juego;

    juego.start();
    juego.partidaj();
    while (!juego.findejuego()) {
        juego.turno();

        cout << "\nCasillas disponibles: " << (bsize * bsize - 4) - juego.finpartida() << endl;
    }

    juego.resfinal();
    juego.finpartida();

    string resultado = juego.gpartida()->gresultadop();
    cout << resultado << endl;

    Historial historial;

    string opcion;
    cout << "Desea ver el historial de partidas? (s/n): ";
    cin >> opcion;

    if (opcion == "s" || opcion == "S") {
        cout << "\nHistorial de partidas\n" << endl;
        historial.imprimir();
    }
    else {
        return 0;
    }


    cout << "\nJuego terminado\n" << endl;


    return 0;
}
