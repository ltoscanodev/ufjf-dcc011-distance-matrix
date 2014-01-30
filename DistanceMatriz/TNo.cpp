#include "TNo.h"

TNo::TNo() { }

TNo::~TNo() { }

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
