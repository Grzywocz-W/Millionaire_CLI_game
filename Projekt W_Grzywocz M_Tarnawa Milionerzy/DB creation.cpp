#include "Header.h"

void createTable(sqlite3* db)
{
	const char* sqlCreateTable =                      //tworzenie tabeli w bazie
		"CREATE TABLE IF NOT EXISTS PYTANIA ("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
		"QUESTION TEXT NOT NULL, "
		"ANSWER1 TEXT NOT NULL, "
		"ANSWER2 TEXT NOT NULL, "
		"ANSWER3 TEXT NOT NULL, "
		"ANSWER4 TEXT NOT NULL, "
		"CORRECT_ANSWER TEXT NOT NULL);";

	int creation_result = sqlite3_exec(db, sqlCreateTable, nullptr, nullptr, nullptr);        //wykonanie zapytania
	check(creation_result, db);                                             //sprawdzenie czy wykonano poprawnie
}


void check(int result, sqlite3* db)             //funkcja sprawdzajaca poprawnosc dzia³ania zapytania do bazy danych
{
	if (result != SQLITE_OK)
	{
		cerr << "Wyst¹pi³ b³¹d " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
		exit(1);
	}
}