#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *fp;
    char name[50];
    int marks, i, num;
    fp= fopen("student_data_with_files.txt", "w");
    if(fp==NULL)
    {
        printf("Error");
        exit(0);
    }
    printf("Enter the number of students\t");
    scanf("%d", &num);
    for(i=0; i<num; i++)
    {
        printf("For student %d\n Enter name:", i+1);
        scanf("%s", name);
        printf("Enter marks:");
        scanf("%d", &marks);
        fprintf(fp, "%s\n%d\n", name, marks);
    }
    fclose(fp);
    if((fp=fopen("student_data_with_files.txt", "r"))==NULL)
    {
        printf("Error");
        exit(1);
    }
for(;;)
{
    fscanf(fp, "%s", name);
    fscanf(fp, "%d", &marks);
    printf("%s\n%d\n", name, marks);
    if(feof(fp))
    break;
}
fclose(fp);
}
