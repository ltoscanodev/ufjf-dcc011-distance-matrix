#include "TDistMat.h"

/*
    Descrição: Implementação do construtor do TAD, recebe como parâmetro a ordem da matriz e aloca
               memória para o vetor
*/
TDistMat::TDistMat(int ordem)
{
    n = ordem;
    nVet = ((n * (n - 1)) / 2);
    mat = new float[nVet];
}

/*
    Descrição: Implementação do destrutor do TAD, desaloca o vetor que guarda a matriz
*/
TDistMat::~TDistMat()
{
    delete [] mat;
}

/*
    Descrição: Implementação do método isValidIndex do TAD, verifica se o índice i e j está dentro da matriz
*/
bool TDistMat::isValidIndex(int i, int j)
{
    if((i >= 0) && (i < n) && (j >= 0) && (j < n))
        return true;

    return false;
}

/*
    Descrição: Implementação do método convertIndex do TAD, se i e j são válidos, converte-os para um índice k do vetor
*/
int TDistMat::convertIndex(int i, int j)
{
    if(isValidIndex(i, j))
        return (i * (i - 1)/2 + j);

    return -1;
}

/*
    Descrição: Implementação do método getDist do TAD, retorna a distância no índice i e j
*/
float TDistMat::getDist(int i, int j)
{
    int index = convertIndex(i, j);

    if(index != -1)
    {
        if(i == j)
            return 0;
        else
        {
            if(j > i)
                index = convertIndex(j, i);

            return mat[index];
        }
    }
    else
        cout << endl << "[ Erro: Indice invalido ]" << endl;

    return -1;
}

/*
    Descrição: Implementação do método setDist do TAD, atribui uma distância elemento i e j da matriz
*/
bool TDistMat::setDist(int i, int j, float dist)
{
    int index = convertIndex(i, j);

    if(index != -1)
    {
        if(i != j)
        {
            if(dist >= 0)
            {
                if(j > i)
                    index = convertIndex(j, i);

                mat[index] = dist;

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
    Descrição: Implementação do método print do TAD, imprime a matriz
*/
void TDistMat::print()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << "[" << i << "][" << j << "]: " << getDist(i, j) << endl;
        }
    }
}

/*
    Descrição: Implementação do método save do TAD, salva a matriz em um arquivo
*/
bool TDistMat::save(string fileName)
{
    ofstream matFile;
    string filePath = "Matrizes/" + fileName + ".txt";
    matFile.open(filePath.c_str());

    if(!matFile.is_open())
        cout << endl << "[ Erro: Nao foi possivel criar o arquivo da matriz ]" << endl;
    else
    {
        matFile << n << endl;

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                matFile << getDist(i, j);

                if(j < (i - 1))
                    matFile << " ";
            }

            matFile << endl;
        }

        matFile.close();

        return true;
    }

    return false;
}
