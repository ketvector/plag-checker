#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,bijli_yes,l,t,num_vill,m,left1,left2,left3,x,y,z,s,sa,minimum;
	char binary_string;
	cin>>t;
	while(t--)
	{
		left1=left2=left3=0;
		cin>>num_vill;
		int bijli_check[num_vill],village_distance[num_vill];
		for(i=0;i<num_vill;i++)
		{
			cin>>binary_string;
			bijli_check[i]=binary_string-'0';
		}
		for(i=0;i<num_vill;i++)
		{
			cin>>village_distance[i];
		}
		for(i=num_vill-1;i>-1;i--)
		{
			if(bijli_check[i]!=0)
			{
				m=i;
				break;
			}
		}
		
		//checking for bijli available in village
			for(i=0;i<num_vill;i++)
			{
				if(bijli_check[i]!=0)
				{
					bijli_yes=i;
					break;
				}
			}
		left1+=village_distance[bijli_yes]-village_distance[0];
		left1+=village_distance[num_vill-1]-village_distance[m];
		if(m==bijli_yes||m==bijli_yes+1)
		{
			cout<<left1<<endl;
			continue;
		}
		int d=m-bijli_yes+1;
		int r[d],re_calculate[d];
		x=bijli_yes;y=m;
		//cal from left to right
		for(i=bijli_yes,z=0;i<=m;i++)
		{
			if(bijli_check[i]!=0)
			{
				r[z++]=0;
				bijli_yes=i;
			}
			else
				r[z++]=village_distance[i]-village_distance[bijli_yes];
		}
		//cal from right to left
		for(i=y,z=d-1;i>=x;i--)
		{
			if(bijli_check[i]!=0)
			{
				re_calculate[z--]=0;
				y=i;
			}
			else
			{
				re_calculate[z--]=village_distance[y]-village_distance[i];
			}
		}
		minimum=village_distance[num_vill-1];
		for(i=0;i<d-1;i++)
		{
			s=r[i]+re_calculate[i+1];
			if(minimum>s)
				minimum=s;
			if(r[i+1]==0)
			{
				left3+=minimum;
				minimum=village_distance[num_vill-1];
				continue;
			}
		}
	
		cout<<left1+left3<<endl;
	}
	return 0;
	
}
