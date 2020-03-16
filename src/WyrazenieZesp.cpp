#include "WyrazenieZesp.hh"

void Wyswietl(WyrazenieZesp WyrZ)
{
    cout << "(" << WyrZ.Arg1.re << showpos << WyrZ.Arg1.im << noshowpos << "i)";
    switch (WyrZ.Op)
    {
    case Op_Dodaj:
        cout << '+';
        break;
    case Op_Odejmij:
        cout << '-';
        break;
    case Op_Mnoz:
        cout << '*';
        break;
    case Op_Dziel:
        cout << '/';
        break;
    }
    cout << "(" << WyrZ.Arg2.re << showpos << WyrZ.Arg2.im << noshowpos << "i)" << endl;
}

LZespolona Oblicz(WyrazenieZesp Wyr)
{
    LZespolona LZ1 = Wyr.Arg1, LZ2 = Wyr.Arg2;
    LZespolona Wynik;
    switch (Wyr.Op)
    {
    case Op_Dodaj:
        Wynik = LZ1 + LZ2;
        break;
    case Op_Odejmij:
        Wynik = LZ1 - LZ2;
        break;
    case Op_Mnoz:
        Wynik = LZ1 * LZ2;
        break;
    case Op_Dziel:
        Wynik = LZ1 / LZ2;
        break;
    default:
        cerr << "Bledne dzialanie, obliczenie niemozliwe" << endl;
    }
    return Wynik;
}

bool porownaj(WyrazenieZesp Dzialanie, LZespolona odp)
{
    LZespolona Wynik;
    
    Wynik = Oblicz(Dzialanie);
    if (Wynik.re != odp.re || Wynik.im != odp.im)
        return false;
    else
        return true;
}
/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
