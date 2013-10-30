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
#include<ctype.h>

int main(void)
{
	FILE *fin;																						//�����ļ�ָ��
	FILE *fout;																					//д���ļ�ָ��

	int NumLength = 0;																		//��������
	int num[10] = {0};																		//���������
	char ch;																						//ÿ�ζ�����ַ�
	int temp;																						//�ݴ�����
	int one,two,three;																			//��һ���������ڶ������������
	int sum = 0;																					//���ҵ�ţʽ������
	int TempNum[15] = {0};																//�ֽ�ĳ���
	int FindFlag = 0;																			//���ҵ��ı�־

	if(NULL==(fin = fopen("crypt1.in","r")))											//���ļ�
	{
		printf("���ļ�����\n");
		exit(0);
	}

	if(NULL==(fout = fopen("crypt1.out","w")))
	{
		printf("���ļ�����\n");
		exit(0);
	}

	int i = 0;
	while((EOF!=(ch=getc(fin))))															//��ȡ����	
	{
		if(0!=isdigit(ch))
			num[i++] = (int)ch-48; 	
	}
	
	NumLength = num[0];

	for(int j=0;j<i;j++)
		num[j] = num[j+1];

	for(int j=0;j<NumLength;j++)														//��������
		for(int k=j+1;k<NumLength;k++)
		{
			if(num[j]>num[k])
			{
				temp = num[j];
				num[j] = num[k];
				num[k] = temp;		
			}
		}

	for(int j = 100;j<1000;j++)															//ͳ��ţʽ����
		for(int k = 10;k<100;k++)
		{
			one = j*(k%10);
			if(999>=one)
			{
				two = j*(k/10);
				if(999>=two)
				{
					three = j*k;
					if(9999>=three)
					{
						TempNum[0] = j/100;
						TempNum[1] = (j%100)/10;
						TempNum[2] = (j%100)%10;
						TempNum[3] = k/10;
						TempNum[4] = k%10;
						TempNum[5] = one/100;
						TempNum[6] = (one%100)/10;
						TempNum[7] = (one%100)%10;
						TempNum[8] = two/100;
						TempNum[9] = (two%100)/10;
						TempNum[10] = (two%100)%10;
						TempNum[11] = three/1000;
						TempNum[12] = (three%1000)/100;
						TempNum[13] = ((three%1000)%100)/10;
						TempNum[14] =  ((three%1000)%100)%10;

						int l;
						int m;
						for(l=0;l<15;l++)
						{
							for(m=0;m<NumLength;m++)
							{
								if(TempNum[l]==num[m])
									FindFlag = 1;							
							}
							if(1==FindFlag)
							{
								FindFlag = 0;
								continue;
							}
							else
								break;
						}
						if(15==l)
							sum++;
					}
					else
						continue;
				}
				else
					continue;
			}
			else
				continue;
		}

	fprintf(fout,"%d\n",sum);

	if(NULL!=fclose(fin))
	{
		printf("�ر��ļ�����\n");
		exit(0);
	}

	if(NULL!=fclose(fout))
	{
		printf("�ر��ļ�����\n");
		exit(0);
	}
	return 0;
}

#endif