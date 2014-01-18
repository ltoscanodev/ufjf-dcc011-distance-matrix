#ifndef TDISTMAT_H_INCLUDED
#define TDISTMAT_H_INCLUDED

/*
    Descrição: TAD que representa a matriz de distâncias através de um vetor
    Autor: Luis Augusto Toscano
*/
class TDistMat
{
    private:
        int n; // Ordem da matriz
        float *mat; // Vetor que armazena a matriz
        bool isValidIndex(int i, int j); // Verifica se o índice é válido
        int convertIndex(int i, int j); // Se i e j forem válidos, converte o i e j para o índice correto no vetor
    public:
        TDistMat(int ordem); // Construtor do TAD
        ~TDistMat(); // Destrutor do TAD
        float getDist(int i, int j); // Consulta a distância na posição i e j
        void setDist(int i, int j, float dist); // Atribui uma distância à posição i e j
        void print(); // Imprime a matriz
};

#endif // TDISTMAT_H_INCLUDED
