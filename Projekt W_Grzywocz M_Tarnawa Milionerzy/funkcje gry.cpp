#include "Header.h"


void beginning()
{
    cout << endl << endl;
    coutCentered("MILIONERZY");
    cout << endl<<endl<< endl;
    coutCentered("Dost�pne opcje :");
    cout << endl << endl;;
    coutCentered("GRAJ");
    cout << endl;
    coutCentered("DODAJ PYTANIE");
    cout << endl;
    coutCentered("USUN PYTANIE");
};


void Questions::wyswietl(int k)
{
    cout << "Pytanie " << k + 1 << endl;
    cout << question << endl;
    cout << "A) " << answer1 << endl;
    cout << "B) " << answer2 << endl;
    cout << "C) " << answer3 << endl;
    cout << "D) " << answer4 << endl;
}

void kola(bool kolo1, bool kolo2, bool kolo3) // wypisuje czy mamy dost�pne(niewykorzystywane) ko�a ratunkowe
{
    cout << left << endl << setw(30) << "Telefon do przyjaciela(T) " << kolo1;
    cout << left << endl << setw(30) << "Pytanie do eksperta(E)  " << kolo2;
    cout << left << endl << setw(30) << "Pytanie do publiczno�ci(P)  " << kolo3 << endl;

}

void przeliczanie()
{
    for (int i = 0; i < 5; i++)
    {
        backgroundColor = BACKGROUND_BLUE;
        textColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
        setConsoleColor(backgroundColor | textColor);
        system("cls");
        
        cout << "Przeliczanie wyniku prosz� czeka�...." << 5 - i<< endl;
        this_thread::sleep_for(chrono::seconds(1));
        system("cls");
        backgroundColor = BACKGROUND_BLUE;
        setConsoleColor(backgroundColor | textColor);
    }
    
}

void wygrana(bool war1, int b)// Podaje nagrod�
{
    if (war1)// jesli sie wycofali�my lub wygrali�my
    {
        switch (b)
        {
        case 12:
            cout << "Gratulacje! Wygra�e� 1.000.000!" << endl;
            break;
        case 11:
            cout << "Wygra�e� 500.000!" << endl;
            break;
        case 10:
            cout << "Wygra�e� 250.000!" << endl;
            break;
        case 9:
            cout << "Wygra�e� 125.000!" << endl;
            break;
        case 8:
            cout << "Wygra�e� 75.000!" << endl;
            break;
        case 7:
            cout << "Wygra�e� 40.000!" << endl;
            break;
        case 6:
            cout << "Wygra�e� 20.000!" << endl;
            break;
        case 5:
            cout << "Wygra�e� 10.000!" << endl;
            break;
        case 4:
            cout << "Wygra�e� 5.000!" << endl;
            break;
        case 3:
            cout << "Wygra�e� 2.000!" << endl;
            break;
        case 2:
            cout << "Wygra�e� 1.000!" << endl;
            break;
        case 1:
            cout << "Wygra�e� 500!" << endl;
            break;
        default:
            cout << "Niestety, nie wygra�e� �adnej nagrody." << endl;
            break;
        }
    }
    else { // je�li �le odpowiedzieli�my
        if ((b) >= 2 && b < 7)
        {
            cout << "Wygra�e� 1.000!" << endl;

        }
        if ((b) >= 7 && b < 11)
        {
            cout << "Wygra�e� 40.000!" << endl;

        }
        if (b < 2)
        {
            cout << "Niestety nic nie wygra�e�, nie martw si�, dasz rad� nast�pnym razem";
        }
    }

}


