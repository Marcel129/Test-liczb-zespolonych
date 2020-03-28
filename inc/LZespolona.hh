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
istream &operator >>(istream &strWej, LZespolona &wyr);//przeciążenie operatora >> dla liczby zespolonej
ostream &operator <<(ostream &strWyj, LZespolona &wyr);//przeciążenie operatora << dla liczby zespolonej

LZespolona operator+(LZespolona Skl1, LZespolona Skl2);
LZespolona operator-(LZespolona Skl1, LZespolona Skl2);
LZespolona operator*(LZespolona Skl1, LZespolona Skl2);
LZespolona operator/(LZespolona Skl1, LZespolona Skl2);
LZespolona operator/(LZespolona Skl1, float Skl2);

bool operator ==(LZespolona LZ,int zero); //funkcja sprawdzajaca, czy modul drugiej liczby zespolonej nie jest rowny 0

LZespolona sprzezenie(LZespolona); //funkcja obliczjaca sprzezenie liczby zes
double modul(LZespolona LZ); //funkcja obliczjaca modul liczby zes

#endif
