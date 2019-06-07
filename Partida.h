#ifndef PARTIDA_H
#define PARTIDA_H

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <fstream>
using std::ofstream;
class Partida
{
private:
    string nombre, tipo, moves;
public:
    Partida();
    Partida(string, string, string);
    void guardarPartida(string, string, string);
};
#endif