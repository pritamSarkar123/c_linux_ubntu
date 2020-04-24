#include <stdio.h>
#define MAX_SIZE 1000
typedef struct node{
    unsigned long long int key;
    unsigned long long int value;
    
}node;
node cache[MAX_SIZE];
int counter=0;
unsigned long long int cacheValue(unsigned long long int n){
    unsigned long long int value,i;
    for(i=0;i<MAX_SIZE;i++){
        if(cache[i].key==n) return cache[i].value;
    }
}
unsigned long long int valueInCache(unsigned long long int n){
    unsigned long long int value,i;
    for(i=0;i<MAX_SIZE;i++){
        if(cache[i].key==n) return 1;
    }
    return 0;
}
unsigned long long int fibonacchi(unsigned long long int n){
    unsigned long long int value;
    if(valueInCache(n)){
        return cacheValue(n);
    }
    if(n==0){
        value=0;
    }
    else if(n==1){
        value=1;
    }
    else{
        value=fibonacchi(n-1)+fibonacchi(n-2);
    }
    cache[counter].key=n;
    cache[counter++].value=value;
    return value;
}
int main()
{
    int i;
    for(i=1;i<=100;i++){
        printf("%llu\n",fibonacchi(i));
    }
    return 0;
}
