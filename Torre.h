#ifndef TORRE_H
#define TORRE_H
#include "Pieza.h"
class Torre : public Pieza
{
public:
    Torre();
    Torre(char letra);
    virtual bool Movimiento(int, int, int, int);
};
#endif