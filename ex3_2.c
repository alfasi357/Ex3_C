#include <stdio.h>
#define LINE 256
#define WORD 30
#include <string.h>

int getline3 (char s[])
{
int counter=0;
for(int i=0; i<LINE; i++){
if(s[i]==' '||s[i]=='\n'||s[i]=='\t'||s[i]=='\0'||s[i]=='\r')
break;
counter++;
}
  return counter;
}

int getword (char w[])
{
  int counter = 0;
  while (w[counter]!= ' ' && w[counter]!= '\t' && w[counter]!= '\n'&& w[counter]!= '\r')
    {
    counter++;
    }
  return counter;
}


int substring (char *str1, char *str2)
{
  for (int i = 0; i < strlen (str1)-strlen(str2); i++)
    {
      int t = i;
      for (int j = 0; j < strlen (str2); j++)
	{
	  if (j == strlen (str2) - 1 && *(str1 + t) == *(str2 + j))
	    return 1;
	  if (*(str1 + t) == *(str2 + j))
	    t++;
	  else
	    break;
	}
    }
  return 0;
}


int similar (char *s, char *t, int n)
{
	
  if (strlen (t) > strlen (s))
    return 0;
  int j = 0;
  int count = 0;
  int i;
  for ( i = 0; i < strlen (s)-1; i++)
    {
      if (*(s + i) == *(t + j) && j == strlen (t) - 1&&n>=count+strlen(s)-1-i)
	return 1;
      if (*(s + i) == *(t + j))
	j++;
      else
	count++;
      if (count > n)
	return 0;
      if (i == strlen (s) - 1 && j != strlen (t) - 1)
	return 0;
      if (*(s + i) != *(t + j) && i == strlen (s) - 1 && j == strlen (t) - 1)
	return 0;

    }
    
  return 1;
}


void print_lines (char *str)
{

char s[LINE]={0};
 while(fgets(s,LINE,stdin)){
if(getline3(s)!=0){
	  if (substring (s, str)){
	    printf("%s", s);
	      
	  }
	  for(int i=0; i<LINE;i++)
	  s[i]='\0';
	}
	}
}


void print_similar_words (char *str)
{
char s[LINE]={0};
int check=0;
  while(fgets(s,LINE,stdin)){
	 int i=0;
	 int t=0;
	 while(s[i]!='\n'&&i<strlen(s)){
	 char w[WORD]={0};
	 while(s[i]==' '||s[i]=='\n'||s[i]=='\r'||s[i]=='\0'||s[i]=='\t'){
	 i++;
	 }
	 t = getword(s+i);
	 check=t;
	 for(int j=0;j<check; j++){
	 w[j]=s[j+i];}
	 w[check]=' ';
	  if (similar(w,str, 1)){
	    printf ("%s\n", w);}

	     i+=check;


}
}
}

int main(){
char s[WORD]={0};
char c ='a';
int i =0;
while(c!=' '&&c!='\n'&&c!='\t'){
scanf("%c",&c);
s[i++]=c;
}
s[i-1]='\0';
while(c==' '||c=='\n'||c=='\t'){
scanf("%c", &c);
}
if(c=='a')
print_lines(s);
else
print_similar_words(s);
return 0;
}

