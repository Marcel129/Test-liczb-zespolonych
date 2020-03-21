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
  Stat Odp;

  wyzeruj_statystyki(Odp);

  while (PobierzNastpnePytanie(&BazaT, &WyrZ_PytanieTestowe))
  {
    cout << "Podaj wartosc wyrazenia:" << WyrZ_PytanieTestowe << "Twoja odpowiedz to ";
    cin >> OdpowiedzUzytkownika;
    if (porownaj(WyrZ_PytanieTestowe, OdpowiedzUzytkownika)) //jeśli odpowiedź jest poprawna
    {
      cout << "Poprawna odpowiedz, jeeej!!!" << endl; //wyświetl komunikat
      licz_punkt(Odp);                                //dolicz punkt
    }
    else
      cout << "No chyba nie" << endl; //jeśli nie, to wyświetl komunikat
    licz_pytanie(Odp);                //dolicz pytanie do puli
  }

  wyswietl_statystyki(Odp);
  cout << endl<< " Koniec testu" << endl<< endl;
}
