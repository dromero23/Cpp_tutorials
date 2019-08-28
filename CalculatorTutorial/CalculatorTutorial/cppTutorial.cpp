// CalculatorTutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Calculator.h"
#include <string>
#include <fstream>
using namespace std;


enum Example
{

	A, B, C
};

void SwitchEx();
void WhileEx();
int log(int number, int base);
//include fstream and string
void FileEx(void);
void FileExercises(void);


int main()
{
	cout << "Switch Example" << endl;
	SwitchEx();
	cout << "Operation "<<log(9, 3) << endl;
	cout << "Loop Example" << endl;
	WhileEx();
	cout << "File Example" << endl;
	FileEx();
	return 0;
}

void FileExercises(void) {
	fstream inpustream;
	inpustream.open("scores.txt");
	int players;
	inpustream >> players;
	for (int i = 0; i < players; i++)
	{
		string name;
		int score;
		inpustream >> name;
		inpustream >> score;
		cout << name << ", " << score << endl;

	}
}
void FileEx(void)
{
	string firstName, lastName;
	int score;
	fstream inputStream;

	inputStream.open("player.txt");

	inputStream >> score;
	inputStream >> firstName >> lastName;
	cout << "First name: " << firstName << " Last name: " << lastName << endl;
	cout << "Score: " << score << endl;
	inputStream.close();

	/*
	good way to check if reading the whole file is the following: 
		while (inputstream>>text) <--- will return false if there's no data left to read 
		{
			w/e it is that you need to do with the data.
		}
	*/
}


void SwitchEx(void)
{
	Example value = B;
	switch (value) {
	case A:
		cout << "Ay!" << endl;
		break;
	case B:
		cout << "bye" << endl;
		break;
	case C:
		cout << "hi" << endl;
		break;
	default:
		cout << "Print" << endl;
		break;
	}
}

void WhileEx(void)
{
	int countdown = 10;
	while (countdown > 0)
	{
		cout << countdown << endl;
		countdown--;
	}
}
int log(int number, int base){
	int log = 0;
	for (int i = 1; i < number; i = i * base)
	{
		log++;
	};
	return log;
}
//int main()
//{
//	double x = 0.0;
//	double y = 0.0;
//	double result = 0.0;
//	char oper = '+';
//	cout << "Calculatore Console Applicaton" << endl << endl;
//	cout << "Please enter the operation to perform. Format: a+b |a-b | a*b| a/b" << endl;
//
//	Calculator c;
//	while (true) {
//		cin >> x >> oper >> y;
//		if (oper == '/' && y == 0) {
//			cout << "Division by 0 exception" << endl;
//			continue;
//		}
//		result = c.Calculate(x, oper, y);
//		cout << "Result is: " << result << endl;
//	}
//
//	return 0;
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
