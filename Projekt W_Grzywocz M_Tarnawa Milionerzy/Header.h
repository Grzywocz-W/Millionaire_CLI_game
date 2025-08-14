#pragma once

#include<iostream>
#include<locale.h>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<sqlite3.h>
#include<windows.h>    // Nag³ówek do obs³ugi kolorów w konsoli
#include<locale>       // Nag³ówek do obs³ugi std::locale
#include<stdexcept>
#include <limits>
#include <iomanip>     // Nag³ówek do obs³ugi setw, fixed, setprecision
#include <random>
#include <ctime>
#include<cctype>
#include <chrono>
#include <thread>//do uspania
using namespace std;


void createTable(sqlite3* db);
void check(int result, sqlite3* db);
void InsertQuestion(sqlite3* db);
int countQuestions(sqlite3* db);
void drawing(int n, bool logic[], int wylosowane[]);
void stawki();
void kola(bool kolo1, bool kolo2, bool kolo3);
void przeliczanie();
void wygrana(bool war1, int b);
void beginning();
void DeleteQuestion(sqlite3* db, int id);
int getConsoleWidth();
void coutCentered(const string& text);
void setConsoleColor(WORD attributes);
//void poprawnosc(Questions tab[]);

class Questions
{
public:
	string question;
	string answer1;
	string answer2;
	string answer3;
	string answer4;
	string correctAnswer;

	Questions(){}
	Questions(const string& q, const string& a1, const string& a2, const string& a3, const string& a4, const string& ca)
	{
		question = q;
		answer1 = a1;
		answer2 = a2;
		answer3 = a3;
		answer4 = a4;
		correctAnswer = ca;
	}
	friend Questions readQuestionByID(sqlite3* db, int id, Questions& row);
	friend void poprawnosc(Questions tab[]);
	void wyswietl(int k);
	void przyjaciel(bool warunek);
	void ekspert(bool warunek);
	void pub(bool warunek);

	virtual ~Questions(){}
};


extern int maks;
extern int numer_pytania;
extern int poprawne_odp;
extern Questions pomocnicze;
extern char odp;
extern string ans;
extern bool war1;
extern bool kolo1;
extern bool kolo2;
extern bool kolo3;
string litera(int a);
extern WORD backgroundColor;
extern WORD textColor;

