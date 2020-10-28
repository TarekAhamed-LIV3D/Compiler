#include <iostream>
#include <cstring>
#define maxinput 100
using namespace std;

int main(){
    char input[maxinput] = "";
    int length,i;
    cout << "Enter a string:- ";
    cin >> input;
    length = strlen (input);
    cout << "\n";
    for (i=0;i<length; i++)
        if (!isdigit(input[i]))
        {
            cout << "Entered input is not a number \n";
            exit(1);
        }
    cout << "Entered input is a number \n";

}
