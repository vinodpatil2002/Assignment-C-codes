//write a c to read name and marks of n no. of students from user and store in a file

#include <stdio.h>
#include<stdlib.h>
int main()
{

char name[10];
int marks,i,n;
printf("Enter number of students: ");
scanf("%d",&n);
FILE *fp;
fp=(fopen("student.txt","w"));
if(fp==NULL) {
printf("Error");
exit(0);

}
for (i=0;i<n;++i) {
printf("For student%d\nEnter name: ",i+1);
scanf("%s",name);
printf("Enter marks: ");
scanf("%d",&marks);
fprintf(fp,"\nName: %s \nMarks=%d \n",name,marks);
}
fclose(fp);
if((fp=fopen("student.txt","r"))==NULL)
    {
        printf("error");
        exit(0);
    }
while(1) //for(;;)=while(1)
    {
        fscanf(fp,"%s",&name);
        fscanf(fp,"%d",&marks);
        printf("%s\n%d\n",name,marks);
        if(feof(fp))
    break;
         }
fclose(fp);
return 0;
}




