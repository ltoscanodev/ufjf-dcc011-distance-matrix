#ifndef TLIST_H_INCLUDED
#define TLIST_H_INCLUDED

#include "TNo.h"

class TList
{
    private:
        TNo *first; //Ponteiro para o primeiro item da lista
        TNo *it; //Ponteiro para determinado item da lista
    public:
        TList();
        ~TList();
        float getDist();
        float getDistJ(int j);
        void setDist(float dist);
        void setDistJ(int j, float dist);
        void insertLast(float dist);
        void start();
        void next();
        bool isEnd();
};

#endif // TLIST_H_INCLUDED
