#include<stdio.h>
#include<stdlib.h>
char str[20];
int i=0;
int flagB=0,flagA=0;

void S();
void A();
void B();

void advance(){
	i++;
	}

void S(){
	A();
	B();
	if(str[i]=='c'){
		advance();
		if(str[i]=='d')
			advance();
		else
			return;
		}
	else
		return;
	B();
	}

void B(){
	flagB=0;
	if(str[i]=='c'){
		advance();
		A();
		if(str[i]=='d')
			advance();
		else{
			return;
		}
	}
	else if(str[i]=='b')
		advance();
	else
		return;
	}

void A(){
	flagA=0;
	if(str[i]=='a')
		advance();
	else if(str[i]=='d')
		advance();
	else
		return;
	}


void main(){
	printf("\nEnter expression: ");
	scanf("%s",str);
	S();
	if(str[i]=='\0')
		printf("\nValid\n");
	else
		printf("\nInvalid\n");
	}

