#include "Caballo.h"

Caballo::Caballo()
{
}
Caballo::Caballo(char letra) : Pieza(letra)
{
}

bool Caballo::Movimiento(int f1, int c1, int f2, int c2)
{
    bool vali = false;
    if ((f1 - f2) * (f1 - f2) + (c1 - c2) * (c1 - c2) == 5)
    {
        vali = true;
    }

    return vali;
}