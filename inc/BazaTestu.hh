#ifndef BAZATESTU_HH
#define BAZATESTU_HH

#include "WyrazenieZesp.hh"

/*
 * Modeluje pojecie baze testu z zestawem pytan w tablicy
 * oraz informacji o maksymalnej ilosci pytan, jak
 * tez indeksem nastepnego pytania, ktore ma byc pobrane
 * z bazy.
 */

bool InicjalizujTest(fstream &plik,string sNazwaTestu);
bool PobierzNastpnePytanie(istream &plik, WyrazenieZesp &wskWyr);

#endif
