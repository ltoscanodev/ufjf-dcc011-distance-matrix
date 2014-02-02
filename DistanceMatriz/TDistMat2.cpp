#include "TDistMat2.h"
#include "TList.h"
#include <iostream>

using namespace std;

/*
    Descrição: Implementação do método construtor do TAD, recebe como parâmetro a ordem da matriz e aloca
               memória para um vetor [n - 1] de listas
    Autor: Igor Pires dos Santos
*/
TDistMat2::TDistMat2(int ordem)
{
    n = ordem;
    nVet = n - 1;
    mat = new TList*[nVet];
    for(int i = 0; i < nVet; i++)
        mat[i] = new TList();
}


/*
    Descrição: Implementação do método destrutor do TAD, desaloca as listas e em seguida o vetor que guarda estas
    Autor: Igor Pires dos Santos
*/
TDistMat2::~TDistMat2()
{
    for(int k = 0; k < n; k++)
    {
        TList *p = mat[k];
        delete p;
    }

    delete [] mat;
}

/*
    Descrição: Implementação do método isValidIndex do TAD
    Autor: Igor Pires dos Santos
*/
bool TDistMat2::isValidIndex(int i, int j)
{
    if((i >= 0) && (i < n) && (j >= 0) && (j < n))
        return true;

    return false;
}

/*
    Descrição: Implementação do método getDist do TAD
    Autor: Igor Pires dos Santos
*/
float TDistMat2::getDist(int i, int j)
{
    if(isValidIndex(i,j))
    {
        if(i == j)
            return 0;
        else if(i != j)
        {
            if(j > i)
                return mat[j-1]->getDistJ(i);

            return mat[i-1]->getDistJ(j);
        }
        else
            cout << "Índice inválido" << endl;
    }

    return -1;
}

/*
    Descrição: Implementação do método setDist do TAD
    Autor: Igor Pires dos Santos
*/
void TDistMat2::setDist(int i, int j, float dist)
{
    if(isValidIndex(i,j))
    {
        if(i != j)
        {
            if(j > i)
                mat[j-1]->setDist(i,dist);
            else
                mat[i-1]->setDist(j,dist);
        }
        else
            cout << "Índice inválido" << endl;

    }
}

/*
    Descrição: Implementação do método print do TAD
    Autor: Luis Augusto Toscano
*/
void TDistMat2::print()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << "[" << i << "][" << j << "]: " << getDist(i, j) << endl;
        }
    }
}

