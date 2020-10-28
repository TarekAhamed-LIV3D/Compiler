#include <iostream>
#include <cstring>
using namespace std;

void splitting(){
    char str[100];
    char String[10][10];
    int x,y,z;
    cout << " Input  a string : ";
    fgets(str, sizeof str, stdin);
    y = 0; z = 0;
    for(x = 0;x <=(strlen(str)); x++)
    {
        if(str[x] == ' '||str[x] == '\0')
        {
            String[z][y] = '\0';
            z++;
            y = 0;
        }
        else
        {
            String[z][y] = str[x];
            y++;
        }
    }
    for(x = 0;x < z; x++)
        cout<<"\n"<<String[x];
}
int main()
{
    splitting();
}
