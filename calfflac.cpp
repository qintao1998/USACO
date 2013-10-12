/*
ID: qintao11
LANG: C
TASK: calfflac
*/

#include"public.h"
#ifdef CALFFLAC_C

#include<stdio.h>
#include<string.h>

int main(void)	
{
	int ch;
	FILE *fin;
	FILE *fout;
	int count = 0;

	if(NULL==(fin = fopen("calfflac.in","r")))							//���ļ�������
	{
		printf("��fin�ļ�����\n");
		return 1;	
	}

	if(NULL==(fout = fopen("calfflac.out","r")))					//���ļ�������
	{
		printf("��fout�ļ�����\n");
		return 1;	
	}


	while ((EOF!=(ch = getc(fin))))
	{
		//putc(ch,stdout);
		putchar(ch);
		count++;
	}

	fclose(fin);
	fclose(fout);

	printf("%d\n",count);

	return 0;


}



#endif