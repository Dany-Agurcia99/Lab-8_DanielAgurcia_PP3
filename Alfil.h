#ifndef ALFIL_H
#define ALFIL_H
#include "Pieza.h"
class Alfil : public Pieza
{
public:
    Alfil();
    Alfil(char letra);
    virtual bool Movimiento(int, int, int, int);
};
#endif