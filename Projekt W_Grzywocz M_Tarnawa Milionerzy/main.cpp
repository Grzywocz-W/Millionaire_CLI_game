#include "Header.h"

int main()
{

    
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "pl_PL");  // ustawienie polskich znaków 
    backgroundColor = BACKGROUND_BLUE;
    textColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    setConsoleColor(backgroundColor | textColor);
    sqlite3* db;
    int result;
    
    

    result = sqlite3_open("Milionerzy-pytania Baza danych", &db); // otwieranie bazy danych lub utworzenie
    check(result, db);
    sqlite3_exec(db, "PRAGMA encoding = 'UTF-8';", nullptr, nullptr, nullptr);
    cout << "Po³¹czono z baz¹ danych pytañ!" << endl;

    createTable(db); // tworzenie tabeli w bazie danych jeœli nie istnieje

    //cout << countQuestions(db);
    while (ans != "GRAJ" && ans!= "graj")
    {
        system("cls");
        cout << "Po³¹czono z baz¹ danych pytañ!" << endl;
        beginning();
        getline(cin, ans);
        if (ans == "DODAJ PYTANIE" || ans== "dodaj pytanie")
        {
            InsertQuestion(db);
            cout << "Dodano pytanie/a " << endl;
        }
        if (ans == "USUN PYTANIE" || ans== "usun pytanie")
        {
            int id = 0;
            cout << "Podaj numer rekordu do usuniecia";
            cin >> id;
            DeleteQuestion(db, id);
            cout << "Usuniêto pytanie/a " << endl;
        }
    }
    system("cls");
    int war_pocz¹tkowy = countQuestions(db);
    if (war_pocz¹tkowy >= 12)
    {
        cout << "Witaj w grze Milionerzy" << endl
            << "Przed tob¹ 12 pytañ, i 4 odpowiedzi dla ka¿dego, lecz tylko jedna odpowiedŸ jest poprawna" << endl
            << "Naciœnij ENTER by kontynuowaæ";
        

        getline(cin, ans); // Ignoruj wszystko do nowej linii
        system("cls");

        bool* logic = new bool[war_pocz¹tkowy+1];
        for (int i = 0; i < war_pocz¹tkowy+1; ++i) {
            logic[i] = false;
        }

        int wylosowane[12]{};
        
        drawing(war_pocz¹tkowy,logic,wylosowane);
        /*for (int j = 0; j < 12; j++)
        {
            cout << wylosowane[j] << endl;
        }*/

        Questions p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12;

        readQuestionByID(db, wylosowane[0], p1);
        readQuestionByID(db, wylosowane[1], p2);
        readQuestionByID(db, wylosowane[2], p3);
        readQuestionByID(db, wylosowane[3], p4);
        readQuestionByID(db, wylosowane[4], p5);
        readQuestionByID(db, wylosowane[5], p6);
        readQuestionByID(db, wylosowane[6], p7);
        readQuestionByID(db, wylosowane[7], p8);
        readQuestionByID(db, wylosowane[8], p9);
        readQuestionByID(db, wylosowane[9], p10);
        readQuestionByID(db, wylosowane[10], p11);
        readQuestionByID(db, wylosowane[11], p12);

        Questions tab[12] = { p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12 };
        string Exception;

        try {
            poprawnosc(tab);
        }
        catch (string w)
        {
            cout << "Niepoprawna sk³adnia odpowiedzi na pytanie w bazie danych!!! ";
            this_thread::sleep_for(chrono::seconds(15));
            numer_pytania = 234;
        }



        cout << "Masz do dyspozycji trzy ko³a ratunkowe " << endl << "Telefon do przyjaciela, gdzie dzwonisz do kolegi, który pomaga Ci w pytaniu," << endl << "telefon do eksperta, który odrzuca dwie niepoprawne odpowiedzi" << endl << "oraz pytanie do publicznoœci" << endl;
        cout << endl << "Pamiêtaj, ¿e ka¿dego ko³a mo¿esz u¿yæ tylko raz";
        cout << endl << "Na ka¿de pytanie musisz odpowiedzieæ A B C lub D";
        cout << endl << "Aby siê wycofaæ wpisz K i zgarnij sumê pieniêdzy z poprzedniego pytania" << endl << "Aby skorzystaæ z telefonu do przyjaciela wpisz T,";
        cout << endl << "Aby zapytaæ eksperta E,";
        cout << endl << "Natomiast aby zapytaæ publicznoœæ wpisz P";
        cout << endl << endl << "JAKO ODPOWIEDZI WPISUJ WIELKIE LITERY    [ENTER]";



        getline(cin, ans);
        system("cls");
        stawki();
        getline(cin, ans);
        system("cls");


        cout << "A wiêc zaczynamy...[ENTER]";
        getline(cin, ans);
        system("cls");
        
        
        while (numer_pytania < 12)
        {

            //cout << ans;
            
            tab[numer_pytania].wyswietl(numer_pytania);
            kola(kolo1, kolo2,kolo3);
            getline(cin, ans);
            //kola(kolo1, kolo2,kolo3);
            
    
            //cin.ignore(ans.length(), '\n');
            system("cls");
            ans = ans[0];
            char ansAlternative = ans[0];
            ansAlternative = toupper(ansAlternative);
            char correctAlternative = tab[numer_pytania].correctAnswer[0];
          
            if (tab[numer_pytania].correctAnswer == ans || correctAlternative == ansAlternative)
            {
                numer_pytania += 1;
                poprawne_odp += 1;
                cout << "To poprawna odpowiedŸ" << endl;
                cout << "Przechodzimy do kolejnej rundy" << endl;
                //this_thread::sleep_for(chrono::seconds(5));
                system("cls");
                war1 = 1;
            }
            else if (ans != "A" && ans != "B" && ans != "C" && ans != "D" && ans != "K" && ans != "P" && ans != "E" && ans != "T" && ans != "a" && ans != "b" && ans != "c" && ans != "d" && ans != "k" && ans != "p" && ans != "e" && ans != "t")
            {
                system("cls");
            }
            else if (ans == "K" || ans=="k")// zakoñczenie gry
            {
                cout << "Dziêkujê za grê, zgarniasz kwotê dla poprzedniego pytania" << endl;
                this_thread::sleep_for(chrono::seconds(5));
                war1 = 1;
                break;
            }
            else if (ans == "P" || ans=="p") { //publicznoœæ

                system("cls");
                tab[numer_pytania].pub(kolo3);
                kolo3 = 0;


            }
            else if (ans == "T" || ans=="t") {//telefon do przyjaciela

                system("cls");
                tab[numer_pytania].przyjaciel(kolo1);
                kolo1 = 0;
               

            }
            else if (ans == "E"|| ans=="e") {// pytanie do eksperta

                system("cls");
                tab[numer_pytania].ekspert(kolo2);
                kolo2 = 0;

            }
            else {
                backgroundColor = BACKGROUND_BLUE;
                textColor = FOREGROUND_RED;
                setConsoleColor(backgroundColor | textColor);
                cout << endl << "To niestety z³a odpowiedŸ. Poprawna to: " << tab[numer_pytania].correctAnswer << endl;
                setConsoleColor(FOREGROUND_RED|FOREGROUND_GREEN | FOREGROUND_BLUE);
                war1 = 0;// war1 =0 oznacza, ¿e Ÿle odpowiedzieliœmy, wiêc funkcja wygrana zadzia³a inaczej(da nam próg gwarantowany, a nie z ostatniego pytania)
                this_thread::sleep_for(chrono::seconds(3));
                break;
            }  
        }


        przeliczanie();
        wygrana(war1, poprawne_odp);
    }



   

    {//{InsertQuestion(db);
    //cout << "Dodano pytania " << endl; }
    }
    
    Questions row; // wiersz do tabeli z 12 pytaniami
    {//string table[12][6];
    //for (int i = 0; i < 12; i++)
    //{
    //    cout << "Podaj ID rekordu do odczytania: " << endl; // COUT DO WYRZUCENIA, A CIN DO ZAST¥PIENIA F.LOSUJ¥C¥ LICZBÊ I ZWRACAJ¥C¥ INTA, zwrócony int przypisany do zmiennej id!!!!
    //    cin >> id;
    //    readQuestionByID(db, id, row);
    //    table[i][0] = row.question;
    //    table[i][1] = row.answer1;
    //    table[i][2] = row.answer2;
    //    table[i][3] = row.answer3;
    //    table[i][4] = row.answer4;
    //    table[i][5] = row.correctAnswer;
    //    cout << row.question;
    //} // pytania wczytane do tabeli stringów która imituje baze danych
    }

    

    
     //cout <<  countQuestions(db);

    //readQuestionByID(db, 1, row);
    //cout << row.question;
    sqlite3_close(db);
    return 0;
}
