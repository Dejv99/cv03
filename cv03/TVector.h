#pragma once

struct TVector
{
    size_t iSize = 0;
    size_t iCapacity = 0;
    double* iData = nullptr;
};

double Get(TVector& aVec, size_t aIndex);

void Set(TVector& aVec, size_t aIndex, double aVal);

void AllocVector(TVector& aVec, size_t aSize);

void DeallocVector(TVector& aVec);

int Add(TVector& aRes, const TVector& aVec1, const TVector& aVec2);

int Add(TVector& aRes, const TVector& aVec1, double aVal = 0);