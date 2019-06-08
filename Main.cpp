#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <sstream>
using std::stringstream;
#include <vector>
using std::vector;

#include "Pieza.h"
#include "Peon.h"
#include "Alfil.h"
#include "Caballo.h"
#include "Torre.h"
#include "Reina.h"
#include "Rey.h"
#include "Partida.h"

void JugarPartida(string, string, Pieza *, Pieza *, char **, int);
void RecrearPartida();
char **CrearMatriz();
void EliminarMatriz(char **);
void ImprimirMatriz(char **);
int coordenadachar(char);
Pieza *coordPieza(char);
char **matrix = NULL;
int main()
{
    int opcion = 0;
    while (opcion != 3)
    {
        cout << "Menu" << endl
             << "1-Jugar Partida" << endl
             << "2-Recrear Partida" << endl
             << "3-Salir" << endl;
        cout << "Ingrese una opcion: " << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {
            string nombreP, PiezaUsada;

            int opcion2;
            cout << "Ingrese el nombre de la partida: ";
            cin >> nombreP;
            cout << "Elija el numero de la pieza con la que desea jugar" << endl
                 << "1-Peon" << endl
                 << "2-Alfil" << endl
                 << "3-Caballo" << endl
                 << "4-Torre" << endl
                 << "5-Reina" << endl;
            cout << "Ingrese una opcion: " << endl;
            cin >> opcion2;
            Pieza *pieza;
            switch (opcion2)
            {
            case 1:
                pieza = new Peon('P');
                PiezaUsada = "Peon";
                break;
            case 2:
                pieza = new Alfil('A');
                PiezaUsada = "Alfil";
                break;
            case 3:
                pieza = new Caballo('C');
                PiezaUsada = "Caballo";
                break;
            case 4:
                pieza = new Torre('T');
                PiezaUsada = "Torre";
                break;
            case 5:
                pieza = new Reina('Q');
                PiezaUsada = "Reina";
                break;
            }
            Pieza *rey = new Rey('K');
            matrix = CrearMatriz();
            JugarPartida(nombreP, PiezaUsada, pieza, rey, matrix, opcion2);
        }
        break;
        case 2:
            RecrearPartida();
            break;
        case 3:
            EliminarMatriz(matrix);
        }
    }
    return 0;
}

void JugarPartida(string nombre, string PiezaUsada, Pieza *pieza, Pieza *rey, char **matrix, int opcion)
{
    stringstream StreamMoves;
    string Moves;
    char resp = 's';
    matrix[0][4] = 'K';
    matrix[7][4] = 'K';
    switch (opcion)
    {
    case 1:
        matrix[1][4] = 'P';
        matrix[6][4] = 'P';
        break;
    case 2:
        matrix[0][5] = 'A';
        matrix[7][2] = 'A';
        break;
    case 3:
        matrix[0][6] = 'C';
        matrix[7][1] = 'C';
        break;
    case 4:
        matrix[0][7] = 'T';
        matrix[7][0] = 'T';
        break;
    case 5:
        matrix[0][3] = 'Q';
        matrix[7][3] = 'Q';
        break;
    }
    while (resp == 's' || resp == 'S')
    {
        bool validarMovimiento;
        int columna1, columna2, fila2, fila1;
        string coordsBlanco, coordsNegro;
        ImprimirMatriz(matrix);
        cout << "Ingrese las coordenadas jugador blanco: ";
        cin >> coordsBlanco;
        fila1 = 8 - ((int)coordsBlanco[2]);
        columna1 = coordenadachar(coordsBlanco[1]);
        fila2 = 8 - ((int)coordsBlanco[5]);
        columna2 = coordenadachar(coordsBlanco[4]);
        Pieza *piezaM = coordPieza(matrix[fila1][columna1]);
        validarMovimiento = piezaM->Movimiento(fila1, columna1, fila2, columna2);
        while (validarMovimiento == false)
        {
            cout << "Movimiento invalido";
            cout << "Ingrese las coordenadas jugador blanco: ";
            cin >> coordsBlanco;
            fila1 = 8 - ((int)coordsBlanco[2]);
            columna1 = coordenadachar(coordsBlanco[1]);
            fila2 = 8 - ((int)coordsBlanco[5]);
            columna2 = coordenadachar(coordsBlanco[4]);
            piezaM = coordPieza(matrix[fila1][columna1]);
            validarMovimiento = piezaM->Movimiento(fila1, columna1, fila2, columna2);
        }
        StreamMoves << coordsBlanco<<";";
        cout << "Ingrese las coordenadas jugador negro: ";
        cin >> coordsNegro;
        fila1 = 8 - ((int)coordsNegro[2]);
        columna1 = coordenadachar(coordsNegro[1]);
        fila2 = 8 - ((int)coordsNegro[5]);
        columna2 = coordenadachar(coordsNegro[4]);
        piezaM = coordPieza(matrix[fila1][columna1]);
        validarMovimiento = piezaM->Movimiento(fila1, columna1, fila2, columna2);
        while (validarMovimiento == false)
        {
            cout << "Movimiento invalido";
            cout << "Ingrese las coordenadas jugador blanco: ";
            cin >> coordsNegro;
            fila1 = 8 - ((int)coordsNegro[2]);
            columna1 = coordenadachar(coordsNegro[1]);
            fila2 = 8 - ((int)coordsNegro[5]);
            columna2 = coordenadachar(coordsNegro[4]);
            piezaM = coordPieza(matrix[fila1][columna1]);
            validarMovimiento = piezaM->Movimiento(fila1, columna1, fila2, columna2);
        }
        StreamMoves << coordsNegro<<";";
        cout << "Desea continuar? [s/n]: ";
        cin >> resp;
    }
    Moves = StreamMoves.str();
    Partida *partida = new Partida(nombre, PiezaUsada, Moves);
    partida->guardarPartida(nombre, PiezaUsada, Moves);
}
void RecrearPartida()
{
    //nada
}
char **CrearMatriz()
{
    char **matrix = new char *[8];
    for (int k = 0; k < 8; k++)
    {
        matrix[k] = new char[8];
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            matrix[i][j] = ' ';
        }
    }
    return matrix;
}
void EliminarMatriz(char **matrix)
{
    for (int i = 0; i < 8; i++)
    {
        if (matrix[i] != NULL)
        {
            delete[] matrix[i];
            matrix[i] = NULL;
        }
    }
    delete matrix;
}
void ImprimirMatriz(char **matrix)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << "[" << matrix[i][j] << "]";
        }
        cout << endl;
    }
}
int coordenadachar(char letra)
{
    int fila;
    switch (letra)
    {
    case 'a':
        fila = 0;
        break;
    case 'b':
        fila = 1;
        break;
    case 'c':
        fila = 2;
        break;
    case 'd':
        fila = 3;
        break;
    case 'e':
        fila = 4;
        break;
    case 'f':
        fila = 5;
        break;
    case 'g':
        fila = 6;
        break;
    case 'h':
        fila = 7;
        break;
    }
    return fila;
}
Pieza *coordPieza(char letra)
{
    Pieza *pieza;
    switch (letra)
    {
    case 'P':
        pieza = new Peon('P');
        break;
    case 'A':
        pieza = new Alfil('A');
        break;
    case 'C':
        pieza = new Caballo('C');
        break;
    case 'T':
        pieza = new Torre('T');
        break;
    case 'R':
        pieza = new Reina('Q');
        break;
    default:
        break;
    }
    return pieza;
}