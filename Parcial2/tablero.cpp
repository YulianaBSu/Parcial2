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
    if (colizq >= 0 && tablero[fila][colizq] == ficha ) {
        return true;
    }

    while (colder < bsize && tablero[fila][colder] != ' ' && tablero[fila][colder] != ficha) {
        colder++;
    }
    if (colder < bsize && tablero[fila][colder] == ficha ) {
        return true;
    }



    //Verificacion vertical

    int filaarr = fila - 1;
    int filaab = fila + 1;

    while (filaarr >= 0 && tablero[filaarr][columna] != ' ' && tablero[filaarr][columna] != ficha) {
        filaarr--;
    }
    if (filaarr >= 0 && tablero[filaarr][columna] == ficha ) {
        return true;
    }

    while (filaab < bsize && tablero[filaab][columna] != ' ' && tablero[filaab][columna] != ficha) {
        filaab++;
    }
    if (filaab < bsize && tablero[filaab][columna] == ficha ) {
        return true;
    }



    int Dfilaarr = fila - 1;
    int Dfilaab = fila + 1;
    int Dcolizq = columna - 1;
    int Dcolder = columna + 1;


    // Verificar diagonal 1
    while (Dfilaarr >= 0 && Dcolizq >= 0 && tablero[Dfilaarr][Dcolizq] != ' ' && tablero[Dfilaarr][Dcolizq] != ficha) {
        Dfilaarr--;
        Dcolizq--;
    }
    if (Dfilaarr >= 0 && Dcolizq >= 0 && tablero[Dfilaarr][Dcolizq] == ficha ) {
        return true;
    }
    while (Dfilaab < bsize && Dcolder < bsize && tablero[Dfilaab][Dcolder] != ' ' && tablero[Dfilaab][Dcolder] != ficha) {
        Dfilaab++;
        Dcolder++;
    }
    if (Dfilaab < bsize && Dcolder < bsize && tablero[Dfilaab][Dcolder] == ficha ) {
        return true;
    }

    // Verificar diagonal 2
    while (Dfilaarr >= 0 && Dcolder < bsize && tablero[Dfilaarr][Dcolder] != ' ' && tablero[Dfilaarr][Dcolder] != ficha) {
        Dfilaarr--;
        Dcolder++;
    }
    if (Dfilaarr >= 0 && Dcolder < bsize && tablero[Dfilaarr][Dcolder] == ficha ) {
        return true;
    }
    while (Dfilaab < bsize && Dcolizq >= 0 && tablero[Dfilaab][Dcolizq] != ' ' && tablero[Dfilaab][Dcolizq] != ficha) {
        Dfilaab++;
        Dcolizq--;
    }
    if (Dfilaab < bsize && Dcolizq >= 0 && tablero[Dfilaab][Dcolizq] == ficha ) {
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


    int colizq = columna - 1;
    int colder = columna + 1;

    while (colizq >= 0 && tablero[fila][colizq] != ' ' && tablero[fila][colizq] != ficha) {
        colizq--;
    }

    if (colizq >= 0 && tablero[fila][colizq] == ficha) {
        int col = columna - 1;
        while (col != colizq) {
            if (tablero[fila][col] != ficha) {
                tablero[fila][col] = ficha;
            }
            col--;
        }
    }


    while (colder < bsize && tablero[fila][colder] != ' ' && tablero[fila][colder] != ficha) {
        colder++;
    }
    if (colder < bsize && tablero[fila][colder] == ficha) {
        int col = columna + 1;
        while (col != colder) {
            if (tablero[fila][col] != ficha) {
                tablero[fila][col] = ficha;
            }
            col++;
        }
    }


    int filaarr = fila - 1;
    int filaab = fila + 1;

    while (filaarr >= 0 && tablero[filaarr][columna] != ' ' && tablero[filaarr][columna] != ficha) {
        filaarr--;
    }
    if (filaarr >= 0 && tablero[filaarr][columna] == ficha) {
        int fil = fila - 1;
        while (fil != filaarr) {
            if (tablero[fil][columna] != ficha) {
                tablero[fil][columna] = ficha;
            }
            fil--;
        }
    }


    while (filaab < bsize && tablero[filaab][columna] != ' ' && tablero[filaab][columna] != ficha) {
        //tablero[filaab][columna] = ficha;
        filaab++;
    }
    if (filaab < bsize && tablero[filaab][columna] == ficha) {
        int fil = fila + 1;
        while (fil != filaab) {
            if (tablero[fil][columna] != ficha) {
                tablero[fil][columna] = ficha;
            }
            fil++;
        }
    }


    //Diagonales
    int Dfilaarr = fila - 1;
    int Dfilaab = fila + 1;
    int Dcolizq = columna - 1;
    int Dcolder = columna + 1;

    while (Dfilaarr >= 0 && Dcolizq >= 0 && tablero[Dfilaarr][Dcolizq] != ' ' && tablero[Dfilaarr][Dcolizq] != ficha) {
        Dfilaarr--;
        Dcolizq--;
    }
    if (Dfilaarr >= 0 && Dcolizq >= 0 && tablero[Dfilaarr][Dcolizq] == ficha) {
        int Dfila = fila - 1;
        int Dcol = columna - 1;
        while (Dfila != Dfilaarr && Dcol != Dcolizq) {
            if (tablero[Dfila][Dcol] != ficha) {
                tablero[Dfila][Dcol] = ficha;
            }
            Dfila--;
            Dcol--;
        }
    }

    while (Dfilaab < bsize && Dcolder < bsize && tablero[Dfilaab][Dcolder] != ' ' && tablero[Dfilaab][Dcolder] != ficha) {
        Dfilaab++;
        Dcolder++;
    }
    if (Dfilaab < bsize && Dcolder < bsize && tablero[Dfilaab][Dcolder] == ficha) {
        int Dfila = fila + 1;
        int Dcol = columna + 1;
        while (Dfila != Dfilaab && Dcol != Dcolder) {
            if (tablero[Dfila][Dcol] != ficha) {
                tablero[Dfila][Dcol] = ficha;
            }
            Dfila++;
            Dcol++;
        }
    }


    while (Dfilaarr >= 0 && Dcolder < bsize && tablero[Dfilaarr][Dcolder] != ' ' && tablero[Dfilaarr][Dcolder] != ficha) {
        Dfilaarr--;
        Dcolder++;
    }
    if (Dfilaarr >= 0 && Dcolder < bsize && tablero[Dfilaarr][Dcolder] == ficha) {
        int Dfila = fila - 1;
        int Dcol = columna + 1;
        while (Dfila != Dfilaarr && Dcol != Dcolder) {
            if (tablero[Dfila][Dcol] != ficha) {
                tablero[Dfila][Dcol] = ficha;
            }
            Dfila--;
            Dcol++;
        }
    }

    while (Dfilaab < bsize && Dcolizq >= 0 && tablero[Dfilaab][Dcolizq] != ' ' && tablero[Dfilaab][Dcolizq] != ficha) {
        Dfilaab++;
        Dcolizq--;
    }

    if (Dfilaab < bsize && Dcolizq >= 0 && tablero[Dfilaab][Dcolizq] == ficha) {
        int Dfila = fila + 1;
        int Dcol = columna - 1;
        while (Dfila != Dfilaab && Dcol != Dcolizq) {
            if (tablero[Dfila][Dcol] != ficha) {
                tablero[Dfila][Dcol] = ficha;
            }
            Dfila++;
            Dcol--;
        }
    }
 }
