#include <iostream>
using namespace std;
const int WMAX = 50, KMAX = 50;

void wypisz_wektor(float Przekazany_wektor[], int);
void wczytaj_macierz(float mac[][KMAX], int w, int k);

int main()
{
    float Wektor[WMAX];
    float Macierz[WMAX][KMAX];
    int ob_rob_w, ob_rob_k;
    int ktory_wiersz;

    std::cout << "Podaj ilość wierszy macierzy: ";
    std::cin >> ob_rob_w;
    std::cout << "Podaj ilość kolumn macierzy: ";
    std::cin >> ob_rob_k;
    wczytaj_macierz(Macierz, ob_rob_w, ob_rob_k);
    std::cout << "Ktory wiersz chcesz wyswietlic?" << std::endl;
    std::cin >> ktory_wiersz;
    wypisz_wektor(Macierz[ktory_wiersz - 1], ob_rob_k);
}

void wczytaj_macierz(float Macierz[][KMAX], int ob_rob_w, int ob_rob_k)
{
    for (int j = 0; j < ob_rob_w; ++j)
    {
        for (int i = 0; i < ob_rob_k; ++i)
        {
            std::cout << "Podaj " << i + 1 << " element wiersza" << j + 1 << ": " << std::endl;
            std::cin >> Macierz[j][i];
        }
    }
    for (int j = 0; j < ob_rob_w; ++j)
    {
        for (int i = 0; i < ob_rob_k; ++i)
        {
            cout<< Macierz[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void wypisz_wektor(float Przekazany_wektor[], int rozmiar)
{
    std::cout << "Elementy wektora to:" << std::endl;
    for (int i = 0; i < rozmiar; ++i)
    {
        std::cout << Przekazany_wektor[i] << "\t";
    };
    std::cout << std::endl;
}

