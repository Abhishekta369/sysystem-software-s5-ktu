#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
  FILE *fp;
  int i,addr1,l,j,staddr1;
  char name[10],line[50],name1[10],addr[10],rec[10],ch,staddr[10];
  printf("Enter the name of the program:" );
  scanf("%s",name);
  fp=fopen("objcode.txt","r");
  fscanf(fp,"%s",line);
  for(i=2,j=0;i<7;i++,j++)
  	name1[j]=line[i];
    name1[j]='\0';
  printf("name from obj File. %s\n",name1);
  if(strcmp(name,name1)==0)//verify program name
  {
    do
    {
	    fscanf(fp,"%s",line);
	    if(line[0]=='T')
	    {
		    for(i=2,j=0;i<8;i++,j++)//extract starting address from object file 
			//which is stored from columns 2 to 7 in text record and store it in an array staddr and 
			//convert into interger using atoi function
		    	staddr[j]=line[i];
		    staddr[j]='\0';
		    staddr1=atoi(staddr);
		    i=12;//start object code from column 12
		    while(line[i]!='\0')
		    {
		      if(line[i]!='^')
		      {
		        printf("00%d \t %c%c\n", staddr1,line[i],line[i+1]);// each memory location stores 2 character
		        staddr1++;// increment memory address 
		        i=i+2;//move to next character
		      }
		      else i++;// if it is ^
		    }
		}
		else if(line[0]=='E') 
	    {
			printf("\nExecution address: ");
            for (i = 2; i < 8; i++)
                printf("%c", line[i]);
            break;
        }
	}
	while(!feof(fp));
  }	
  fclose(fp);
}

