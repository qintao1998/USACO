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
  函数名称:  void CalCalfflacLength(char calfflac[],int CalLength[],int length)										
  功能描述:  最大子回文字符串查找
  输入参数:  char calfflac[]——去除非字母后的字符串
				 int CalLength[]——各字符对应的回文长度
				 int length——输入的字符串长度
  输出参数:  无
  返回值	  :  无
  
  修改日期:  2013.10.18
  修改人	  :  秦涛
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
  函数名称:  int  FindMaxLocation(int CalLength[],int Location[],char Calfflac[],int length,int *max)										
  功能描述:  最大回文位置查找
  输入参数:  int CalLength[]——各字符对应的回文长度
			     int Location[]——字符在原始字符串中的位置
				 char Calfflac[]——去除非字母后的字符才
				 int length——输入的字符串长度
				 int *max——最大子回文字符串长度
  输出参数:  无
  返回值	  :  无
  
  修改日期:  2013.10.18
  修改人	  :  秦涛
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
  函数名称: int RecoverCalfflac(char Temp[],int index,int length,FILE *fout)										
  功能描述:  恢复最长回文子串
  输入参数:  char Temp[]——原始字符串
			     int index——回文字符在原始字符串的位置
				 int length——回文字符串的长度
				 FILE * fout——输出文件
  输出参数:  无
  返回值	  :  无
  
  修改日期:  2013.10.20
  修改人	  :  秦涛
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
	

	char Calfflac[MAXNUM]     = {0};									//去掉非字母的字符串
	char Temp[MAXNUM]       = {0};									//原始字符串
	int CalLength[MAXNUM]   = {0};									//子回文串长度
	int Location[MAXNUM]     = {0};									//字符在原始字符串中的位置

	if(NULL==(fin = fopen("calfflac.in","r")))							//打开文件错误处理
	{
		printf("打开fin文件错误\n");
		return 1;	
	}

	if(NULL==(fout = fopen("calfflac.out","w")))					//打开文件错误处理
	{
		printf("打开fout文件错误\n");
		return 1;	
	}

	memset(Calfflac,'*',MAXNUM);										//初始化数组
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


