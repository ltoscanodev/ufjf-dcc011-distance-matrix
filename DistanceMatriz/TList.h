#ifndef TLIST_H_INCLUDED
#define TLIST_H_INCLUDED

class TList
{
    private:
        TNo *first;
        TNo *it;
    public:
        TList();
        ~TList();
        float getDist();
        void setDist(float dist);
        void start();
        void next();
        bool isEnd();
};

#endif // TLIST_H_INCLUDED
