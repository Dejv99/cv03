#pragma once

struct TVector
{
    size_t iSize = 0;
    size_t iCapacity = 0;
    double* iData = nullptr;
};

double Get(TVector& aVec, size_t aIndex)
{
    if (aVec.iSize <= aIndex)
        throw "Index mimo vektor";
    return aVec.iData[aIndex];
}

void Set(TVector& aVec, size_t aIndex, double aVal)
{
    if (aVec.iSize <= aIndex)
        throw "Index mimo vektor";

    aVec.iData[aIndex] = aVal;
}

void AllocVector(TVector& aVec, size_t aSize)   // Neni potreba kontrolovat, jestli aVec == nullptr, aVec je totiz reference.
{
    if (aVec.iData)                             // kratsi zapis (aVec.iData == nullptr)
        throw "Jiz naalokovano";
    //while(true)
    //    new double[100000000ul];

    aVec.iData = new double[aSize];
    aVec.iSize = aSize;
    aVec.iCapacity = aSize;
}

void DeallocVector(TVector& aVec)
{
    delete[] aVec.iData;
    aVec.iSize = aVec.iCapacity = 0;
}