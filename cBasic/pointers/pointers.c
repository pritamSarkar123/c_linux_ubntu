#include<stdio.h>
int* func1(int a) //returning pointer
{
    int *c=&a;
    *c=(*c)*(*c);
    return c; //c is local to the function, deallocates when the function ends
}
void func2(int *a)
{
    *a= (*a)*(*a);
}
int* func3(int *a)
{
    int *c=a;
    *c=(*c)*(*c);
    return c; //c is local to the function, deallocates when the function ends
    
}
int main()
{
    /*int a=5;
    int *b=func1(a);//call by value
    a=*b;
    printf("%d",a);  */ //may be the pointed address is accessed and allocated by some other variable or function,
    //as stack memory removed automatically 
    
    /*int a=5;
    func2(&a);
    printf("%d",a);*/
    
    int a=5;
    int *b=func3(&a);
    printf("%d",*b);  //may be the pointed address is accessed and allocated by some other variable or function,
    //as stack memory removed automatically 
    
    
    return 0;
}
