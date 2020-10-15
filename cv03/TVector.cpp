#pragma once
#include <iostream>
#include "TVector.h"
#include "C:/GitHub/BPC-PPC/checker/check.h"

using std::cout;

double Get(const TVector& aVec, size_t aIndex)
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

    for (size_t i = 0; i < aVec.iCapacity; ++i)
        aVec.iData[i] = 0;
}

void DeallocVector(TVector& aVec)
{
    delete[] aVec.iData;
    aVec.iSize = aVec.iCapacity = 0;
    aVec.iData = nullptr;
}

int Add(TVector& aRes, const TVector& aVec1, const TVector& aVec2)
{
    if ((aVec1.iSize != aRes.iSize) || (aVec2.iSize != aRes.iSize))
        throw "Vstupni vektory nemaji stejnou delku";

    for (size_t i = 0; i < aVec1.iSize; ++i)    // <--  ++i je efektivnejsi (nez i++) pri pouzivani vetsich struktur (iterátory)
        aRes.iData[i] = aVec1.iData[i] + aVec2.iData[i];

    //for (double& i : aRes)
    //    i += aVal;
    return 0;
}

int Add(TVector& aRes, const TVector& aVec1, double aVal)
{
    if (aVec1.iSize != aRes.iSize)
        throw "Vstupni vektory nemaji stejnou delku";

    for (size_t i = 0; i < aVec1.iSize; i)
        aRes.iData[i] = aVec1.iData[i] + aVal;
    return 0;
}

void DumpVector(const TVector& aVec, const char* aStr)    //tisk vektoru
{
    if (aStr)
        cout << aStr << ": ";
    cout << "{ ";
    for (size_t i = 0; i < aVec.iSize; ++i)
        cout << aVec.iData[i] << ", ";
    cout << "}\n";
}