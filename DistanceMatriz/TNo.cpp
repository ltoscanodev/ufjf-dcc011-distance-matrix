#include "TNo.h"

TNo::TNo(int j)
{
    index = j;
}

TNo::~TNo() { }

int TNo::getIndex()
{
    return index;
}

float TNo::getInfo()
{
    return info;
}

void TNo::setInfo(float val)
{
    info = val;
}

TNo* TNo::getNext()
{
    return next;
}

void TNo::setNext(TNo *p)
{
    next = p;
}
