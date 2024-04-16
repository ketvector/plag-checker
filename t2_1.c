    #include<bits/stdc++.h>
    using namespace std;
    int main(void)
    {
    	int i,j,k,l,t,n,m,l1,l2,l3,x,y,z,s,sa,min;
    	char c;
    	cin>>t;
    	while(t--)
    	{
    		l1=l2=l3=0;
    		cin>>n;
    		int a[n],b[n];
    		for(i=0;i<n;i++)
    		{
    			cin>>c;
    			a[i]=c-'0';
    		}
    		for(i=0;i<n;i++)
    		{
    			cin>>b[i];
    		}
    		for(i=n-1;i>-1;i--)
    		{
    			if(a[i]!=0)
    			{
    				m=i;
    				break;
    			}
    		}
    		for(i=0;i<n;i++)
    		{
    			if(a[i]!=0)
    			{
    				k=i;
    				break;
    			}
    		}
    		l1+=b[k]-b[0];
    		l1+=b[n-1]-b[m];
    		if(m==k||m==k+1)
    		{
    			cout<<l1<<endl;
    			continue;
    		}
    		int d=m-k+1;
    		int r[d],re[d];
    		x=k;y=m;
    		for(i=k,z=0;i<=m;i++)
    		{
    			if(a[i]!=0)
    			{
    				r[z++]=0;
    				k=i;
    			}
    			else
    				r[z++]=b[i]-b[k];
    		}
    		for(i=y,z=d-1;i>=x;i--)
    		{
    			if(a[i]!=0)
    			{
    				re[z--]=0;
    				y=i;
    			}
    			else
    			{
    				re[z--]=b[y]-b[i];
    			}
    		}
    		min=b[n-1];
    		for(i=0;i<d-1;i++)
    		{
    			s=r[i]+re[i+1];
    			if(min>s)
    				min=s;
    			if(r[i+1]==0)
    			{
    				l3+=min;
    				min=b[n-1];
    				continue;
    			}
    		}
    		//for(i=0;i<d;i++)
    		//{
    			//cout<<b[i]<<" "<<r[i]<<" "<<re[i]<<endl;
    		//}
    	//	cout<<l1<<" "<<l3<<" ";
    		
    		cout<<l1+l3<<endl;
    	}
    	return 0;
    } 
