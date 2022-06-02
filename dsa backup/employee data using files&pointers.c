
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct employee
 {
   int id;
   char name[20];
};
int main () {
   FILE *of;
   of= fopen ("employee.txt", "w");
   if (of == NULL)
        {
      fprintf(stderr, "\nError to open the file\n");
      exit (1);
   }
   struct employee inp1 = {1, "xxx"};
   struct employee inp2 = {2, "yyy"};
   fwrite (&inp1, sizeof(struct employee), 1, of);
   fwrite (&inp2, sizeof(struct employee), 1, of);
   if(fwrite != 0)
      printf("Contents to file is ready !\n");
   else
      printf("Error writing file !\n");
   fclose (of);
   FILE *inf;
   struct employee inp;
   inf = fopen ("employee.txt", "r");
   if (inf == NULL) {
      fprintf(stderr, "\nError to open the file\n");
      exit (1);
   }
   while(fread(&inp, sizeof(struct employee), 1, inf))
      printf ("id = %d name = %s\n", inp.id, inp.name);
   fclose (inf);
}
