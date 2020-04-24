#include<stdio.h>
#include<stdarg.h>
// argc number of arguments
// ... multiple arguments
// va_list args list of variable argument
// va_start(args,argc) start the list
// va_arg(args,int) each time returns 1st element of the args list as int
// va_end(args) end the list
int minF(int argc,...){
	va_list args;
	va_start(args,argc);
	int min=va_arg(args,int);
	int i,a;
	for(i=2;i<=argc;i++){
		if((a=va_arg(args,int))<min){
			min=a;
		}
	}
	va_end(args);
	return min;
}
int main(){
	int min=minF(5,9,81,2,7,93);
	printf(" min element =%d ",min);
	return 0;
}
