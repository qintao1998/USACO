/*
ID: qintao11
LANG: C
TASK: calfflac
*/

#include"public.h"
#ifdef CALFFLAC_C

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXNUM 40020


int CalCalfflacLength(char calfflac[],int CalLength[],int length)
{
	for(int i=0;i<length;i++)
	{
		int j = 1;
		while((i-j)>=0&&(i+j)<=length)
		{
			if(calfflac[i-j]==calfflac[i+j])
			{
				CalLength[i]++;
				j++;
			}
			else
				break;
		}
	}


	return 0;
}


int RecoverCalfflac()
{




}

int main(void)	
{
	int ch;
	FILE *fin;
	FILE *fout;

	char Calfflac[MAXNUM]    = {0};
	char Temp[MAXNUM]      = {0};
	int CalLength[MAXNUM]  = {0};
	int Location[MAXNUM]     = {0};

	if(NULL==(fin = fopen("calfflac.in","r")))							//打开文件错误处理
	{
		printf("打开fin文件错误\n");
		return 1;	
	}

	if(NULL==(fout = fopen("calfflac.out","r")))					//打开文件错误处理
	{
		printf("打开fout文件错误\n");
		return 1;	
	}

	memset(Calfflac,'*',MAXNUM);										//初始化数组
	for(int i = 0;i<MAXNUM;i++)
		CalLength[i] = 1;

	int i = 1;
	int j = 0;
	int k = 0;
	while ((EOF!=(ch = getc(fin))))
	{
		Temp[j++] = ch;
		if(0!=isalpha(ch))
		{
			if(0!=isupper(ch))
				ch = tolower(ch);
			Calfflac[i] = ch;
			i = i+2;
		}
	}
	Calfflac[i] = 0;

	CalCalfflacLength(Calfflac,CalLength,i);		

	fclose(fin);
	fclose(fout);


	puts((const char *)Temp);

	puts((const char *)Calfflac);

	return 0;


}



#endif


