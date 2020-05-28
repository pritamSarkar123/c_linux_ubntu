#include<stdio.h>
int main(){
    int num,rep;
    printf("Enter the number to count its no of ones\n");
    scanf("%d",&num);
    rep=num;
    int count=0;
    while (num){
        count++;
        num=num & (num-1);
    }
    printf("No of one in %d is %d",rep,count);
    return 0;
}