/*
ID: qintao11
LANG: C++
TASK: crypt1
*/

#include"public.h"
#ifdef CRYPT1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int main(void)
{
	FILE *fin;
	FILE *fout;

	int NumOfDig;
	int num[9] = {0};
	char ch;

	if(NULL==fopen("crypt1.in","r"))
	{
		printf("���ļ�����\n");
		exit(0);
	}

	if(NULL==fopen("crypt1.out","w"))
	{
		printf("���ļ�����\n");
		exit(0);
	}

	if(EOF!=(ch=getc(fin)))
	{
		
	
	}












	return 0;
}

















#endif