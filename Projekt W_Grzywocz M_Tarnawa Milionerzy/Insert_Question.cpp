#include "Header.h"

void InsertQuestion(sqlite3* db)
{
	int number_of_q;
	cout << "Ile pytañ chcesz dodaæ? " << endl;
	cin >> number_of_q;
	for (int i = 1; i <= number_of_q; i++)
	{
		string k;
		string question, answer1, answer2, answer3, answer4, correctAnswer;
		cout << "Podaj pytanie: " << endl;
		cin.ignore();
		getline(cin,question);
		cout << "Podaj odpowiedz a: " << endl;
		getline(cin,answer1);
		cout << "Podaj odpowiedz b: " << endl;
		getline(cin,answer2);
		cout << "Podaj odpowiedz c: " << endl;
		getline(cin,answer3);
		cout << "Podaj odpowiedz d: " << endl;
		getline(cin,answer4);
		while (k != "A" && k != "B" && k != "C" && k != "D") {
			cout << "Podaj poprawn¹ odpowiedz: ";
			getline(cin, k);
		}
		correctAnswer = k;
		
		const char* sql = sqlite3_mprintf("INSERT INTO PYTANIA (QUESTION, ANSWER1, ANSWER2, ANSWER3, ANSWER4, CORRECT_ANSWER)" "VALUES ('%q', '%q', '%q', '%q', '%q', '%q');", question.c_str(), answer1.c_str(), answer2.c_str(), answer3.c_str(), answer4.c_str(), correctAnswer.c_str());
		int result = sqlite3_exec(db, sql, nullptr, nullptr, nullptr);
		check(result, db);
	}

}

void DeleteQuestion(sqlite3* db, int id) 
{
	const char* sql = sqlite3_mprintf("DELETE FROM PYTANIA WHERE ID = %d;", id);
	int result = sqlite3_exec(db, sql, nullptr, nullptr, nullptr);
	check(result, db);
	
}