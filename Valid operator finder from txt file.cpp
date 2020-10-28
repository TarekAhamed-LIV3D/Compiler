#include <iostream>
#include <cstring>
#include <typeindex>
FILE *fp;

bool isValidScope(char ch) {
   if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ',' || ch == ';' || ch == '>' || ch == '<' || ch == '=' || ch == '(' || ch == ')' ||ch == '[' || ch == ']' || ch == '{' || ch == '}')
   return (true);
   return (false);
}
bool isValidOperator(char ch){
   if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '>' || ch == '<' || ch == '=')
   return (true);
   return (false);
}
bool isvalidIdentifier(char* str){
   if (str[0] == '0' || str[0] == '1' || str[0] == '2' || str[0] == '3' || str[0] == '4' || str[0] == '5' || str[0] == '6' || str[0] == '7' || str[0] == '8' || str[0] == '9' || isValidScope(str[0]) == true)
   return (false);
   return (true);
}
bool isValidKeyword(char* str) {
   if (!strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "while") || !strcmp(str, "do") || !strcmp(str, "break") || !strcmp(str, "continue") || !strcmp(str, "int") || !strcmp(str, "double") || !strcmp(str, "float") || !strcmp(str, "return") || !strcmp(str, "char") || !strcmp(str, "case") || !strcmp(str, "char") || !strcmp(str, "sizeof") || !strcmp(str, "long") || !strcmp(str, "short") || !strcmp(str, "typedef") || !strcmp(str, "switch") || !strcmp(str, "unsigned") || !strcmp(str, "void") || !strcmp(str, "static") || !strcmp(str, "struct") || !strcmp(str, "goto"))
   return (true);
   return (false);
}
bool isValidInteger(char* str) {
   int i, len = strlen(str);
   if (len == 0)
   return (false);
   for (i = 0; i < len; i++) {
      if (str[i] != '0' && str[i] != '1' && str[i] != '2'&& str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' || (str[i] == '-' && i > 0))
      return (false);
   }
   return (true);
}
bool isRealNumber(char* str) {
   int i, len = strlen(str);
   bool hasDecimal = false;
   if (len == 0)
   return (false);
   for (i = 0; i < len; i++) {
      if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '.' || (str[i] == '-' && i > 0))
      return (false);
      if (str[i] == '.')
      hasDecimal = true;
   }
   return (hasDecimal);
}
char* subString(char* str, int left, int right) {
   int i;
   char* subStr = (char*)malloc( sizeof(char) * (right - left + 2));
   for (i = left; i <= right; i++)
   subStr[i - left] = str[i];
   subStr[right - left + 1] = '\0';
   return (subStr);
}
void detectTokens(char* str) {
   fp = fopen("assignment.txt", "a");
   if(fp == NULL)
   {
       printf("Error!");
       exit(1);
   }
   int left = 0, right = 0;
   int length = strlen(str);
   while (right <= length && left <= right) {
      if (isValidScope(str[right]) == false)
      right++;
      if (isValidScope(str[right]) == true && left == right) {
         if (isValidOperator(str[right]) == true)
         fprintf(fp,"Valid operator : '%c'\n", str[right]);
         right++;
         left = right;
      } else if (isValidScope(str[right]) == true && left != right || (right == length && left != right)) {
         char* subStr = subString(str, left, right - 1);
         if (isValidKeyword(subStr) == true)
         fprintf(fp,"Valid keyword : '%s'\n", subStr);
         else if (isValidInteger(subStr) == true)
         fprintf(fp,"Valid Integer : '%s'\n", subStr);
         else if (isRealNumber(subStr) == true)
         fprintf(fp,"Real Number : '%s'\n", subStr);
         else if (isvalidIdentifier(subStr) == true
         && isValidScope(str[right - 1]) == false)
         fprintf(fp,"Valid Identifier : '%s'\n", subStr);
         else if (isvalidIdentifier(subStr) == false
         && isValidScope(str[right - 1]) == false)
         fprintf(fp,"Invalid Identifier : '%s'\n", subStr);
         left = right;
      }
   }
   fclose(fp);
   return;
}
int main(){
         char str[100] ;
         char str2[100];
         fp = fopen( "input.txt", "r" );
         if ( fp == NULL )
         {
                 printf( "Could not open file input.txt" );
                 return 1;
         }
         fgets ( str, 100, fp );
         fclose(fp) ;
         detectTokens(str);

         fp = fopen( "assignment.txt", "r" );
         if ( fp == NULL )
         {
                 printf( "Could not open file assignment.txt" );
                 return 1;
         }
         while( fgets ( str2, 50, fp ) != NULL )
            printf( "%s" , str2 ) ;
         fclose(fp) ;
   return (0);
}
