/*
ID: qintao11
LANG: C++
TASK: calfflac
*/

#include"public.h"
#ifdef CALFFLAC_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAXNUM 40020

int OddEvenFlag = 0;


/**************************************************************************** 
  ��������:  void CalCalfflacLength(char calfflac[],int CalLength[],int length)										
  ��������:  ����ӻ����ַ�������
  �������:  char calfflac[]����ȥ������ĸ����ַ���
				 int CalLength[]�������ַ���Ӧ�Ļ��ĳ���
				 int length����������ַ�������
  �������:  ��
  ����ֵ	  :  ��
  
  �޸�����:  2013.10.18
  �޸���	  :  ����
*****************************************************************************/
void CalCalfflacLength(char calfflac[],int CalLength[],int length)										
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

}


/**************************************************************************** 
  ��������:  int  FindMaxLocation(int CalLength[],int Location[],char Calfflac[],int length,int *max)										
  ��������:  ������λ�ò���
  �������:  int CalLength[]�������ַ���Ӧ�Ļ��ĳ���
			     int Location[]�����ַ���ԭʼ�ַ����е�λ��
				 char Calfflac[]����ȥ������ĸ����ַ���
				 int length����������ַ�������
				 int *max��������ӻ����ַ�������
  �������:  ��
  ����ֵ	  :  ��
  
  �޸�����:  2013.10.18
  �޸���	  :  ����
****************************************************************************/
int  FindMaxLocation(int CalLength[],int Location[],char Calfflac[],int length,int *max)
{
	*max = CalLength[0];
	int index = 0;
	for(int i = 1;i<length;i++)
	{
		if(*max<CalLength[i])
		{
			*max = CalLength[i];
			index = i;
		}
	}
	if(0==(*max%2))
		return Location[index];
	else
		return Location[index-1]; 
}

/**************************************************************************** 
  ��������: int RecoverCalfflac(char Temp[],int index,int length,FILE *fout)										
  ��������:  �ָ�������Ӵ�
  �������:  char Temp[]����ԭʼ�ַ���
			     int index���������ַ���ԭʼ�ַ�����λ��
				 int length���������ַ����ĳ���
				 FILE * fout��������ļ�
  �������:  ��
  ����ֵ	  :  ��
  
  �޸�����:  2013.10.20
  �޸���	  :  ����
****************************************************************************/

int RecoverCalfflac(char Temp[],int index,int length,FILE *fout)
{
	fprintf(fout,"%d\n",length-1);
	int num = (length-1)/2;
	int max = 0;
	int min = 0;
	int flag = index;
	if(0==(length%2))
	{
		max = index;
		while(num>0)
		{
			if(0!=isalpha(Temp[(flag++)+1]))
			{
				max++;
				num--;
			}
			else
				max++;						
		}

		num = (length-1)/2;
		flag = index;
		min = index;
		while(num>0)
		{
			if(0!=isalpha(Temp[(flag--)-1]))
			{
				min--;
				num--;
			}
			else
				min--;						
		}
	}
	else
	{
		max = index;
		while(num>0)
		{
			if(0!=isalpha(Temp[(flag++)+1]))
			{
				max++;
				num--;
			}
			else
				max++;						
		}

		num = (length-1)/2;
		flag = index;
		min = index;
		while((num-1)>0)
		{
			if(0!=isalpha(Temp[(flag--)-1]))
			{
				min--;
				num--;
			}
			else
				min--;						
		}
	
	}

	for(int i = min;i<=max;i++)
		fprintf(fout,"%c",Temp[i]);
	fprintf(fout,"\n");

	return 0;
}

int main(void)	
{
	int ch;
	int max;
	int index;
	FILE *fin;
	FILE *fout;
	

	char Calfflac[MAXNUM]     = {0};									//ȥ������ĸ���ַ���
	char Temp[MAXNUM]       = {0};									//ԭʼ�ַ���
	int CalLength[MAXNUM]   = {0};									//�ӻ��Ĵ�����
	int Location[MAXNUM]     = {0};									//�ַ���ԭʼ�ַ����е�λ��

	if(NULL==(fin = fopen("calfflac.in","r")))							//���ļ�������
	{
		printf("��fin�ļ�����\n");
		return 1;	
	}

	if(NULL==(fout = fopen("calfflac.out","w")))					//���ļ�������
	{
		printf("��fout�ļ�����\n");
		return 1;	
	}

	memset(Calfflac,'*',MAXNUM);										//��ʼ������
	for(int i = 0;i<MAXNUM;i++)
	{
		CalLength[i] = 1;
	}

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
			Location[i] = j-1;
			i = i+2;
		}
	}
	Calfflac[i] = 0;

	CalCalfflacLength(Calfflac,CalLength,i);		

	index = FindMaxLocation(CalLength,Location,Calfflac,i,&max);

	RecoverCalfflac(Temp,index,max,fout);



	fclose(fin);
	fclose(fout);

	return 0;


}



#endif


