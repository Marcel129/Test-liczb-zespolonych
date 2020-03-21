#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

#include "WyrazenieZesp.hh"

struct Stat {
    float l_pytan;
    float l_pop_odp;
};

void licz_punkt(Stat &wyniki);
void licz_pytanie(Stat &wyniki);
void wyzeruj_statystyki(Stat &wyniki);
void wyswietl_statystyki(Stat &wyniki);

#endif