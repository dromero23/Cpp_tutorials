#include "dayofyear.h"
#include <iostream>
using namespace std;
int main()
{
    DayOfYear today, birthday;
    cout <<"Enter today's date: \n";
    cout <<"Enter month as a number: ";
    cin >> today.month;
    cout <<"Enter day as a number: ";
    cin >> today.day;
    cout <<"Enter your birthday: \n";
    cout <<"Enter month as a number: ";
    cin >> birthday.month;
    cout <<"Enter day as a number: ";
    cin >> birthday.day;
    cout << "Today's date is ";
    today.output();
    cout <<endl;
    
    if (birthday.isBirthday(today))
        cout <<"Happy Birthday!\n";
    else 
        cout <<"Not your birthday!\n";
    return 0;
}