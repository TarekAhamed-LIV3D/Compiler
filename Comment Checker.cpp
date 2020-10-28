#include <iostream>
#include <cstring>
#define max 100
using namespace std;

int main ()
{
    int a,b;
    char ar[max];
    char str[2];
    cout << "Enter your information: ";
    cin >> ar;
    strncpy(str,ar,2);
    if ((a=strncmp(str,"//",2))  && (b=strncmp(str,"/*",2)))
        cout << "Not a Comment";
    else
        cout << "It's a Comment";
}
