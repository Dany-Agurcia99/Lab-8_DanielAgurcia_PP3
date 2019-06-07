#ifndef CABALLO_H
#define CABALLO_H
#include "Pieza.h"
class Caballo : public Pieza
{
public:
    Caballo();
    Caballo(char letra);
    virtual bool Movimiento(int, int, int, int);
};
#endif