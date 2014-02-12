#include <iostream>
#include "TList.h"

using namespace std;

TList::TList()
{
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

float TList::getDist(int j)
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

bool TList::searchDist(int j)
{
    if(!isEmpty())
    {
        TNo *p = first;

        while(p != NULL)
        {
            if(p->getIndex() == j)
            {
                it = p;
                return true;
            }

            p = p->getNext();
        }
    }

    return false;
}

void TList::setDist(float dist)
{
    if(it != NULL)
        it->setInfo(dist);
}

void TList::setDist(int j, float dist)
{
    if(searchDist(j))
        setDist(dist);
    else
    {
        TNo *p = new TNo(j);
        p->setInfo(dist);
        p->setNext(NULL);

        if(!isEmpty())
            last->setNext(p);
        else
            first = p;

        last = p;
    }
}

bool TList::isEmpty()
{
    return (first == NULL);
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
