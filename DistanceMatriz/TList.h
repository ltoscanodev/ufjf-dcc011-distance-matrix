#ifndef TLIST_H_INCLUDED
#define TLIST_H_INCLUDED

#include "TNo.h"

class TList
{
    private:
        TNo *first; //Ponteiro para o primeiro item da lista
        TNo *last; //Ponteiro para o último item da lista
        TNo *it; //Ponteiro para determinado item da lista
    public:
        TList();
        ~TList();
        bool searchDist(int index);
        float getDist();
        float getDist(int j);
        void setDist(float dist);
        void setDist(int j, float dist);
        bool isEmpty();
        void print();
};

#endif // TLIST_H_INCLUDED
