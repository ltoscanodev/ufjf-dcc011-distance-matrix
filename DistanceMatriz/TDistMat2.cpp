#include "TDistMat2.h"

/*
    Descrição: Implementação do método construtor do TAD, recebe como parâmetro a ordem da matriz e aloca
               memória para um vetor [n - 1] de listas
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
*/
bool TDistMat2::isValidIndex(int i, int j)
{
    if((i >= 0) && (i < n) && (j >= 0) && (j < n))
        return true;

    return false;
}

/*
    Descrição: Implementação do método getDist do TAD
*/
float TDistMat2::getDist(int i, int j)
{
    if(isValidIndex(i,j))
    {
        if(i == j)
            return 0;
        else
        {
            if(j > i)
                return mat[j-1]->getDist(i);

            return mat[i-1]->getDist(j);
        }
    }
    else
        cout << endl << "[ Erro: Indice invalido ]" << endl;

    return -1;
}

/*
    Descrição: Implementação do método setDist do TAD
*/
bool TDistMat2::setDist(int i, int j, float dist)
{
    if(isValidIndex(i,j))
    {
        if(i != j)
        {
            if(dist >= 0)
            {
                if(j > i)
                    mat[j-1]->setDist(i,dist);
                else
                    mat[i-1]->setDist(j,dist);

                return true;
            }
            else
                cout << endl << "[ Erro: Valor invalido para distancia ]" << endl;
        }
    }
    else
        cout << endl << "[ Erro: Indice invalido ]" << endl;

    return false;
}

/*
    Descrição: Implementação do método print do TAD
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

