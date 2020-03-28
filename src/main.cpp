#include <iostream>
#include <fstream>
#include "Statystyka.hh"
#include "BazaTestu.hh"
#include <cstdio>
#define ILOSCPROB 3
/*
Zadania dodatkowe:
Program wczytuje dane z pliku, sprawdza poprawność wprowadzanych wyrażeń. Nazwa pliku musi być podana jako argument wywołania programu
Program częściowo rozpoznaje skróconą notacje, muszą być podane nawiasy, radzi sobie z pomijaniem zer i jednek przy i
*/

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    std::cout << endl;
    std::cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    std::cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    std::cout << endl;
    return 1;
  }
  fstream BazaPlikowa;
  string tryb = argv[1];

  if (InicjalizujTest(BazaPlikowa, tryb) == false)
  {
    cerr << "Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }

  std::cout << endl;
  std::cout << " Start testu arytmetyki zespolonej. Pytania z pliku: " << argv[1] << endl;
  std::cout << endl;

  WyrazenieZesp WyrZ_PytanieTestowe;
  LZespolona OdpowiedzUzytkownika;
  Stat Odp;

  wyzeruj_statystyki(Odp);

  while (PobierzNastpnePytanie(BazaPlikowa, WyrZ_PytanieTestowe))
  {
    std::cout << "Podaj wartosc wyrazenia:" << WyrZ_PytanieTestowe;
    for (int i = 0; i < ILOSCPROB; i++)
    {
      std::cin >> OdpowiedzUzytkownika;
      std::cout << "Twoja odpowiedz to "<<OdpowiedzUzytkownika<<endl;
      if (std::cin.fail()==false) //jesli poprawnie wczytano odpowiedz, przejdz do jej analizy
      {
        i = ILOSCPROB;                                           //ustawiamy warunek petli sprawdzajacej poprawnosc zapisu liczby na false, aby przejsc do kolejnego pytania
        if (porownaj(WyrZ_PytanieTestowe, OdpowiedzUzytkownika)) //jeśli odpowiedź jest poprawna
        {
          std::cout << "Poprawna odpowiedz" << endl; //wyświetl komunikat
          licz_punkt(Odp);                           //dolicz punkt
        }
        else
          std::cout << "Bledna odpowiedz" << endl; //jeśli nie, to wyświetl komunikat
      }
      else //jesli odpowiedz byla zle wprowadzona wczysc bufor i zapytaj ponownie
      {
        std::cout << "Blad zapisu liczby zespolonej, sprobuj jeszcze raz" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
      }
    }
    licz_pytanie(Odp); //dolicz pytanie do puli
  }

  std::cout << Odp;
  std::cout << endl
            << " Koniec testu" << endl
            << endl;
}
