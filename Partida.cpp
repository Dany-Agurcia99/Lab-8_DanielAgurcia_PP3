#include "Partida.h"

Partida::Partida(string nombre, string tipo, string moves)
{
    this->nombre = nombre;
    this->tipo = tipo;
    this->moves = moves;
}
void Partida::guardarPartida(string nombre, string tipo, string moves)
{
    ofstream outFile;
    outFile.open("bitacorasPartidas.txt", std::ios::app);
    outFile << nombre << "\n";
    outFile << tipo << "\n";
    outFile << moves << "\n";
    outFile << "*************\n";
}