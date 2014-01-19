#ifndef TNO_H_INCLUDED
#define TNO_H_INCLUDED

class TNo
{
    private:
        float info;
        TNo *next;
    public:
        TNo();
        ~TNo();
        float getInfo();
        void setInfo(float val);
        TNo* getNext();
        void setNext(TNo *p);
};

#endif // TNO_H_INCLUDED
