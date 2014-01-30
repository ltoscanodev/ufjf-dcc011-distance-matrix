#ifndef TLIST_H_INCLUDED
#define TLIST_H_INCLUDED

class TList
{
    private:
        TNo *first; //Ponteiro para o primeiro item da lista
        TNo *it; //Ponteiro para determinado item da lista
        int i; //Determina qual é a linha
    public:
        TList(int linha);
        ~TList();
        float getDist();
        void setDist(float dist);
        void start();
        void next();
        bool isEnd();
};

#endif // TLIST_H_INCLUDED
