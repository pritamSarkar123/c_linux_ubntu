#include<stdio.h>
void oneDarrayPointer(int (*A)) //(int A[])
//(int *A) <<--- Allowed ***
{
    //int B[]=&A; <<--not allowed
    //
    int *B=A; //&A
    int i=0;
    printf("%d",*(B+i));
    printf("\n sizeof B =%ld \n",sizeof(B)); 
}
void twoDarrayPointer(int (*A)[3]) //(int A[][3])
//(int *A[3]) not allowed
{
    //int *B[3]=A; <<--not allowed
    //int **B=A; <<--not reliable for 2d case as Row or Column major differs
    //int B[][3]=A; <<--error
    
    //int A[2][3]={{1,2,3},{4,5,6}};
    int (*B)[3]=A; //&A
    printf("%d",B[1][1]);
    printf("\n sizeof B =%ld \n",sizeof(B));
}
void threeDarrayPointer(int (*A)[3][4]) //(int (*A)[3][4]) //(int A[][3][4])
//*A[3][4] not allowed
{
    /*int A[2][3][4]={ 
                        { {1,2,3,4},
                          {5,6,7,8},
                          {9,10,11,12} 
                        },
                        { {17,18,19,20},
                          {21,22,23,24},
                          {25,26,27,28}
                        }
                   }; */
    int (*B)[3][4]=A;
    printf("%d",B[1][1][1]);
    printf("\n sizeof B =%ld \n",sizeof(B));
}
void pointerToAnEntireArray()
{
    int A[5]={1,2,3,4,5};
    int *B=A;
    int (*C)[5]=A;
    //C pointer to an array, where each element pointing to each element of A
    printf("\n sizeof B =%ld C=%ld C[5]=%ld\n",sizeof(B),sizeof(C),sizeof(C[5]));
}
int main()
{
    int A[3]={1,2,3};
    oneDarrayPointer(A);
    //int A[2][3]={{1,2,3},{4,5,6}};
    //twoDarrayPointer(A);
    /*int A[2][3][4]={ 
                        { {1,2,3,4},
                          {5,6,7,8},
                          {9,10,11,12} 
                        },
                        { {17,18,19,20},
                          {21,22,23,24},
                          {25,26,27,28}
                        }
                   }; */
    //threeDarrayPointer(A);
    //pointerToAnEntireArray();   
}
