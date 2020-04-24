#include<stdio.h>
#include<stdlib.h>

int main(){
        /*int *p=NULL; //pointing to 0 address
        printf("p= %p *p=%d",p,*p);
        *p=12;
        printf("p= %p *p=%d",p,*p);*/
        int *p; //pointing to any garbage address
        *p=12;
        printf("p= %p *p=%d",p,*p);
}
