#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *fp;
    char ch;
    fp= fopen("sample.txt", "w");
    if(fp==NULL)
    {
        printf("Error");
        exit(0);
    }
    printf("Insert some data");
    while((ch = getchar())!= EOF)
    fputc(ch, fp);
    fclose(fp);
    printf("The file contains");
    fp=fopen("sample.txt", "r");
    while((ch = fgetc(fp))!= EOF)
    putchar(ch);
    fclose(fp);
}
