#include "TDistMat.h"

/*
    Descrição: Implementação do TAD TDistMat
*/

/*
    Descrição: Implementação do construtor do TAD, recebe como parâmetro a ordem da matriz e aloca
               memória para um vetor [n x n]
    Autor: Luis Augusto Toscano
*/
TDistMat::TDistMat(int ordem)
{
    n = ordem;
    mat = new float[n * n];
}

/*
    Descrição: Implementação do destrutor do TAD, desaloca o vetor que guarda a matriz
    Autor: Luis Augusto Toscano
*/
TDistMat::~TDistMat()
{
    delete [] mat;
}

/*
    Descrição: Implementação do método isValidIndex do TAD
    Autor:
*/
bool TDistMat::isValidIndex(int i, int j)
{
    if((i >= 0) && (i < n) && (j >= 0) && (j < n))
        return true;

    return false;
}

/*
    Descrição: Implementação do método convertIndex do TAD
    Autor:
*/
int TDistMat::convertIndex(int i, int j)
{
    //TODO
}

/*
    Descrição: Implementação do método getDist do TAD
    Autor:
*/
float TDistMat::getDist(int i, int j)
{
    //TODO
}

/*
    Descrição: Implementação do método setDist do TAD
    Autor:
*/
void TDistMat::setDist(int i, int j, float dist)
{
    //TODO
}

/*
    Descrição: Implementação do método print do TAD
    Autor:
*/
void TDistMat::print()
{
    //TODO
}
