#include "WyrazenieZesp.hh"

ostream &operator<<(ostream &strWyj, WyrazenieZesp WyrZ)
{
    cout << WyrZ.Arg1 << WyrZ.Op << WyrZ.Arg2 << endl;
    return strWyj;
}

istream &operator>>(istream &strWej, WyrazenieZesp &WyrZ) //wczytywanie wyrażenia zespolonego
{
    while(!strWej.eof())
    {   
        strWej >> WyrZ.Arg1;
        if (strWej.fail() == false)
        {
            strWej >> WyrZ.Op;
            if (strWej.fail() == false && (WyrZ.Op == '+' || WyrZ.Op == '-' || WyrZ.Op == '*' || WyrZ.Op == '/'))
            {
                strWej >> WyrZ.Arg2;
                if (strWej.fail() == false)
                {
                    return strWej;
                }
            }
        }
        strWej.clear();
        strWej.ignore(10000, '\n');
        cout << "Napotkano błędne wyrażenie. Zostało ono pominięte." << endl;
    }

    return strWej;
}

LZespolona Oblicz(WyrazenieZesp Wyr)
{
    LZespolona LZ1 = Wyr.Arg1, LZ2 = Wyr.Arg2;
    LZespolona Wynik;

    if (Wyr.Op == '+')
        Wynik = LZ1 + LZ2;
    else if (Wyr.Op == '-')
        Wynik = LZ1 - LZ2;
    else if (Wyr.Op == '*')
        Wynik = LZ1 * LZ2;
    else if (Wyr.Op == '/')
        Wynik = LZ1 / LZ2;
    else
        cerr << "Bledne dzialanie, obliczenie niemozliwe" << endl;

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
