#include "partida.h"
#include <iostream>
#include <ctime>
#include <string>
#include "juego.h"

using namespace std;
Partida::Partida()
{
    juego = new Juego();

}

Partida::~Partida() {

    delete juego;

}

void Partida::initpartida(){

    cout << "\nPartida iniciada!" << endl;
    cout << reghorayfecha()<< endl;
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
    resultado += "\nJugadores: " + juego->jugadores[0]->getn() + " - " + juego->jugadores[1]->getn() + "\n" +
            "Fecha y hora" + reghorayfecha() + "\n" +
            "Ganador: " + juego->jugadorganador;
    return resultado;
}
