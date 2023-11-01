#include <iostream>
#include <tablero.h>
#include <jugador.h>
#include <partida.h>

using namespace std;





int main()
{
    Jugador jugador1("Jugador1", '*');
    Jugador jugador2("Jugador2", '-');

    cout << "Jugadores:" << endl;
    cout << jugador1.getn() << " - Ficha: " << jugador1.getf() << endl;
    cout << jugador2.getn() << " - Ficha: " << jugador2.getf() << "\n" << endl;

    Partida partida(&jugador1, &jugador2);
    partida.initpartida();

    Tablero tablero;
    tablero.startb();
    tablero.imprimir();

    int fila;
    char columna;
    char ficha;

    cout << "Turno de " << jugador1.getn() << " ("<< jugador1.getf()<< "). Ingrese fila (1-8) y columna (A-H) separadas por espacio: ";
    cin >> fila >> columna;
    ficha = jugador1.getf();
    int convcol = columna - 'A';
    fila--;

    if (tablero.movimiento(fila, convcol, ficha)) {
        tablero.imprimir();
    } else {
        cout << "Movimiento invalido" << endl;
    }

    cout << "Turno de " << jugador2.getn() << " ("<< jugador2.getf()<< "). Ingrese fila (1-8) y columna (A-H) separadas por espacio: ";
    cin >> fila >> columna;
    ficha = jugador2.getf();
    convcol = columna - 'A';
    fila--;

    if (tablero.movimiento(fila, convcol, ficha)) {
        tablero.imprimir();
    } else {
        cout << "Movimiento invalido." << endl;
    }

    return 0;
}
