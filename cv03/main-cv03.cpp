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
    frr(ii) = 5;    // Vrati se misto, kde lezi 'ii' a do nej se zapise 5.

    cout << "f: " << f << '\n';
    cout << ii << '\n';
    cout << ri << '\n';
// --------------------------------------------------------------------------------

// ------------------------------ funkce TVector ----------------------------------
    TVector v;
    try
    {
        AllocVector(v, 10);
        Set(v, 9, 5.0);
        cout << Get(v, 9) << '\n';
    }

    catch (char aStr[])
    {
        cout << "Vyjimka: " << aStr << '\n';
    }

    catch (std::bad_alloc exc)
    {
        cout << "Vyjimka bad_alloc: " << exc.what() << '\n';    // exc.what() ... kde vznikla vyjimka
    }

    catch (...)
    {
        cout << "Obecna vyjimka\n";
    }

    DeallocVector(v);
// --------------------------------------------------------------------------------
    return 0;
}