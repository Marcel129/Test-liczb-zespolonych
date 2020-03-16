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