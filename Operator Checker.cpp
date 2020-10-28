#include <iostream>
#include <cstring>
#include <typeindex>
int main(){
    int i,l;
    cout << ("Lets");
    char c,str[100];
    puts("Enter the string and type $ to stop");
    while((c=getchar()) != '$')
        str[i++] = c;
        str[i] = '\0';
        i = 0;
    while(str[i] != '\0')
    {
        if(!isalpha(str[i]) && !isdigit(str[i]))
        switch(str[i])
        {
        case '+':
            if(str[i] == '+' && str[i+1] != '=' && str[i+1] != '+')
                puts("Plus Operator +");
            else if(str[i+1] == '=')
            {
              puts("Assignment Operator =");
              i++;
            }
            else if(str[i+1] == '+')
            {
              puts("Increment Operator ++");
              i++;
            }
            break;
        case '-':
            if(str[i] == '-' && str[i+1] != '=' && str[i+1] != '-')
                puts("Minus Operator -");
            else if(str[i+1] == '=')
            {
              puts("Assignment Operator -=");
              i++;
            }
            else if(str[i+1] == '-')
            {
              puts("Decrement Operator --");
              i++;
            }
            break;
        case '*':
            if(str[i] == '*' && str[i+1] != '=')
                puts("Multiply Operator *");
            else if(str[i+1] == '=')
            {
              puts("Assignment Operator *=");
              i++;
            }
            break;
        case '/':
            if(str[i] == '/' && str[i+1] != '=')
                puts("Devided Operator /");
            else if(str[i+1] == '=')
            {
              puts("Assignment Operator /=");
              i++;
            }
            break;
        case '%':
            if(str[i] == '%' && str[i+1] != '=')
                puts("Arithmetic Operator %");
            else if(str[i+1] == '=')
            {
              puts("Assignment Operator %=");
              i++;
            }
            break;
        case '^':
            if(str[i] == '^' && str[i+1] != '=')
                puts("Arithmetic Operator ^");
            else if(str[i+1] == '=')
            {
              puts("Assignment Operator ^=");
              i++;
            }
            break;
        case '|':
            if(str[i] == '|' && str[i+1] != '=' && str[i+1] != '!')
                puts("Bitwise Or Operator !");
            else if(str[i+1] == '=')
            {
              puts("Assignment Operator |=");
              i++;
            }
            else if(str[i+1] == '!')
            {
              puts("Logical Or Operator ||");
              i++;
            }
            break;
        case '<':
            if(str[i] == '<' && str[i+1] != '=' && str[i+1] != '<')
                puts("Less than Operator <");
            else if(str[i+1] == '=')
            {
              puts("Less than or equal Operator <=");
              i++;
            }
            else if(str[i+1] == '<')
            {
              puts("Left shift  Operator <<");
              i++;
            }
            break;
        case '>':
            if(str[i] == '>' && str[i+1] != '=' && str[i+1] != '>')
                puts("Greater than Operator >");
            else if(str[i+1] == '=')
            {
              puts("Greater than or equal Operator <=");
              i++;
            }
            else if(str[i+1] == '>')
            {
              puts("Right shift  Operator >>");
              i++;
            }
            break;
        case '&':
            if(str[i] == '&' && str[i+1] != '=' && str[i+1] != '&')
                puts("Bitwise And Operator &");
            else if(str[i+1] == '=')
            {
              puts("Assignment Operator ^=");
              i++;
            }
            else if(str[i+1] == '&')
            {
              puts("Logical And Operator &&");
              i++;
            }
            break;
        case '!':
            if(str[i] == '!' && str[i+1] != '=')
                puts("Logical Not Operator !");
            else if(str[i+1] == '=')
            {
              puts("Not Equal to Operator !=");
              i++;
            }
            break;
        case '=':
            if(str[i] == '=' && str[i+1] != '=')
                puts("Assignment Operator !");
            else if(str[i+1] == '=')
            {
              puts("Equal to Operator ==");
              i++;
            }
            break;
        }
        i++;
    }
}
