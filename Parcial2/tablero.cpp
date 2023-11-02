#include <iostream>
#include "tablero.h"

using namespace std;

Tablero::Tablero()
{
    startb();
}

void Tablero::startb(){
    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            tablero[i][j] = ' ';
        }
    }
    tablero[3][3] = '*';
    tablero[3][4] = '-';
    tablero[4][3] = '-';
    tablero[4][4] = '*';


}

void Tablero::imprimir(){

    cout << "\n    A   B   C   D   E   F   G   H  " << endl;
    cout << "  +---+---+---+---+---+---+---+---+" << endl;
    for (int i = 0; i < bsize; i++) {
        cout << i+1 << " | ";
        for (int j = 0; j < bsize; j++) {
            cout << tablero[i][j] << " | ";
        }
        cout << endl << "  +---+---+---+---+---+---+---+---+" << endl;
    }
}

bool Tablero::movimientovalido(int fila, int columna) {

    if (fila < 0 || fila >= bsize || columna < 0 || columna >= bsize) {
        cout << "Jugada invalida, posicion fuera del límite\n" << endl;
        return false;
    }

    if (tablero[fila][columna] != ' ') {
        cout << "Jugada invalida, casilla ocupada\n" << endl;
        return false;
    }

    return true;
}

bool Tablero::movimiento(int fila, int columna, char ficha) {

    if (movimientovalido(fila, columna)) {
            tablero[fila][columna] = ficha;
            return true;
        }

        return false;
    }
  /*  if (movimientovalido(fila, columna)) {
    if (fila >= 0 && fila < bsize && columna >= 0 && columna < bsize) {
        if (tablero[fila][columna] == ' ') {
            tablero[fila][columna] = ficha;
            return true;
        }
    }
    }
    return false;
}
*/

