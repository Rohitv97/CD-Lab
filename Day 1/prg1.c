#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

void main()
{
    int state=0,flag=0,i,p=0,id=0;
    char ch,word[20],kw[20][20]={"int","float","char","long","double","if","else","for","while","void","do","switch","case","break"};
    FILE *f;
    f = fopen("input.txt","r");
    while(flag!=1)
    {
      switch(state)
      {
        case 0: ch = fgetc(f);
                if(isalnum(ch)){
                  if(isalnum(ch))
                    state = 11;
                  else
                    state = 13;
                }
                else if(ch=='<')
                  state = 1;
                else if(ch=='>')
                  state = 4;
                else if(ch=='!')
                  state = 7;
                else if(ch=='=')
                  state = 9;
                break;
        case 1: ch = fgetc(f);
                if(ch=='=')
                  state = 2;
                else
                  state = 3;
                break;
        case 2: printf("'<=' is a relational operator\n");
                state = 0;
                break;
        case 3: fseek(f,-1,SEEK_CUR);
                printf("'<' is a relational operator\n");
                state = 0;
                break;
        case 4: ch = fgetc(f);
                if(ch=='=')
                  state = 5;
                else
                  state = 6;
                break;
        case 5: printf("'>=' is a relational operator\n");
                state = 0;
                break;
        case 6: fseek(f,-1,SEEK_CUR);
                printf("'>=' is a relational operator\n");
                state = 0;
                break;
        case 7: ch = fgetc(f);
                if(ch=='=')
                  state = 8;
                else
                  {
                    fseek(f,-1,SEEK_CUR);
                    state = 0;
                  }
                break;
        case 8: printf("'!=' is a relational operator\n");
                state = 0;
                break;
        case 9: ch = fgetc(f);
                if(ch=='=')
                  state = 10;
                else
                  {
                    fseek(f,-1,SEEK_CUR);
                    state = 0;
                  }
                break;
        case 10:printf("'==' is a relational operator\n");
                state = 0;
                break;
        case 11:word[p++]=ch;
                while(isalnum(ch=fgetc(f)))
                  word[p++] = ch;
                fseek(f,-1,SEEK_CUR);
                word[p] = '\n';
                state = 12;
                p=0;
                break;
        case 12:for(i=0;i<14;i++){
                  if(strcmp(kw[i],word)==0){
                    printf("%s is a keyword\n",word);
                    id = 1;
                    break;
                  }
                }
                if(id==0)
                  printf("%s is an identifier\n",word);
                state=0;
                id = 0;
                break;
        case 13:word[p++]=ch;
                while(isdigit(ch=fgetc(f)))
                  word[p++]=ch;
                fseek(f,-1,SEEK_CUR);
                word[p]='\0';
                state = 14;
                p=0;
                break;
        case 14:printf("%s is a number\n",word);
                state = 0;
                break;
        default: break;
      }
      if(ch==EOF)
        flag=1;
    }fclose(f);

}
