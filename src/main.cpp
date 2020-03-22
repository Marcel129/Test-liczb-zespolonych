#include <iostream>
#include "Statystyka.hh"
#include "BazaTestu.hh"
#define ILOSCPROB 3

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
    cout << "Podaj wartosc wyrazenia:" << WyrZ_PytanieTestowe;
    for (int i = 0; i < ILOSCPROB; i++)
    {
      cout << "Twoja odpowiedz to ";
      if (cin >> OdpowiedzUzytkownika) //jesli poprawnie wczytano odpowiedz, przejdz do jej analizy
      {
        i=ILOSCPROB;//ustawiamy warunek petli sprawdzajacej poprawnosc zapisu liczby na false, aby przejsc do kolejnego pytania
        if (porownaj(WyrZ_PytanieTestowe, OdpowiedzUzytkownika)) //jeśli odpowiedź jest poprawna
        {
          cout << "Poprawna odpowiedz" << endl; //wyświetl komunikat
          licz_punkt(Odp);                                //dolicz punkt
        }
        else
          cout << "Bledna odpowiedz" << endl; //jeśli nie, to wyświetl komunikat
      }
      else //jesli odpowiedz byla zle wprowadzona wczysc bufor i zapytaj ponownie
      {
        cout << "Blad zapisu liczby zespolonej, sprobuj jeszcze raz" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
      }
    }
    licz_pytanie(Odp); //dolicz pytanie do puli
  }

  wyswietl_statystyki(Odp);
  cout << endl
       << " Koniec testu" << endl
       << endl;
}
