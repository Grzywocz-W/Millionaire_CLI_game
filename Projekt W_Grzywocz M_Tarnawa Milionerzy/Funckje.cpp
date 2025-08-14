
#include "Header.h"


int countQuestions(sqlite3* db) {
    const char* sql = "SELECT COUNT(*) FROM PYTANIA;";
    sqlite3_stmt* stmt;
    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    check(result, db);

    result = sqlite3_step(stmt);
    int count = 0;
    if (result == SQLITE_ROW) {
        count = sqlite3_column_int(stmt, 0);
    }

    sqlite3_finalize(stmt);
    return count;
}

void poprawnosc(Questions tab[])
{
    for (int i = 0; i < 12; i++)
    {
        string w = "Z³a sk³adnia pytania";
        string l1 = tab[i].correctAnswer;
        int u = l1.length();
        if (u != 1)
        {
            throw w;
        }
       
        
    }
}
string litera(int a) // zamienia cyfrê od 1 do 4 na A DO D
{
    string w;
    if (a == 1) {
        w = "A";
    }
    else if (a == 2) {
        w = "B";
    }
    else if (a == 3) {
        w = "C";
    }
    else if (a == 4) {
        w = "D";
    }
    return w;

}


int getConsoleWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    return columns;
}

void coutCentered(const string& text)
{
    int consoleWidth = getConsoleWidth();
    int textLength = text.length();
    int spaces = (consoleWidth - textLength) / 2;
    for (int i = 0; i < spaces; ++i)
    {
        cout << " ";
    }
    cout << text << endl;

}


void setConsoleColor(WORD attributes)                                    //KOLOR T£A I TEKSTU
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, attributes);
}