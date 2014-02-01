#ifndef TNO_H_INCLUDED
#define TNO_H_INCLUDED

class TNo
{
    private:
        int n;
        float info;
        TNo *next;
    public:
        TNo(int j);
        ~TNo();
        float getInfo();
        int getJ();
        void setInfo(float val);
        TNo* getNext();
        void setNext(TNo *p);
};

#endif // TNO_H_INCLUDED
