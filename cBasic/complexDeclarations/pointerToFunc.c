#include<stdio.h>
#include<stdlib.h>
void print(){
        printf("hello world \n");
}
int *add(int *a,int *b,void (*l)()){
        static int c;
        c=(*a)+(*b);
        l(); //callback
        return &c;
}
int main(){
        int *(*p)(int *,int *,void (*l)()); //pointer to a function
        p=&add;//referencing to the function
        int a=2,b=3;
        int *q=(*p)(&a,&b,print);
        printf("%d",*q);
        return 0;
}
