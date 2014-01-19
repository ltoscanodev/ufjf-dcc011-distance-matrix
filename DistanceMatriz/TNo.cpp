#include "TNo.h"

TNo::TNo() { }

TNo::~TNo() { }

float TNo::getInfo()
{
    return dist;
}

void TNo::setInfo(float val)
{
    dist = val;
}

TNo* TNo::getNext()
{
    return next;
}

void TNo::setNext(TNo *p)
{
    next = p;
}
