#include<stdio.h>
int add(int a,int b)
{
    int c=a+b;
    return c;
}
void func1(int *c,int (*f)(int d,int e))
{
    *c = *c + f; //callback
}
int main()
{
    void (*p)(int*,int (*f)(int,int));
    p=&func1; //p=func1;
    int (*q)(int,int);
    q=&add;//q=add;
    int a=5;
    p(&a,q(4,5));//p(&a,add(4,5));
    printf("%d",a);
    return 0;
}
