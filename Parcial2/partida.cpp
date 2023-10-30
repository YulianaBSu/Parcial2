#include "partida.h"
#include <iostream>
#include <ctime>
#include <string>

using namespace std;
Partida::Partida(string jugador1, string jugador2) : jugador1(jugador1), jugador2(jugador2)
{

}

void Partida::initpartida(){

    cout << "Partida iniciada!" << endl;
    reghorayfecha();
}

void Partida::reghorayfecha(){
    time_t tiempo = time(nullptr);
    struct tm* now = localtime(&tiempo);

    fecha = to_string(now->tm_year + 1900) + '/' + to_string(now->tm_mon + 1) + '/' + to_string(now->tm_mday);
    hora = to_string(now->tm_hour) + ':' + to_string(now->tm_min) + ':' + to_string(now->tm_sec);
    cout << "Fecha: " << fecha << ", Hora: " << hora << "\n" << endl;

}
