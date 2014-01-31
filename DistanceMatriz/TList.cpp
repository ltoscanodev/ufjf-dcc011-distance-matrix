#include <iostream>
#include "TList.h"

using namespace std;

TList::TList()
{
    first = NULL;
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
    int k;
    for(k = 0; k < j && aux->getNext() != NULL; k++)
        aux = aux->getNext();
    if(k == j)
        return aux->getInfo();

    return -1;
}

void TList::setDist(float dist)
{
    it->setInfo(dist);
}

void TList::setDistJ(int j, float dist)
{
    TNo *aux = first;
    int k;
    for(k = 0; k < j && aux->getNext() != NULL; k++)
        aux = aux->getNext();
    if(k == j)
        aux->setInfo(dist);
    else
        cout << "ERRO DE INSERÇÃO, COLUNA INVÁLIDA" << endl;
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

void TList::insertLast(float dist)
{
    TNo *p = new TNo();
    p->setInfo(dist);
    TNo *aux = first;
    if(aux == NULL)
    {
        first = p;
        it = first;
    }
    else
    {
        while(aux->getNext() != NULL)
            aux = aux->getNext();
        aux->setNext(p);
    }
}

//FALTA FAZER UM MÉTODO QUE APAGUE !!!!
