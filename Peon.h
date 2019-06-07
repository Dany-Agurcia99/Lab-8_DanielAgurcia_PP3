#ifndef PEON_H
#define PEON_H
#include "Pieza.h"
class Peon : public Pieza
{
public:
    Peon();
    Peon(char letra);
    virtual bool Movimiento(int,int,int,int);
};
#endif