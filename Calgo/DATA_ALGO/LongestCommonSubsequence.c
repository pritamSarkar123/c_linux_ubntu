#include<stdio.h>
#include<string.h>
int max(int a,int b){
    return (a>b)? a : b;
}
int main(){
    char *A="stone";
    char *B="one";
    int i=0,j=0;
    int L[10][10];
    for(i=0;i<=strlen(A);i++){
        for(j=0;j<=strlen(B);j++){
            if(i==0 || j==0){
                L[i][j]=0;
            }
            else if(A[i-1]!=B[j-1]){
                L[i][j]=max(L[i-1][j],L[i][j-1]);
            }
            else{
                printf("%c",A[i-1]);
                L[i][j]=1+L[i-1][j-1];
            }
        }
            
    }
    printf("\n max len %d ",L[i-1][j-1]);
    return 0;
}
