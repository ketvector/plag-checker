#include<stdio.h>
// I am Groot
int main()
{
	int T ;
	scanf("%d",&T);
	while(T--)
	{
		double s , v , t ;
		scanf("%lf%lf",&s,&v);
		t = (2*s)/(3*v);
		printf("%lf\n",t);
	}
}
