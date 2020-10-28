#include <iostream>
#include <cstring>
int main()
{
   char name[50];
   int marks, i, num;

   printf("Enter number of students: ");
   scanf("%d", &num);

   FILE *fptr;
   fptr = (fopen("student.txt", "a"));
   if(fptr == NULL)
   {
       printf("Error!");
       exit(1);
   }

   for(i = 0; i < num; ++i)
   {
      printf("For student%d\nEnter name: ", i+1);
      scanf("%s", name);

      printf("Enter marks: ");
      scanf("%d", &marks);

      fprintf(fptr,"\nName: %s \nMarks: %d \n", name, marks);
   }

    FILE *fp;
   fclose(fptr) ;
    char data[100] ;
         printf( "Opening the file test.txt in read mode" ) ;
         fp = fopen( "student.txt", "r" ) ;
         if ( fp == NULL )
         {
                 printf( "Could not open file student.txt" ) ;
                 return 1;
         }
         printf( "Reading the file student.txt\n" ) ;
         while( fgets ( data, 50, fp ) != NULL )
            printf( "%s" , data ) ;
            printf("\n");
         printf("Closing the file student.txt") ;
         fclose(fp) ;
         return 0;
}
