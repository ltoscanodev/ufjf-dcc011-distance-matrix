#ifndef TDISTMAT2_H
#define TDISTMAT2_H

#include "TList.h"

#include <iostream>

using namespace std;

/*
    Descrição: TAD que representa a matriz de distâncias através de um vetor de listas
*/
class TDistMat2
{
    private:
        int n; // Ordem da matriz
        int nVet; // Quantidade de linhas do vetor
        TList **mat; // Vetor que armazena a matriz
        bool isValidIndex(int i, int j); // Verifica se o índice é válido
    public:
        TDistMat2(int ordem); // Construtor do TAD
        float getDist(int i, int j); // Consulta a distância na posição i e j
        bool setDist(int i, int j, float dist); // Atribui uma distância à posição i e j
        void print(); // Imprime a matriz
        ~TDistMat2(); // Destrutor do TAD
};

#endif // TDISTMAT2_H
