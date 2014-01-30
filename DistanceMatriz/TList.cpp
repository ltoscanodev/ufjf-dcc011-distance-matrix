#include <iostream>
#include "TList.h"

using namespace std;

TList::TList(int linha)
{
    first = NULL;
    it = NULL;
    i = linha;
}

TList::~TList() {
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

void TList::setDist(float val){
    it->setInfo(val);
}

void TList::start() {
    it = first;
}

void TList::next(){
    if(!isEnd()){
        it = it->getNext();
    } else {
        cout << "Não há mais valores nesta linha" << endl;
    }
}

bool TList::isEnd(){
    if(it->getNext() == NULL)
        return true;
    return false;
}

void TList::insertLast(float dist){
    TNo *p = new TNo();
    p->setInfo(dist);

    TNo *aux = first;

    if(aux == NULL){
        first = p;
    } else{

        while(aux->getNext() != NULL)
            aux = aux->getNext();

        aux->setNext(p);
    }
}


