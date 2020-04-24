#include<stdio.h>
int main(int argc,char **argv) //(int argc,char *argv[])
//argv[i]="XXXX" //store as string literals //argc=1 <<--program name
{
    int i;
    for(i=0;i<argc;i++)
    {
        printf("%c\n",argv[i][0]);
    }
    return 0;
}
