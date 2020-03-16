#include <iostream>
#include "Statystyka.hh"
#include "BazaTestu.hh"

using namespace std;

int main(int argc, char **argv)
{

  if (argc < 2)
  {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }

  BazaTestu BazaT = {nullptr, 0, 0};

  if (InicjalizujTest(&BazaT, argv[1]) == false)
  {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }

  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp WyrZ_PytanieTestowe;
  LZespolona OdpowiedzUzytkownika;
  Stat Odpowiedzi, &Odp = Odpowiedzi;

  wyzeruj_statystyki(Odp);

  while (PobierzNastpnePytanie(&BazaT, &WyrZ_PytanieTestowe))
  {
    Wyswietl(WyrZ_PytanieTestowe);
    CzytajOdp(&OdpowiedzUzytkownika);
    if (porownaj(WyrZ_PytanieTestowe, OdpowiedzUzytkownika))//jeśli odpowiedź jest poprawna
    {
      cout << "Poprawna odpowiedz, jeeej!!!" << endl;//wyświetl komunikat
      licz_punkt(Odp);//dolicz punkt
    }
    else
      cout << "Zla odpowiedz, meehhhhhh......" << endl;//jeśli nie, to wyświetl komunikat
    licz_pytanie(Odp);//dolicz pytanie do puli
  }
  cout << "Twoje wyniki to: " << Odp.l_pop_odp << " poprawnych odpowiedzi, podczas gdy liczba pytan wynosiła " << Odp.l_pytan << endl;

  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
}
