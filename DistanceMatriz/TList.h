#ifndef TLIST_H_INCLUDED
#define TLIST_H_INCLUDED
#include "TNo.h"

class TList
{
    private:
        TNo *first; // Primeiro elemento da lista
        TNo *last; // Último elemento da lista
        TNo *it; // Utilizado na busca por um elemento

        bool searchDist(int index); // Busca por um índice j da matriz
        float getDist(); // Consulta a distância do nó it
        void setDist(float dist); // Atribui uma distância ao nó it
    public:
        TList(); // Construtor do TAD
        ~TList(); // Destrutor do TAD
        float getDist(int j); // Consulta a distância por um índice j da matriz
        void setDist(int j, float dist); // Atribui um índice e uma distância da matriz
        bool isEmpty(); // Verifica se a lista está vazia
        void print(); // Imprime a matriz
};

#endif // TLIST_H_INCLUDED
