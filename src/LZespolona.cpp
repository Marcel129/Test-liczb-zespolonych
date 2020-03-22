#include "LZespolona.hh"

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
istream &operator>>(istream &strWej, LZespolona &wyr)
{
  {
    char kosz;
    cin >> kosz;
    if (kosz == '(')
    {
      cin >> wyr.re;
      if (cin.fail() == false)
      {
        cin >> wyr.im;
        if (cin.fail() == false)
        {
          cin >> kosz;
          if (kosz == 'i')
          {
            cin >> kosz;
            if (kosz == ')')
            {
              return strWej;
            }
          }
        }
        else //przypadek, kiedy wczyta jedna liczbe, a nastepny jest znak
        {
          cin.clear();
          cin >> kosz;
          if (cin.fail() == false)
          {
            if (kosz == 'i') //kiedy po wczytaniu liczby wystepuje i, czyli jest sama czesc urojona
            {
              wyr.im = wyr.re;
              wyr.re = 0;
              cin >> kosz;
              if (kosz == ')')
              {
                return strWej;
              }
            }
            else if (kosz == ')') //kiedy po wczytaniu liczby nie wystepuje i, czyli jest sama czesc rzeczywista
            {
              wyr.im = 0;
              return strWej;
            }
          }
        }
      }
      else //przypadek, kiedy liczba jest samo i
      {
        cin.clear();
        cin >> kosz;
        if (kosz == 'i')
        {
          wyr.im = 1;
          wyr.re = 0;
          cin >> kosz;
          if (kosz == ')')
          {
            return strWej;
          }
        }
      }
    }
  }
  strWej.setstate(std::ios::failbit);

  return strWej;
}

ostream &operator<<(ostream &strWyj, LZespolona &wyr)
{
  cout << '(' << wyr.re << showpos << wyr.im << noshowpos << "i)";
  return strWyj;
}

LZespolona operator+(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona operator-(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona operator*(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
  return Wynik;
}

LZespolona operator/(LZespolona Skl1, LZespolona Skl2) //dzielenie liczby zespolonej przez liczbe zepolona
{
  LZespolona Wynik, Iloczyn;
  double modulKwadrat;           //zmienna pomocnicza do obliczenia modulu
  if (CzyRoznaOdZera(Skl2) == 0) //sprawdz, czy druga liczba nie jest zerem
  //pierwszy w kolejności jest warunek na rownosc z zerem, poniewaz w przeciwnym wypadku kompilator zwraca ostrzezenie
  {
    cerr << "Bledne dzialanie, dzielenie przez 0" << endl; //jesli jest zerem, wyswietl komunikat
  }
  Iloczyn = Skl1 * sprzezenie(Skl2);    //jesli nie, oblicz jej sprzezenie i pomnoz przez nie pierwsza liczbe
  modulKwadrat = pow(modul(Skl2), 2);   //oblicz kwadrat modulu drugiej liczby
  Wynik.re = Iloczyn.re / modulKwadrat; //podstaw obliczone wartosci do wyniku
  Wynik.im = Iloczyn.im / modulKwadrat;

  return Wynik;
}

LZespolona operator/(LZespolona Skl1, float Skl2) //dzielenie liczby zespolonej przez liczb rzeczywista
{
  LZespolona Wynik;

  if (Skl2 == 0) //sprawdz, czy druga liczba nie jest zerem
  //pierwszy w kolejności jest warunek na rownosc z zerem, poniewaz w przeciwnym wypadku kompilator zwraca ostrzezenie
  {
    cerr << "Bledne dzialanie, dzielenie przez 0" << endl; //jesli jest zerem, wyswietl komunikat
  }
  Wynik.re = Skl1.re / Skl2; //podstaw obliczone wartosci do wyniku
  Wynik.im = Skl1.im / Skl2;

  return Wynik;
}

bool CzyRoznaOdZera(LZespolona LZ)
{
  float modulLiczby = modul(LZ);
  if (modulLiczby == 0)
    return false;

  return true;
}

LZespolona sprzezenie(LZespolona LZ)
{
  LZespolona sprzezenie;
  sprzezenie.im = -LZ.im;
  return sprzezenie;
}

double modul(LZespolona LZ)
{
  float modul = sqrt(pow(LZ.re, 2) + pow(LZ.im, 2));
  return modul;
}