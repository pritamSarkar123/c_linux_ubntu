#include<stdio.h>
int main(){
    int num;
    printf("Enter the number to check the power of 2 or not \n");
    scanf("%d",&num);
    if((num & (num-1))==0) printf("%d is power of 2",num);
    else printf("%d is not power of 2",num);
    return 0;
}