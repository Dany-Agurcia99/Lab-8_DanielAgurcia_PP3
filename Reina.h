#ifndef REINA_H
#define REINA_H
#include "Pieza.h"
class Reina : public Pieza
{
private:
public:
    Reina();
    Reina(char letra);
    virtual bool Movimiento(int, int, int, int);
};
#endif