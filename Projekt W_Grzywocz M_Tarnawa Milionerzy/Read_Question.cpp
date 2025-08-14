#include "Header.h"

Questions readQuestionByID(sqlite3* db, int id, Questions &row)
{
	const char* sql = "SELECT QUESTION, ANSWER1, ANSWER2, ANSWER3, ANSWER4, CORRECT_ANSWER FROM PYTANIA WHERE ID = ?;";        //zapytanie do bazy z niewiadom¹
	sqlite3_stmt* stmt;
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
	check(result, db);                                                                 //sprawdzenia czy utworzono poprawnie
	sqlite3_bind_int(stmt, 1, id);                                                     //przypisanie inta do ID z zapytania
	result = sqlite3_step(stmt);
	if (result == SQLITE_ROW)                                                          //odczytanie kolejnych kolumn z rekordu
	{
		const unsigned char *question = sqlite3_column_text(stmt, 0);
		const unsigned char *answ1 = sqlite3_column_text(stmt, 1);
		const unsigned char *answ2 = sqlite3_column_text(stmt, 2);
		const unsigned char *answ3 = sqlite3_column_text(stmt, 3);
		const unsigned char *answ4 = sqlite3_column_text(stmt, 4);
		const unsigned char *corransw = sqlite3_column_text(stmt, 5);
	
		row.question= string(reinterpret_cast<const char*>(question));
		row.answer1= string(reinterpret_cast<const char*>(answ1));
		row.answer2 = string(reinterpret_cast<const char*>(answ2));
		row.answer3 = string(reinterpret_cast<const char*>(answ3));
		row.answer4 = string(reinterpret_cast<const char*>(answ4));
		row.correctAnswer = string(reinterpret_cast<const char*>(corransw));

	}
	else
	{
		cerr << "Nie ma takiego ID " << id << endl;
	}
	result = sqlite3_finalize(stmt);
	check(result, db);

	return row;
}