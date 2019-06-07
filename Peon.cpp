#include "Peon.h"

Peon::Peon()
{
}
Peon::Peon(char letra) : Pieza(letra)
{
}

bool Peon::Movimiento(int f1, int c1, int f2, int c2)
{
    bool vali = false;
    if (f1 == f1 + f2)
    {
        vali = true;
    }

    return vali;
}