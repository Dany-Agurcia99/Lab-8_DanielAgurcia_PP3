#ifndef PIEZA_H
#define PIEZA_H

class Pieza
{
private:
char letra;
public:
    Pieza();
    Pieza(char);

    char getLetra();
    void setLetra(char);

    virtual bool Movimiento(int,int,int,int) = 0;
};
#endif