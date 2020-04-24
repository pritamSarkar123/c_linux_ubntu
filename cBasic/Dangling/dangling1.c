#include<stdio.h>
#include<stdlib.h>
int p;
void func(){
        int *p=(int *)calloc(15,sizeof(int));
        int i;
        for(i=0;i<15;i++){
                *(p+i)=i+1;
        }
        
        printf("Before free ! \n");
        for(i=0;i<15;i++){
                printf("%d ",*(p+i));
        }
        printf("\n");
        free(p);
        printf("After free ! \n");
        for(i=0;i<15;i++){ // dealocated but still pointing
                printf("%d ",*(p+i));
        }
        
}
int *func1(){
        //int p=5; //segmentation error
        //static int p=5;
        p=5; //global can be used out of the program
        return &p;
}
void func2(){
        int *q;
        {
                int c=5;
                q=&c;
                printf("*q=%d c=%d",*q,c);
                
        }
        printf("*q=%d c dallocated",*q); //still pointing to the position after dalocation of c
}
int main(){
       //func(); 
       /*int *p;
       p=func1();
       printf("%d ",*p);*/
       func2();
}
