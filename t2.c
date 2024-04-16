#include<stdio.h>
#include<string.h>
#define MAX 1010
int isAllOnes(char l[] , int s)
{
	int i = 0;
	while(i<s)
	{
		if(l[i] == '0')
			return 0;
		i++;
	}
	return 1;
}
int countOnes(char l[] , int s)
{
	int i = 0 , count = 0 ;
	while(i<s)
	{
		if(l[i] == '1')
			count++;
		i++;
	}
	return count;
}
int countRightOnes(char l[] , int s)
{
	int i = s-1 , count = 0;
	while(i>=0)
	{
		if(l[i] == '1')
			count++;
		else
			break;
		i--;
	}
	return count;
}
int countTotal(char l1[] , char l2[] , char l3[] , int n)
{
	int s1 = strlen(l1) , s2 = strlen(l2) , s3 = strlen(l3) ;
	return countOnes(l1,s1)+n*countOnes(l2,s2)+countOnes(l3,s3);
}

int countChange(char l1[] , char l2[] , char l3[] , int n)
{
	int s1 = strlen(l1) , s2 = strlen(l2) , s3 = strlen(l3) ;
	int totals =  countTotal(l1,l2,l3,n);
	if(!isAllOnes(l3,s3))
		totals = totals-countRightOnes(l3,s3)+1;
	else
	{
		if(!isAllOnes(l2,s2))
		{
			totals = totals - s3 - countRightOnes(l2,s2)+1;
		}
		else
		{
			totals = totals - s3 - n*s2 - countRightOnes(l1,s1)+1;
		}
	}
		
}

int main(void)
{
	//freopen("data.txt","r",stdin);
	int t ;
	scanf("%d",&t);
	while(t--)
	{
		char l1[MAX] , l2[MAX] , l3[MAX] ;
		int n ;
		scanf("%s",l1);
		scanf("%s",l2);
		scanf("%s",l3);
		scanf("%d",&n);
		int ans = countChange(l1,l2,l3,n);
		printf("%d\n",ans);
	}
}
