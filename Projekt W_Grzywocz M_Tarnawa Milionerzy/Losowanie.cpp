#include "Header.h"


using namespace std; // U¿ycie namespace std

void drawing(int n,bool logic[], int wylosowane[])
{
    // Inicjalizacja generatora liczb pseudolosowych
    mt19937 generator(time(nullptr));
    uniform_int_distribution<int> distribution(1, n);

    // Generowanie trzech liczb losowych od 1 do n
    int zmienna = distribution(generator);
    wylosowane[0] = zmienna;
    logic[zmienna] = true;

    bool w1 = false;
    // logika zawiera informacje czy dana liczba ju¿ zosta³a wylosowana jeœli tak to tab[n] = true
    // np. jeœli wylosuje 12 tab[12] = true
    // wylosowana zawiera wylosowan¹ liczbê
    for (int j = 1; j < 12; j++)
    {
        w1 = false;
        zmienna = distribution(generator);
        while (w1 == false)
        {
            if (logic[zmienna] == true)
            {
                zmienna += 0;
                zmienna = distribution(generator);
            }
            else
            {
                logic[zmienna] = true;
                wylosowane[j] = zmienna;
                w1 = true;
            }
        }
    }
    
}


int maks = 10000000000000000000;