#ifndef TDISTMAT_H_INCLUDED
#define TDISTMAT_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
    Descrição: TAD que representa a matriz de distâncias através de um vetor
*/
class TDistMat
{
    private:
        int n; // Ordem da matriz
        int nVet; // Quantidade de elementos do vetor
        float *mat; // Vetor que armazena a matriz
        bool isValidIndex(int i, int j); // Verifica se o índice é válido
        int convertIndex(int i, int j); // Se i e j forem válidos, converte o i e j para o índice correto no vetor
    public:
        TDistMat(int ordem); // Construtor que recebe como parâmetro a ordem da matriz
        float getDist(int i, int j); // Consulta a distância na posição i e j
        bool setDist(int i, int j, float dist); // Atribui uma distância à posição i e j
        void print(); // Imprime a matriz
        bool save(string fileName); // Salva a matriz em um arquivo
        ~TDistMat(); // Destrutor do TAD
};

#endif // TDISTMAT_H_INCLUDED
