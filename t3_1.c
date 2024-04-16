    #include <stdio.h>
     
    int main()
    {
    	int t, n, arr[100001], arr1[100001], arr2[100001], arr3[100001], i, length, j, flag, k, max;
    	char str[100001];
    	scanf("%d", &t);
    	while(t--)
    	{
    		j=length=flag=0;
    		scanf("%d", &n);
    		scanf("%s", str);
    		for(i=0;i<n;i++)
    		{
    			if(str[i]=='1')
    				arr1[j++]=i;
    			scanf("%d", &arr[i]);
    		}
    		for(i=0;i<n;i++)
    		{
    			if(str[i]=='1')
    			{
    				length=0;
    				arr2[i]=0;
    				flag=1;
    			}
    			else
    			{
    				if(length==0 && flag==0)
    				{
    					arr2[i]=0;
    				}
    				else if(flag==1)
    				{
    					length+=arr[i]-arr[i-1];
    					arr2[i]=length;
    				}
    			}
    		}
    		for(i=n-1;i>=0;i--)
    		{
    			if(str[i]=='1')
    			{
    				length=0;
    				arr3[i]=0;
    				flag=1;
    			}
    			else
    			{
    				if(length==0 && flag==0)
    				{
    					arr3[i]=0;
    				}
    				else if(flag==1)
    				{
    					length+=arr[i+1]-arr[i];
    					arr3[i]=length;
    				}
    			}
    		}
    		length=0;
    		if(j==1)
    		{
    			if(arr1[0]>0 && arr1[0]<n-1)
    				length=arr3[0]+arr2[n-1];
    			else if(arr1[0]==0)
    				length=arr2[n-1];
    			else if(arr1[0]==n-1)
    				length=arr3[0];
    			printf("%d\n", length);
    		}
    		else
    		{
    			if(arr1[0]!=0)
    				length=arr3[0];
    			for(i=0;i<j-1;i++)
    			{
    				max=0;
    				for(k=arr1[i]+1;k<=arr1[i+1];k++)
    					if(max<arr[k]-arr[k-1])
    						max=arr[k]-arr[k-1];
    				length+=arr[arr1[i+1]]-arr[arr1[i]]-max;
    			}
    			if(arr1[j-1]!=n-1)
    				length+=arr2[n-1];
    			printf("%d\n", length);
    		}
    	}
    	return 0;
    } 
