#include<stdio.h>
int myStrlen(char *s){ //length of string
    int len=0;
    while(*s++!='\0'){
        len++;
    }
    return len;
}
void myStrcat(char *t,char *s){ //concatination
    t+=myStrlen(t);
    while(*s!='\0'){
        *t++=*s++;
    }
    *t='\0';
}
void myStrNcat(char *t,char *s,int n){ //concatination of 1st n charachter
    t+=myStrlen(t);
    int i=0;
    while(*s!='\0' && i++<n){
        *t++=*s++;
    }
    *t='\0';
}
void myStrcpy(char *t,char *s){ //entire string coppy
    while(*s!='\0'){
        *t++=*s++;
    }
    *t='\0';
}
void myStrNcpy(char *t,char *s,int n){ //coppy upto 1st n char
    int i;
    while(*s!='\0' && i++<n){
        *t++=*s++;
    }
    *t='\0';
}
void myStrlwr(char *t){ //lower
    while(*t!='\0'){
        if(*t>=65 && *t<=90) *t+=32;
        t++;
    }
}
void myStrupr(char *t){ //upper
    while(*t!='\0'){
        if(*t>=97 && *t<=122) *t-=32;
        t++;
    }
}
int myStrcmp(char *t,char*s){ //string comparison considering case
    while(*t!='\0' || *s!='\0'){
        if ((*t-*s)!=0){
            return (*t-*s);
        }
        t++;
        s++;
    }
    return 0;
}
int myStrcmpI(char *t,char *s){ //string comparison by ignoring case
    while(*t!='\0' || *s!='\0'){
        if ((*t-*s)!=0){
            if((*t>=65 && *t<=90)&&(*s>=97 && *s<=122)){ //t upper s lower
                if(*t+32 != *s) return (*t-*s);
            }
            if((*s>=65 && *s<=90)&&(*t>=97 && *t<=122)){  //t lower s upper
                if(*t-32 != *s) return (*t-*s);
            }
            if(((*s>=65 && *s<=90)&&(*t>=65 && *t<=90))||((*t>=97 && *t<=122)&&(*s>=97 && *s<=122))){ //both upper or lower
                if(*t != *s) return (*t-*s);
            }
        }
        t++;
        s++;
    }
    return 0;
}
void myStrRev(char *t){ //reversing the string by reference
    char *s,temp;
    s=t+myStrlen(t)-1;
    while(t<s){ //up to middle position
        temp=*t;
        *t=*s;
        *s=temp;
        t++;
        s--;
    }
}
char *myStrchr(char *t,char c){ //1st occurance of the character
    while(*t!='\0'){
        if(*t==c) return t;
        t++;
    }
    return NULL;
}
char *myStrRchr(char *t,char c){ //last occurance of the character
    char *s;
    s=t+myStrlen(t)-1; 
    while(t<=s){
        if(*s==c) return s;
        s--;
    }
    return NULL;
}
char *myStrStr(char *t,char *s){ //1st occurance of the string
    int l=myStrlen(s),i;
    //printf("%d\n",l);
    int missmathed;
    while(*t!='\0'){
        
        if(*t==*s){
            i=0;
            while(i<l){
                missmathed=0;
                //printf("%c %c \n",t[i],s[i]);
                if(t[i]!=s[i]){
                    missmathed=1;
                }
                i++;
            }
            if(missmathed==0) return t;
        }
        
        t++;
    }
    return NULL;
}
void myStrset(char *t,char c){
    while(*t!='\0') *t++=c;
    *t='\0';
}
void myStrNset(char *t,char c,int n){
    while(*t!='\0' && n-->0) *t++=c;
}
int main(){
    char t[]="PritaM";
    char s[]=" Sarkar";
    char c[]="";
    //myStrNcpy(c,t,2);
    //myStrupr(t);
    myStrcat(t,s);
    myStrRev(t);
    printf("%s\n",t);
    char *p=myStrStr(t,"S ");
    printf("%s\n",p);
    myStrNset(t,'G',3);
    printf("%s\n",t);
    //printf("%d",myStrcmpI(t,"pritam"));
    return 0;
}
