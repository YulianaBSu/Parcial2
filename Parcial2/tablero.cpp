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

bool Tablero::movimientovalido(int fila, int columna, char ficha) {

    if (fila < 0 || fila >= bsize || columna < 0 || columna >= bsize) {
        cout << "Jugada invalida, posicion fuera del limite\n" << endl;
        return false;
    }

    if (tablero[fila][columna] != ' ') {
        cout << "Jugada invalida, casilla ocupada\n" << endl;
        return false;
    }


    //Verificacion horizontal

    int colizq = columna - 1;
    int colder = columna + 1;

    while (colizq >= 0 && tablero[fila][colizq] != ' ' && tablero[fila][colizq] != ficha) {
        colizq--;
    }
    if (colizq >= 0 && tablero[fila][colizq] == ficha && columna - colizq > 1) {
        return true;
    }

    while (colder < bsize && tablero[fila][colder] != ' ' && tablero[fila][colder] != ficha) {
        colder++;
    }
    if (colder < bsize && tablero[fila][colder] == ficha && colder - columna > 1) {
        return true;
    }



    //Verificacion vertical

    int filaarr = fila - 1;
    int filaab = fila + 1;

    while (filaarr >= 0 && tablero[filaarr][columna] != ' ' && tablero[filaarr][columna] != ficha) {
        filaarr--;
    }
    if (filaarr >= 0 && tablero[filaarr][columna] == ficha && fila - filaarr > 1) {
        return true;
    }

    while (filaab < bsize && tablero[filaab][columna] != ' ' && tablero[filaab][columna] != ficha) {
        filaab++;
    }
    if (filaab < bsize && tablero[filaab][columna] == ficha && filaab - fila > 1) {
        return true;
    }


    // Verificar diagonal 1

    while (filaarr >= 0 && colizq >= 0 && tablero[filaarr][colizq] != ' ' && tablero[filaarr][colizq] != ficha) {
        filaarr--;
        colizq--;
    }
    if (filaarr >= 0 && colizq >= 0 && tablero[filaarr][colizq] == ficha && fila - filaarr > 1 && columna - colizq > 1) {
        return true;
    }

    while (filaab < bsize && colder < bsize && tablero[filaab][colder] != ' ' && tablero[filaab][colder] != ficha) {
        filaab++;
        colder++;
    }
    if (filaab < bsize && colder < bsize && tablero[filaab][colder] == ficha && filaab - fila > 1 && colder - columna > 1) {
        return true;
    }


    // Verificar diagonal 2

    while (filaarr >= 0 && colder < bsize && tablero[filaarr][colder] != ' ' && tablero[filaarr][colder] != ficha) {
        filaarr--;
        colder++;
    }
    if (filaarr >= 0 && colder < bsize && tablero[filaarr][colder] == ficha && fila - filaarr > 1 && colder - columna > 1) {
        return true;
    }

    while (filaab < bsize && colizq >= 0 && tablero[filaab][colizq] != ' ' && tablero[filaab][colizq] != ficha) {
        filaab++;
        colizq--;
    }
    if (filaab < bsize && colizq >= 0 && tablero[filaab][colizq] == ficha && filaab - fila > 1 && columna - colizq > 1) {
        return true;
    }

    return false;
}



bool Tablero::movimiento(int fila, int columna, char ficha) {

    if (movimientovalido(fila, columna, ficha)) {
            tablero[fila][columna] = ficha;
            return true;
        }

        return false;
    }



void Tablero::giro(int fila, int columna, char ficha) {

    if (movimientovalido(fila, columna, ficha)){
    //Verificacion horizontal

    int colizq = columna - 1;
    int colder = columna + 1;

    while (colizq >= 0 && tablero[fila][colizq] != ' ' && tablero[fila][colizq] != ficha) {
        tablero[fila][colizq] = ficha;
        colizq--;
    }

    while (colder < bsize && tablero[fila][colder] != ' ' && tablero[fila][colder] != ficha) {
        tablero[fila][colder] = ficha;
        colder++;
    }



    //Verificacion vertical

    int filaarr = fila - 1;
    int filaab = fila + 1;

    while (filaarr >= 0 && tablero[filaarr][columna] != ' ' && tablero[filaarr][columna] != ficha) {
        tablero[filaarr][columna] = ficha;
        filaarr--;
    }

    while (filaab < bsize && tablero[filaab][columna] != ' ' && tablero[filaab][columna] != ficha) {
        tablero[filaab][columna] = ficha;
        filaab++;
    }


    // Verificar diagonal 1

    while (filaarr >= 0 && colizq >= 0 && tablero[filaarr][colizq] != ' ' && tablero[filaarr][colizq] != ficha) {
        tablero[filaarr][colizq] = ficha;
        filaarr--;
        colizq--;
    }

    while (filaab < bsize && colder < bsize && tablero[filaab][colder] != ' ' && tablero[filaab][colder] != ficha) {
        tablero[filaab][colder] = ficha;
        filaab++;
        colder++;
    }


    // Verificar diagonal 2

    while (filaarr >= 0 && colder < bsize && tablero[filaarr][colder] != ' ' && tablero[filaarr][colder] != ficha) {
        tablero[filaarr][colder] = ficha;
        filaarr--;
        colder++;
    }

    while (filaab < bsize && colizq >= 0 && tablero[filaab][colizq] != ' ' && tablero[filaab][colizq] != ficha) {
        tablero[filaab][colizq] = ficha;

        filaab++;
        colizq--;
    }
    }
    }
