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

    if (fila <1 && fila > bsize && columna <1 && columna > bsize){
        cout << "Jugada invalida, posicion fuera del limite" << endl;
        return false;
    }
    if (tablero[fila-1][columna-1] !=' '){
        cout << "Jugada invalida, casilla ocupada" << endl;
        return false;
    }

    return true;

}
bool Tablero::movimiento(int fila, int columna, char ficha) {
    fila--;
    if (fila >= 0 && fila < bsize && columna >= 0 && columna < bsize) {
        if (tablero[fila][columna] == ' ') {
            tablero[fila][columna] = ficha;
            return true;
        }
    }
    return false;
}


