#include "Torre.h"

Torre::Torre()
{
}
Torre::Torre(char letra) : Pieza(letra)
{
}

bool Torre::Movimiento(int f1, int c1, int f2, int c2)
{
    bool vali = false;
    if ((f1 == f2) || (c1 == c2))
    {
        vali = true;
    }
    return vali;
}