#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
#include <cmath>
using namespace std;

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */

/*!
 * Modeluje pojecie liczby zespolonej
 */
struct LZespolona
{
  double re; /*! Pole repezentuje czesc rzeczywista. */
  double im; /*! Pole repezentuje czesc urojona. */
};

/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */
void CzytajOdp(LZespolona *Odpowiedz);
void Wyswietl(LZespolona Odpowiedz);

LZespolona operator+(LZespolona Skl1, LZespolona Skl2);
LZespolona operator-(LZespolona Skl1, LZespolona Skl2);
LZespolona operator*(LZespolona Skl1, LZespolona Skl2);
LZespolona operator/(LZespolona Skl1, LZespolona Skl2);

bool CzyRoznaOdZera(LZespolona LZ);

LZespolona sprzezenie(LZespolona);
double modul(LZespolona LZ);

#endif
