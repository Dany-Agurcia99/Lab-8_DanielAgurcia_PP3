#ifndef PARTIDA_H
#define PARTIDA_H

#include <vector>
using std::vector;

#include <string>
using std::string;

class Partida
{
private:
    string nombre, piezaUsada, movimientos;
public:
    void guardarPartida(string,string,string);
};
#endif