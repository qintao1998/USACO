/*
ID: qintao11
LANG: C++
TASK: packrec
*/

#include"public.h"
#ifdef PACKREC

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


struct square{
						int wide;
						int high;
					}square[4] = {0},															//原始四个矩形，
					  combination[5] = {0};												    //组合后的5个矩形


int FindMax(int length[],int n)
{
	int max = 0;
	for(int i=0;i<n;i++)
	{
		if(max<length[i])
			max = length[i];
	}
	return max;
}

int FindMinArea(struct square Temp[],int n)												//找出所有形状中面积最小的
{
	int min;
	int max;
	min =  Temp[0].high*Temp[0].wide;											
	int index = 0;
	int area = 0;
	for(int i=1;i<n;i++)
	{
		area = Temp[i].high*Temp[i].wide;
		if(area<min)
		{
			max = area;
			index = i;
		}
	}

	return index;
}

int main(void)
{
	FILE *fin;																								//读入文件指针
	FILE *fout;																							//写入文件指针

	if(NULL==(fin=fopen("packrec.in","r")))													//打开文件
	{
		printf("打开文件错误\n");
		exit(0);	
	}

	if(NULL==(fout=fopen("packrec.out","w")))
	{
		printf("打开文件错误\n");
		exit(0);	
	}

	int num[8] = {0};																					//读入的数据
	int ch;																									//每次读入的字符
	int i = 0;																								
	int max;																								//最大值
	struct square TempTwo[4] = {0};															//第二种类型所有形状
	struct  square TempThree[12] = {0};													//第三种类型所有形状
	struct square TempFour[6] = {0};														//第四种类型所有形状
	int sum;																								//几个值的和
	int index;																								//位置标示
	while(EOF!=(ch=getc(fin)))
	{
		if(isdigit(ch))
			num[i++] = int(ch)-48;
	}
	for(int i=0;i<7;i=i+2)
	{
		square[i/2].high = num[i];
		square[i/2].wide = num[i+1];
	}

	/* 第一种类型 */
	combination[0].wide = square[0].wide + square[1].wide + square[2].wide + square[3].wide;	
	max = 0;
	for(int i=0;i<4;i++)
	{
		if(max<square[i].high)
			max = square[i].high;
	}
	combination[0].high = max;

	/* 第二种类型 */
	for(int i=0;i<4;i++)																				//找到所有能形状
	{
		sum = square[0].wide+square[1].wide+square[2].wide + square[3].wide - square[i].wide;
		if(sum>=square[i].high)
			TempTwo[i].wide = sum;
		else
			TempTwo[i].wide = square[i].high;
		max = 0;
		for(int j=0;j<4;j++)
		{
			if((max<square[j].high)&&(j!=i))
				max = square[j].high;	
		}
		TempTwo[i].high = max+square[i].wide;
	}

	index = 0;
	index = FindMinArea(TempTwo,4);
	combination[1].wide = TempTwo[index].wide;
	combination[1].high = TempTwo[index].high;

	/* 第三种类型 */
	int type[12][4] = {0,1,2,3,
								0,1,3,2,
								0,2,1,3,
								0,2,3,1,
								0,3,1,2,
								0,3,2,1,
								1,2,0,3,
								1,2,3,0,
								1,3,0,2,
								1,3,2,0,
								2,3,0,1,
								2,3,1,0
	};

	for(int i=0;i<12;i=i+2)
	{
		sum = square[type[i][0]].wide+square[type[i][1]].wide;
		if(sum>=square[type[i][2]].high)
		{
			TempThree[i].wide = sum + square[type[i][3]].wide;
			int HighOne[3] = {0};
			HighOne[0] = square[type[i][0]].high + square[type[i][2]].wide;
			HighOne[1] = square[type[i][1]].high + square[type[i][2]].wide;
			HighOne[2] = square[type[i][3]].high;
			TempThree[i].high = FindMax(HighOne,3);
		}
		else
		{
			TempThree[i].wide = square[type[i][2]].high + square[type[i][3]].wide;
			int HighTwo[3] = {0};
			HighTwo[0] = square[type[i][0]].high + square[type[i][2]].wide;
			HighTwo[1] = square[type[i][1]].high + square[type[i][2]].wide;
			HighTwo[2] = square[type[i][3]].high;
			TempThree[i].high = FindMax(HighTwo,3);		
		}
	
	}

	index = 0;
	index = FindMinArea(TempThree,12);	
	combination[2].wide = TempThree[index].wide;
	combination[2].high = TempThree[index].high;

	/* 第四种类型 */
	for(int i=0;i<12;i++)
	{
		int j = i/2;
		sum = square[type[i][0]].wide + square[type[i][1]].wide;
		if(square[type[i][2]].wide>=square[type[i][3]].wide)
		{
			TempFour[j].wide = sum + square[type[i][2]].wide;
			int HighThree[3] = {0};
			HighThree[0] = square[type[i][0]].high;
			HighThree[1] = square[type[i][1]].high;
			HighThree[0] = square[type[i][2]].high +  square[type[i][3]].high;
			TempFour[j].high = FindMax(HighThree,3);
		}
		else
		{
			TempFour[j].wide = sum + square[type[i][3]].wide;
			int HighFour[3] = {0};
			HighFour[0] = square[type[i][0]].high;
			HighFour[1] = square[type[i][1]].high;
			HighFour[0] = square[type[i][2]].high +  square[type[i][3]].high;
			TempFour[j].high = FindMax(HighFour,3);		
		}
	
	}
	index = 0;
	index = FindMinArea(TempFour,6);	
	combination[3].wide = TempFour[index].wide;
	combination[3].high = TempFour[index].high;


	return 0; 
}








#endif