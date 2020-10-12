#include <iostream>
#include "TVector.h"

using std::cout;

// --------------------------- funkce FceMin a FMin -------------------------------
double& FceMin(double& p1, double* p2)
{
    return (p1 <= *p2) ? (p1) : (*p2);  // (*p2) <-- Vraci se ”hodnota”, referenci udela prekladac.
}

double& FMin(double& aA, double& aB)
{
    return (aA <= aB) ? (aA) : (aB);
}
// --------------------------------------------------------------------------------

// ----------------------------- funkce ReturnRef ---------------------------------
void fr(float& ri)
{
    ri *= 10;
}

void fr(int& ri)
{
    ri *= 10;
}

int& frr(int& ri)
{
    return ri;
}
// --------------------------------------------------------------------------------

int main()
{
// --------------------------- funkce FceMin a FMin -------------------------------
    double a = 1;    // Inicializace zpusob 1
    double b(3);     // Inicializace zpusob 2 (C++), rovno zapisu "b = 3"
    double c{ 0 };   // Inicializace zpusob 3 (C++ 2017), rovno zapisu "c = 0"

    cout << "a: " << a << '\n' << "b: " << b << '\n' << "c: " << c << '\n' << '\n';
    c = FMin(a, b);

    cout << "a: " << a << '\n' << "b: " << b << '\n' << "c: " << c << '\n';
    cout << "Mensi prvek: " << c << '\n' << '\n';

    FMin(a, b) = 10;    // FMin vrati mensi z prvku a ten bude prepsan hodnotou 10.
    cout << "a: " << a << '\n' << "b: " << b << '\n' << "c: " << c << '\n' << '\n';
// --------------------------------------------------------------------------------

// ----------------------------- funkce ReturnRef ---------------------------------
    int ii = 10;
    int& ri = ii;
    ri = 69;        // Tu se 'ii' prepise na 69
    fr(ii);         // Automaticka konverze z int na int &
    fr(ri);

    float f = 3.14f;
    fr(f);          // Pretizeni funkce 'fr'
    frr(ii) = 7;    // Vrati se misto, kde lezi 'ii' a do nej se zapise 5.

    cout << "f: " << f << '\n';
    cout << ii << '\n';
    cout << ri << '\n' << '\n';
// --------------------------------------------------------------------------------

// ------------------------------ funkce TVector ----------------------------------
    TVector v, v1, v2, vRes;
    try
    {
        AllocVector(v, 10);
        Set(v, 9, 5.0);
        cout << Get(v, 9) << '\n' << '\n';

        AllocVector(v1, 10);
        AllocVector(v2, 10);
        AllocVector(vRes, 10);

        for (size_t i = 0; i < v1.iSize; i++)
            Set(v1, i, (double)(i + 1.0));
        for (size_t i = 0; i < v2.iSize; i++)
            Set(v2, i, (double)3.0);

        Add(vRes, v1, v2);

        for (size_t i = 0; i < v.iSize; i++)
            cout << Get(v1, i) << '\t';
        cout << '\n';
        for (size_t i = 0; i < v.iSize; i++)
            cout << Get(v2, i) << '\t';
        cout << '\n';
        for (size_t i = 0; i < v.iSize; i++)
            cout << Get(vRes, i) << '\t';
        cout << '\n';

        Add(vRes, v1, 2);
        for (size_t i = 0; i < v.iSize; i++)
            cout << Get(vRes, i) << '\t';
        cout << '\n';
    }

    catch (const char aStr[])
    {
        cout << "Vyjimka: " << aStr << '\n';
    }

    catch (std::bad_alloc exc)
    {
        cout << "vyjimka bad_alloc: " << exc.what() << '\n';    // exc.what() ... kde vznikla vyjimka
    }

    catch (...)
    {
        cout << "obecna vyjimka\n";
    }

    DeallocVector(v);
    DeallocVector(v1);
    DeallocVector(v2);
    DeallocVector(vRes);
// --------------------------------------------------------------------------------
    return 0;
}