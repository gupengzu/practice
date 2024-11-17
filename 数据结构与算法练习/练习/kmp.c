//构建next数组
#include<stdio.h>
#include<string.h>
//建立LPS数组
void computeLPSArray(char* pat, int M, int* lps)//pat是指向模式字符串的指针，M是模式字符串的长度，lps指向将要构建的LPS数组
{
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while (i < M)
	{
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0)
			{
				len = lps[len - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

//KMP查找
void KMPsearch(char*pat,char*txt)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int* lps = (int*)malloc(sizeof(int) * M);
	computeLPSArray(pat, M, lps);
	int i = 0;
	int j = 0;
	while (i < N)
	{
		if (pat[j] == txt[i])
		{
			i++;
			j++;
		}
		if(pat[j] != txt[i]&&i<N)
		{
			if (j != 0)
			{
				j = lps[j - 1];
			}
			else
			{
				i++;
			}
		}
		if (j == M)
		{
			printf("在%d出开始都一样", j - i);
			j = lps[j - 1];
		}
	}
}