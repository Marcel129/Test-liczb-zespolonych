#include "LZespolona.hh"

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
void CzytajOdp(LZespolona *Odpowiedz)
{
  char kosz;
  cin >> kosz >> Odpowiedz->re >> Odpowiedz->im >> kosz >> kosz;
}
void Wyswietl(LZespolona Odpowiedz)
{
  cout << "(" << Odpowiedz.re << showpos << Odpowiedz.im << noshowpos << "i)" << endl;
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

LZespolona operator/(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik, Iloczyn;
  double modulKwadrat;
  if (CzyRoznaOdZera(Skl2) == 0)
  {
    cerr << "Bledne dzialanie, dzielenie przez 0" << endl;
  }
  Iloczyn = Skl1 * sprzezenie(Skl2);
  modulKwadrat = pow(modul(Skl1), 2);
  Wynik.re = Iloczyn.re / modulKwadrat;
  Wynik.im = Iloczyn.im / modulKwadrat;

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