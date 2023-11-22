#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void display();
int main()
{
    char label[10], opcode[10], operand[10], symbol[10],s[10],s1[10];
    int start, diff, i, address, add, len, actual_len, finaddr, prevaddr, j = 0;
    char mnemonic[15];
    char code[15];
    FILE *fp1, *fp2, *fp3, *fp4,*fp5;
    fp1 = fopen("output.txt", "w");
    fp3 = fopen("intermediate.txt", "r");
    fp4 = fopen("objcode.txt", "w");
    fscanf(fp3, "%s\t%s\t%s", label, opcode, operand);
    //find length of the program
    while (strcmp(opcode, "END") != 0)
    {
        prevaddr = address;
        fscanf(fp3, "%d%s%s%s", &address, label, opcode, operand);
    }
    finaddr = address;
    fclose(fp3);
    fp3 = fopen("intermediate.txt", "r");
    fscanf(fp3, "\t%s\t%s\t%s", label, opcode, operand);
    if (strcmp(opcode, "START") == 0)
    {
        fprintf(fp1, "\t%s\t%s\t%s\n", label, opcode, operand);
        fprintf(fp4, "H^%s^00%s^00%d\n", label, operand, finaddr);
        fscanf(fp3, "%d%s%s%s", &address, label, opcode, operand);
        start = address;
        diff = prevaddr - start;
        fprintf(fp4, "T^00%d^%d", address, diff);
    }
    while (strcmp(opcode, "END") != 0)
    {
        if (strcmp(opcode, "BYTE") == 0)
        {
            fprintf(fp1, "%d\t%s\t%s\t%s\t", address, label, opcode, operand);
            len = strlen(operand);
            actual_len = len - 3;
            fprintf(fp4, "^");
            for (i = 2; i < (actual_len + 2); i++)
            {   
            	sprintf(s, "%x", toascii(operand[i]));
                fprintf(fp1, "%s", s);
                fprintf(fp4, "%s", s);
                strcpy(s,"");
            }
            fprintf(fp1, "\n");
        }
        else if (strcmp(opcode, "WORD") == 0)
        {
            len = strlen(operand);
            sprintf(s1, "%s", (operand));
            fprintf(fp1, "%d\t%s\t%s\t%s\t00000%s\n", address, label, opcode, operand, s1);
            fprintf(fp4, "^00000%s", s1);
        }
        else if ((strcmp(opcode, "RESB") == 0) || (strcmp(opcode, "RESW") == 0))
        {
            fprintf(fp1, "%d\t%s\t%s\t%s\n", address, label, opcode, operand);
        }
        else
        {
		fp2 = fopen("symtab.txt", "r");
		fp5=fopen("optab.txt","r");	
		fscanf(fp5,"%s%s",mnemonic,code);
		while (strcmp(opcode, mnemonic) != 0)
			fscanf(fp5,"%s%s",mnemonic,code);
		fscanf(fp2, "%s%d", symbol, &add);
		while (strcmp(operand, symbol) != 0)
		      fscanf(fp2, "%s%d", symbol, &add);
		fprintf(fp1, "%d\t%s\t%s\t%s\t%s%d\n", address, label, opcode, operand, code, add);
		fprintf(fp4, "^%s%d", code, add);
                fclose(fp2);
       	fclose(fp5);
        }
       
    	fscanf(fp3, "%d%s%s%s", &address, label, opcode, operand);
    }
    fprintf(fp1, "%d\t%s\t%s\t%s\n", address, label, opcode, operand);
    fprintf(fp4, "\nE^00%d", start);
    fclose(fp4);
    fclose(fp3);
    fclose(fp1);
    display();
   return 0;
}
void display() 
{
    char ch;
    FILE *fp1, *fp2, *fp3, *fp4;
    printf("\nIntermediate file is converted into object code");
    printf("\n\nThe contents of Intermediate file:\n\n");
    fp3 = fopen("intermediate.txt", "r");
    ch = fgetc(fp3);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fp3);
    }
    fclose(fp3);
    printf("\n\nThe contents of Symbol Table :\n\n");
    fp2 = fopen("symtab.txt", "r");
    ch = fgetc(fp2);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fp2);
    }
    fclose(fp2);
    printf("\n\nThe contents of Output file :\n\n");
    fp1 = fopen("output.txt", "r");
    ch = fgetc(fp1);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fp1);
    }
    fclose(fp1);

    printf("\n\nThe contents of Object code file :\n\n");
    fp4 = fopen("objcode.txt", "r");
    ch = fgetc(fp4);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fp4);
    }
    fclose(fp4);
}
