#include <iostream>
#include "TList.h"

using namespace std;

TList::TList()
{
    n = 0;
    first = NULL;
    last = NULL;
    it = NULL;
}

TList::~TList()
{
    TNo *p = first;

    while(p != NULL)
    {
        TNo *t = p->getNext();
        delete p;
        p = t;
    }
}

float TList::getDist()
{
    return it->getInfo();
}

float TList::getDistJ(int j)
{
    TNo *aux = first;

    while(aux != NULL)
    {
        if(aux->getIndex() == j)
            return aux->getInfo();

        aux = aux->getNext();
    }

    return -1;
}

void TList::setDist(float dist) // Tirar isso
{
    it->setInfo(dist);
}

void TList::setDist(int j, float dist)
{
    TNo *p = new TNo(j);
    p->setInfo(dist);
    p->setNext(NULL);

    if(!isEmpty())
    {
        TNo *aux = last;
        aux->setNext(p);
        last = p;
    }
    else
    {
        first = p;
        last = p;
    }

    n++;
}


void TList::start()
{
    it = first;
}

void TList::next()
{
    if(!isEnd())
    {
        it = it->getNext();
    }
    else
    {
        cout << "N�o h� mais valores nesta linha" << endl;
    }
}

bool TList::isEnd()
{
    if(it->getNext() == NULL)
        return true;
    return false;
}

bool TList::isEmpty()
{
    return (n == 0);
}

void TList::print()
{
    TNo *p = first;

    while(p != NULL)
    {
        cout << "[" << p->getIndex() << "]: " << p->getInfo() << endl;
        p = p->getNext();
    }
}

//FALTA FAZER UM M�TODO QUE APAGUE !!!!
