#include<stdio.h>
int main(){
    int toNum,byNum;
    printf("Enter the number to mod\n");
    scanf("%d",&toNum);
    printf("Enter the 2's power by which mod will be done\n");
    scanf("%d",&byNum);
    int mod= toNum & (byNum-1);
    printf("mod id %d",mod);
    return 0;
}