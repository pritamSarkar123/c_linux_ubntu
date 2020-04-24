#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
int main(int argc,char** argv){
	int pipe1[2],pipe2[2];
	pipe(pipe1); //creating pipe 1
	pipe(pipe2); //creating pipe 2
	if(pipe(pipe1)==-1){
		fprintf(stderr,"pipe error!");
		return 1;
	}
	if(pipe(pipe2)==-1){
		fprintf(stderr,"pipe error!");
		return 1;
	}
	pid_t childId=fork();
	if(childId<0){ //child not created
		fprintf(stderr,"child error!");
		return 1;
	}
	if(childId!=0){ //parent process block //2nd
		char string[100];
		printf("Parent process ID=%d childId=%d\n",getpid(),childId);
		close(pipe1[0]); // closing reading end
		close(pipe2[1]); // closing writting end

		//parent receiving the message from child
		read(pipe2[0],string,100); // port, storing array, lengh
		printf("parent receives from child : '%s'\n",string);
		char *parentReply=" It's ok from Parent";
		int i=strlen(string);
		while(*parentReply!='\0'){
			string[i++]=*parentReply++;
		}
		string[i]='\0';
		//parent sending the message to child
		write(pipe1[1],string,strlen(string)+1);
		wait(NULL);
		close(pipe1[1]);
		close(pipe2[0]);
	}
	else{ //child process block //1st
		char string[100];
		printf("Child process ID=%d parentId=%d\n",getpid(),getppid());
		close(pipe1[1]); // closing writting end
		close(pipe2[0]); //closing reading end
		
		printf("hello ! its child ,write the string =\n");
		scanf("%s",string);
		//writting to parent
		write(pipe2[1],string,strlen(string)+1); // port, scanned array, lengh
		
		//sleep(2);
		
		//receiving from parent
		read(pipe1[0],string,100);
		printf("child receives from parent : '%s'\n",string);
		close(pipe1[0]);
		close(pipe2[1]);
	}
	return 0;
	
		
	
}
