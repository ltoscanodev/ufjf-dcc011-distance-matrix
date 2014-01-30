#include "TDistMat.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

/*
    Descrição: Método que lê o arquivo que contêm a matriz
    Autor: Luis Augusto Toscano
*/
TDistMat* readMatriz(string fileName)
{
    ifstream streamFile;
    streamFile.open(fileName.c_str());

    if (!streamFile.is_open())
        cout << "Erro ao carregar o arquivo da matriz!" << endl;
    else
    {
        int i = 1;
        int j = 0;

        string line;
        getline(streamFile, line);
        istringstream streamLine(line);

        float ordem;
        streamLine >> ordem;

        TDistMat *distMat = new TDistMat(ordem);

        while (getline(streamFile, line))
        {
            float dist;
            istringstream streamLine(line);

            while(streamLine >> dist)
            {
                distMat->setDist(i, j, dist);
                j++;
            }

            j = 0;
            i++;
        }

        streamFile.close();
        return distMat;
    }

    return NULL;
}

void consult(TDistMat *p){
    int i = 0;
    int j = 0;

    cout << " -- CONSULTA DA MATRIZ DISTÂNCIA -- " << endl;

    while(i != -1 && j != -1){
        cout << endl << "Insira i: ";
        cin >> i;
        cout << "Insira j: ";
        cin >> j;
        if(i != -1 && j != -1)
            cout << endl << "[" << i << "][" << j << "]: " << p->getDist(i, j) << endl;
    }

    cout << endl << " -- FIM DA CONSULTA -- ";
}

int main()
{
    TDistMat *distMat = readMatriz("Matrizes/matriz.txt");

    if(distMat != NULL)
        distMat->print();

    consult(distMat);

    return 0;
}
