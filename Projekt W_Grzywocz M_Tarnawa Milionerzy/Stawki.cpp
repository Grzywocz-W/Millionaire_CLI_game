#include "Header.h"





void stawki() // wypisuje stawki wygranej
{

    //kolor(czerwony);
    cout << " Tak oto wygl¹daj¹ nagrody za poszczególne pytania" << endl;
    cout << setw(2) << "12" << setw(15) << fixed << setprecision(2) << "1.000.000" << endl;
    cout << setw(2) << "11" << setw(15) << fixed << setprecision(2) << "500.000" << endl;
    cout << setw(2) << "10" << setw(15) << fixed << setprecision(2) << "250.000" << endl;
    cout << setw(2) << "9" << setw(15) << fixed << setprecision(2) << "125.000" << endl;
    cout << setw(2) << "8" << setw(15) << fixed << setprecision(2) << "75.000" << endl;
    backgroundColor = BACKGROUND_BLUE;
    textColor = FOREGROUND_RED;
    setConsoleColor(backgroundColor | textColor);
    cout << setw(2) << "7" << setw(15) << fixed << setprecision(2) << "40.000" << endl;
    textColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    setConsoleColor(backgroundColor | textColor);
    cout << setw(2) << "6" << setw(15) << fixed << setprecision(2) << "20.000" << endl;
    cout << setw(2) << "5" << setw(15) << fixed << setprecision(2) << "10.000" << endl;
    cout << setw(2) << "4" << setw(15) << fixed << setprecision(2) << "5.000" << endl;
    cout << setw(2) << "3" << setw(15) << fixed << setprecision(2) << "2.000" << endl;
    textColor = FOREGROUND_RED;
    setConsoleColor(backgroundColor | textColor);
    cout << setw(2) << "2" << setw(15) << fixed << setprecision(2) << "1.000" << endl;
    textColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    setConsoleColor(backgroundColor | textColor);
    cout << setw(2) << "1" << setw(15) << fixed << setprecision(2) << "500" << endl;
    cout << endl << "Na ";
    textColor = FOREGROUND_RED;
    setConsoleColor(backgroundColor | textColor);
    cout << "czerwono ";
    textColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    setConsoleColor(backgroundColor | textColor);
    cout << "zaznaczono progi gwarantowane [ENTER]";

}