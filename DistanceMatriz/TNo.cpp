#include "TNo.h"

TNo::TNo(int j)
{
    n = j;
}

TNo::~TNo() { }

float TNo::getInfo()
{
    return info;
}

int TNo::getJ()
{
    return n;
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
