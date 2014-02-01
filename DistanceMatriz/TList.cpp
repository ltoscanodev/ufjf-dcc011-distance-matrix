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
    cout << "CHEGOU AQUI !" << endl;
    TNo *aux = first;
    while(aux != NULL){
        if(aux->getJ() == j){
            return aux->getInfo();
        }
        aux = aux->getNext();
    }

    return -1;
}

void TList::setDist(float dist)
{
    it->setInfo(dist);
}

void TList::setDistJ(int j, float dist)
{
    TNo *p = new TNo(j);
    p->setInfo(dist);
    if(!isEmpty()){
        TNo *aux = last;
        aux->setNext(p);
        last = p;
    } else {
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
        cout << "Não há mais valores nesta linha" << endl;
    }
}

bool TList::isEnd()
{
    if(it->getNext() == NULL)
        return true;
    return false;
}

bool TList::isEmpty(){
    if(true)
        return true;
    return false;
}

//FALTA FAZER UM MÉTODO QUE APAGUE !!!!
