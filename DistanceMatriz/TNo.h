#ifndef TNO_H_INCLUDED
#define TNO_H_INCLUDED

class TNo
{
    private:
        int index;
        float info;
        TNo *next;
    public:
        TNo(int j);
        ~TNo();
        int getIndex();
        float getInfo();
        void setInfo(float val);
        TNo* getNext();
        void setNext(TNo *p);
};

#endif // TNO_H_INCLUDED
