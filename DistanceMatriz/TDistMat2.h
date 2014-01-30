#ifndef TDISTMAT2_H
#define TDISTMAT2_H


class TDistMat2
{
    private:
        int n; // Ordem da matriz
        TList *mat; // Vetor que armazena a matriz
        bool isValidIndex(int i, int j); // Verifica se o índice é válido
        int convertIndex(int i, int j); // Se i e j forem válidos, converte o i e j para o índice correto no vetor
    public:
        TDistMat2();
        float getDist(int i, int j); // Consulta a distância na posição i e j
        void setDist(int i, int j, float dist); // Atribui uma distância à posição i e j
        void print(); // Imprime a matriz
        virtual ~TDistMat2();

};

#endif // TDISTMAT2_H
