#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *fp;
    char ch;
    fp= fopen("student_data.txt", "w");
    if(fp==NULL)
    {
        printf("Error");
        exit(0);
    }
    printf("Insert student name\t");
    while((ch = getchar())!= EOF)
    fputc(ch, fp);
    printf("Enter student roll no\t");
    while((ch= getchar())!=EOF)
    fputc(ch, fp);
    fclose(fp);
    printf("The file contains");
    fp=fopen("student_data.txt", "r");
    while((ch = fgetc(fp))!= EOF)
    putchar(ch);
    fclose(fp);
}
