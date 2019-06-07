#ifndef REY_H
#define REY_H
#include "Pieza.h"
class Rey : public Pieza
{
public:
    Rey();
    Rey(char letra);
    virtual bool Movimiento(int, int, int, int);
};
#endif