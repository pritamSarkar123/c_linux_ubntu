#include<stdio.h>
void func1(){
	int x=100;
	if(x>50){
		x=50;
	}
	if(x<60){
		x=40;
	}
	if(50<=x<=60){x=30;}
	printf("%d",x);
}
void func2(){
	int x=100;
	if(x>50){
		x=50;
	}
	else if(x<60){
		x=40;
	}
	else{x=30;}
	printf("%d",x);
}
int main(){
	func1();
	func2();
	return 0;
}
