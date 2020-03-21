#include "Statystyka.hh"

void licz_punkt(Stat &wyniki)
{
    wyniki.l_pop_odp++;
}
void licz_pytanie(Stat &wyniki)
{
    wyniki.l_pytan++;
}
void wyzeruj_statystyki(Stat &wyniki)
{
    wyniki.l_pop_odp = 0;
    wyniki.l_pytan = 0;
}
void wyswietl_statystyki(Stat &wyniki)
{
    cout << "Liczba poprawnych odpowiedzi: " << wyniki.l_pop_odp << endl;
    cout << "Liczba niepoprawnych odpowiedzi: " << wyniki.l_pytan - wyniki.l_pop_odp << endl;
    cout << "Wynik procentowy: " << (wyniki.l_pop_odp / wyniki.l_pytan) * 100 << '%' << endl;
}