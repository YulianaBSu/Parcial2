#include "partida.h"
#include <iostream>
#include <ctime>
#include <string>

using namespace std;
Partida::Partida(Jugador* jugador1, Jugador* jugador2)
{
    this->jugador1 = jugador1;
    this->jugador2 = jugador2;
}

Partida::~Partida() {}

void Partida::initpartida(){

    cout << "\nPartida iniciada!" << endl;
    cout << reghorayfecha()<< endl;
}

void Partida::jganador(string ganador, int fichasganador){
    this->ganador = ganador;
    this->fichasganador = fichasganador;
}

string Partida::reghorayfecha(){
    time_t tiempo = time(nullptr);
    struct tm* now = localtime(&tiempo);

    string fechayhora = to_string(now->tm_year + 1900) + '/' + (now->tm_mon +1 < 10 ? "0" : "") + to_string(now->tm_mon + 1) + '/' +
            (now->tm_mday < 10 ? "0" : "") + to_string(now->tm_mday) + ' ' +
            (now->tm_hour < 10 ? "0" : "") + to_string(now->tm_hour) + ':' +
            (now->tm_min < 10 ? "0" : "") + to_string(now->tm_min) + ':' +
            (now->tm_sec < 10 ? "0" : "") + to_string(now->tm_sec);

    return fechayhora;
}

string Partida::resultados(){
    string resultado;
    resultado += "\nJugadores: " + jugador1->getn() + " - " + jugador2->getn() + "\n" +
            "Fecha y hora" + reghorayfecha() + "\n" +
            "Ganador: ";
    return resultado;
}
