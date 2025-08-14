#include "Header.h"



void Questions::przyjaciel(bool warunek)
{
    if (warunek == 1)// Czy nadal mo�emy skorzysta� z ko�a
    {
        mt19937 generator(time(nullptr));
        uniform_int_distribution<int> distribution(1, 100); //szansa na to, �e przyajciel zna odpowied�
        uniform_int_distribution<int> unlucky(1, 4); // jesli nie to losujemy inn� odpowied�
        int chance = distribution(generator);
        if (chance <= 90) // mamy 90% szans na to, �e otrzymamy poprawn� odpowied�
        {
            cout << " S�uchaj stary wydaje mi si�, �e poprawna odpowied� to: " << correctAnswer << endl;
        }
        else
        {
            int pech = unlucky(generator);
            while (litera(pech) == correctAnswer)
            {
                int pech = unlucky(generator);
            }
            cout << " S�uchaj stary wydaje mi si�, �e poprawna odpowied� to: " << litera(pech) << endl;
        }

    }

}

void Questions::ekspert(bool warunek)
{
    if (warunek == 1)
    {
        mt19937 generator(time(nullptr));
        uniform_int_distribution<int> losowe(1, 4);
        int a = losowe(generator);
        int b = losowe(generator);
        // w tej p�tli sprawdzimy, czy odrzucane odpowiedzi nie s� poprawn� i czy s� r�ne od siebie
        while (litera(a) == correctAnswer || litera(b) == correctAnswer || litera(b) == litera(a))
        {
            //cout << '1';
            a = losowe(generator);
            b = losowe(generator);
        }

        cout << "Po przeanalizowaniu pytania nale�y wykluczy� odpowied� ";
        backgroundColor = BACKGROUND_BLUE;
        textColor = FOREGROUND_RED;
        setConsoleColor(backgroundColor | textColor);
        cout << litera(a);
        textColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
        setConsoleColor(backgroundColor | textColor);
        cout << " i ";
        textColor = FOREGROUND_RED;
        setConsoleColor(backgroundColor | textColor);
        cout << litera(b);
        textColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
        setConsoleColor(backgroundColor | textColor);
        cout << endl;
    }
}


void Questions::pub(bool warunek)
{
    if (warunek == 1)
    {
        int o = 100;
        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;
        cout << "Wyniki g�osowania publiczno�ci: \n";

        std::mt19937 generator(time(nullptr));
        std::uniform_int_distribution<int> losowe1(40, 60);

        if (correctAnswer == "A")
        {
            a = losowe1(generator);
            o -= a;
            std::uniform_int_distribution<int> losowe2(0, o);
            b = losowe2(generator);
            o -= b;
            std::uniform_int_distribution<int> losowe3(0, o);
            c = losowe3(generator);
            o -= c;
            d = o;
        }
        else if (correctAnswer == "B")
        {
            b = losowe1(generator);
            o -= b;
            std::uniform_int_distribution<int> losowe2(0, o);
            a = losowe2(generator);
            o -= a;
            std::uniform_int_distribution<int> losowe3(0, o);
            c = losowe3(generator);
            o -= c;
            d = o;
        }
        else if (correctAnswer == "C")
        {
            c = losowe1(generator);
            o -= c;
            std::uniform_int_distribution<int> losowe2(0, o);
            a = losowe2(generator);
            o -= a;
            std::uniform_int_distribution<int> losowe3(0, o);
            b = losowe3(generator);
            o -= b;
            d = o;
        }
        else if (correctAnswer == "D")
        {
            d = losowe1(generator);
            o -= d;
            std::uniform_int_distribution<int> losowe2(0, o);
            a = losowe2(generator);
            o -= a;
            std::uniform_int_distribution<int> losowe3(0, o);
            b = losowe3(generator);
            o -= b;
            c = o;
        }

        // Wy�wietlenie wynik�w
        std::cout << "A: " << a << "%"<< std::endl;
        std::cout << "B: " << b <<"%" << std::endl;
        std::cout << "C: " << c <<"%" << std::endl;
        std::cout << "D: " << d << "%" << std::endl;
        cout << endl;
    }

    
}