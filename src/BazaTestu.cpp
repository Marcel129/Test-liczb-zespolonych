#include <iostream>
#include <fstream>
#include <cstring>
#include <cassert>
#include "BazaTestu.hh"

using namespace std;

bool InicjalizujTest(fstream &plik, string sNazwaTestu)
{

  plik.open(sNazwaTestu, ios::in);
  if (plik.good())
    return true;
  else
    return false;
}

bool PobierzNastpnePytanie(istream &plik, WyrazenieZesp &Wyrazenie)
{
  plik >> Wyrazenie;
  if (plik.fail() == true || plik.eof())
  {
    return false;
  }
  else
    return true;
}
