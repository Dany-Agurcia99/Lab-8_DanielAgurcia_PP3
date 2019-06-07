#include "Pieza.h"

Pieza::Pieza()
{
}

Pieza::Pieza(char letra)
{
    this->letra = letra;
}

char Pieza::getLetra()
{
    return letra;
}

void Pieza::setLetra(char letra)
{
    this->letra = letra;
}