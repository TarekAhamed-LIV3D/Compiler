#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char str[100];
    cout<<"Input your string:- ";
    cin>>str;
    char* token = strtok(str, "-");
    while (token != NULL) {
        cout << "\n" << token;
        token = strtok(NULL, "-");
    }
    cout << "\n";
}
