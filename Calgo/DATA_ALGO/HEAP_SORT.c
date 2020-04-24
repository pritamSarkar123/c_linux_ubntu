#include<stdio.h>
int a[5]={99,10,15,20,12};
int len=sizeof(a)/sizeof(int);
int leaf(int i){
    if((2*i) > (len-1)) return 1;
    else return 0;
}
int maxindex(int i){
    if((2*i+1) > (len-1)) return (2*i);
    else return (a[2*i] > a[2*i+1]) ? (2*i) : (2*i+1);
}
void swap(int i,int j){
    a[i]=a[i]^a[j];
    a[j]=a[i]^a[j];
    a[i]=a[i]^a[j];
}
void heapyfy(){
    int i,mi;
    for(i=len-1;i>=1;i--){
        if(!leaf(i)){
            mi=maxindex(i);
            if(a[i]<a[mi]) swap(i,mi);
        }
    }
    for(i=1;i<=len-1;i++){
        if(!leaf(i)){
            mi=maxindex(i);
            if(a[i]<a[mi]) swap(i,mi);
        }
    }
    int l=sizeof(a)/sizeof(int);
    for(i=0;i<=l-1;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void heapdelete(){
    int i,mi;
    while(len>2){
        swap(1,len-1);
        len--;
        i=1;
        while(!leaf(i)){
            mi=maxindex(i);
            if(a[i]<a[mi]){
                swap(i,mi);
                i=mi;
            }
            if(i!=mi) break;
        }
    }
    int l=sizeof(a)/sizeof(int);
    for(i=0;i<=l-1;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main(){
    int i;
    int l=sizeof(a)/sizeof(int);
    for(i=1;i<=l-1;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    heapyfy();
    heapdelete();
    for(i=1;i<=l-1;i++){
        printf("%d ",a[i]);    
    }
    printf("\n");
    return 0;
}
