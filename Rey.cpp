#include "Rey.h"

Rey::Rey()
{
}

Rey::Rey(char letra) : Pieza(letra)
{
}

bool Rey::Movimiento(int f1, int c1, int f2, int c2)
{
    bool vali = false;
    int absolute1, absolute2;
    absolute1 = f1 - f2;
    absolute2 = c1 - c2;
    if (absolute1 < 0)
    {
        absolute1 = absolute1 * -1;
    }
    if (absolute2 < 0)
    {
        absolute2 = absolute2 * -1;
    }

    if ((absolute1 <= 1) && (absolute2 <= 1))
    {
        vali = true;
    }

    return vali;
}