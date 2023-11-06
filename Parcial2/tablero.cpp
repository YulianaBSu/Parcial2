#include <iostream>
#include "tablero.h"

using namespace std;

Tablero::Tablero(){}

void Tablero::startb(char ficha1, char ficha2){
    for (int i = 0; i < bsize; i++) {
        for (int j = 0; j < bsize; j++) {
            tablero[i][j] = ' ';
        }
    }
    tablero[bsize/2 - 1][bsize/2 -1] = ficha2;
    tablero[bsize/2 - 1][bsize/2] = ficha1;
    tablero[bsize/2][bsize/2 - 1] = ficha1;
    tablero[bsize/2][bsize/2] = ficha2;
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
        return false;
    }

    if (tablero[fila][columna] != ' ') {
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
    if (colder < bsize && tablero[fila][colder] == ficha && colder - columna > 1 ) {
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



    int Dfilaarr = fila - 1;
    int Dfilaab = fila + 1;
    int Dcolizq = columna - 1;
    int Dcolder = columna + 1;


    // Verificar diagonal 1
    while (Dfilaarr >= 0 && Dcolizq >= 0 && tablero[Dfilaarr][Dcolizq] != ' ' && tablero[Dfilaarr][Dcolizq] != ficha) {
        Dfilaarr--;
        Dcolizq--;
    }
    if (Dfilaarr >= 0 && Dcolizq >= 0 && tablero[Dfilaarr][Dcolizq] == ficha && fila - Dfilaarr > 1 && columna - Dcolizq > 1) {
        return true;
    }
    while (Dfilaab < bsize && Dcolder < bsize && tablero[Dfilaab][Dcolder] != ' ' && tablero[Dfilaab][Dcolder] != ficha) {
        Dfilaab++;
        Dcolder++;
    }
    if (Dfilaab < bsize && Dcolder < bsize && tablero[Dfilaab][Dcolder] == ficha && Dfilaab - fila > 1 && Dcolder - columna > 1) {
        return true;
    }


    int Dsfilaarr = fila - 1;
    int Dsfilaab = fila + 1;
    int Dscolizq = columna - 1;
    int Dscolder = columna + 1;


    // Verificar diagonal 2
    while (Dsfilaarr >= 0 && Dscolder < bsize && tablero[Dsfilaarr][Dscolder] != ' ' && tablero[Dsfilaarr][Dscolder] != ficha) {
        Dsfilaarr--;
        Dscolder++;
    }
    if (Dsfilaarr >= 0 && Dscolder < bsize && tablero[Dsfilaarr][Dscolder] == ficha && fila - Dsfilaarr > 1 && Dscolder - columna > 1) {
        return true;
    }
    while (Dsfilaab < bsize && Dscolizq >= 0 && tablero[Dsfilaab][Dscolizq] != ' ' && tablero[Dsfilaab][Dscolizq] != ficha) {
        Dsfilaab++;
        Dscolizq--;
    }
    if (Dsfilaab < bsize && Dscolizq >= 0 && tablero[Dsfilaab][Dscolizq] == ficha && Dsfilaab - fila > 1 && columna - Dscolizq > 1) {
        return true;
    }

    return false;
    }


bool Tablero::ifmovalid(char ficha) {
    for (int fila = 0; fila < bsize; ++fila) {
        for (int columna = 0; columna < bsize; ++columna) {
            if (movimientovalido(fila, columna, ficha)) {
                return true;
            }
        }
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

    int Dsfilaarr = fila - 1;
    int Dsfilaab = fila + 1;
    int Dscolizq = columna - 1;
    int Dscolder = columna + 1;


    while (Dsfilaarr >= 0 && Dscolder < bsize && tablero[Dsfilaarr][Dscolder] != ' ' && tablero[Dsfilaarr][Dscolder] != ficha) {
        Dsfilaarr--;
        Dscolder++;
    }
    if (Dsfilaarr >= 0 && Dscolder < bsize && tablero[Dsfilaarr][Dscolder] == ficha) {
        int Dfila = fila - 1;
        int Dcol = columna + 1;
        while (Dfila != Dsfilaarr && Dcol != Dscolder) {
            if (tablero[Dfila][Dcol] != ficha) {
                tablero[Dfila][Dcol] = ficha;
            }
            Dfila--;
            Dcol++;
        }
    }

    while (Dsfilaab < bsize && Dscolizq >= 0 && tablero[Dsfilaab][Dscolizq] != ' ' && tablero[Dsfilaab][Dscolizq] != ficha) {
        Dsfilaab++;
        Dscolizq--;
    }

    if (Dsfilaab < bsize && Dscolizq >= 0 && tablero[Dsfilaab][Dscolizq] == ficha) {
        int Dfila = fila + 1;
        int Dcol = columna - 1;
        while (Dfila != Dsfilaab && Dcol != Dscolizq) {
            if (tablero[Dfila][Dcol] != ficha) {
                tablero[Dfila][Dcol] = ficha;
            }
            Dfila++;
            Dcol--;
        }
    }
  }




void Tablero::cfichas(char ficha1, char ficha2) {
    fichasj1 = 0;
    fichasj2 = 0;

    for (int fila = 0; fila < bsize; ++fila) {
        for (int columna = 0; columna < bsize; ++columna) {
            if (tablero[fila][columna] == ficha1) {
                fichasj1++;
            }
            else if (tablero[fila][columna] == ficha2) {
                fichasj2++;
            }
        }
    }

    cout << "\nFichas:"<<endl;
    cout << "'" << ficha1 <<"' -> " << fichasj1 <<  "         '"<< ficha2 << "' -> " << fichasj2 << endl;
}

string Tablero::ganadorp(string jug1, string jug2){

    if (fichasj1 > fichasj2) {
        return "Jugadores: " + jug1 + " y " + jug2 + ", Ganador: " + jug2 + ", Fichas: " + to_string(fichasj2);
        }
    else if (fichasj2 > fichasj1) {
        return "Jugadores: " + jug1 + " y " + jug2 + ", Ganador: " + jug2 + ", Fichas: " + to_string(fichasj2);
        }
    else {
        return "Jugadores: " + jug1 + " y " + jug2 + ", Resultado: Empate, ambos jugadores tienen " + to_string(fichasj1) + " fichas.";
        }
}

