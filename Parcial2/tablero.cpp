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
    cout << "  A B C D E F G H" << endl;
    for (int i = 0; i < bsize; i++) {
        cout << i+1 << " ";
        for (int j = 0; j < bsize; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}
