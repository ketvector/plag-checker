#include<stdio.h>
int main()
{
	int t,sum, co[100000],n,i,j,k,leftpos,rightpos,pos,temprp,templp,tempsum1,tempsum;
	char arr[100000];
 
	scanf("%d",&t);
	while(t--)
	{
        scanf("%d",&n);
        scanf("%s",&arr);
        i=0;
        sum=0;
        while(i<n)
        {
            scanf("%d",&co[i]);
            i++;
        }
        i=0;
        while(i<n)
        {
            if(arr[i]=='0')
            arr[i]=1;
            else
            {
                sum=sum+co[i]-co[0];
                break;
            }
 
        i++;
        }
              //  printf("sum left%d\n",sum);
 
        i=n-1;
        while(i>=0)
        {
            if(arr[i]=='0')
            arr[i]=1;
            else
            {
                sum=sum+co[n-1]-co[i];
                break;
            }
 
        i--;
        }
 
       // printf(" sum right %d\n",sum);
 
        i=0;
        while(i<n-1)
        {
            if(arr[i]=='1'&& arr[i+1]=='0')
            {
                leftpos=i;
                templp=i;
                while(i<n-1)
                {
                    if(arr[i]=='0'&& arr[i+1]=='1')
                    {
                    rightpos=i+1;
                    temprp=i+1;
                    break;
                    }
                    i++;
 
                }
                i--;
                j=leftpos+1;
                tempsum=0;
                tempsum1=0;
                printf(" left%d ,right%d",leftpos,rightpos);
 
                while(j<temprp)
                {
                    if(arr[j]=='0')
                    {
 
                    if((co[j]-co[templp])>=(co[rightpos]-co[j]))
                    {
                        tempsum=tempsum+co[rightpos]-co[j];
                        while(j<rightpos)
                        {
                        arr[j]='1';
                        j++;
                        }
                    }
                    else if(( co[j]-co[templp])<(co[rightpos]-co[j]))
                    {
                        tempsum=tempsum+co[j]-co[templp];
                        arr[j]='1';
                        templp++;
                    }
                    else;
 
                    }
                    j++;
                }
                 //               printf(" left%d ,right%d",leftpos,rightpos);
 
        //    printf("tempsum= %d\n",tempsum);
  //  puts(arr);
                j=leftpos+1;
                while(j<rightpos)
                {
                    arr[j]='0';
                    j++;
                }
              //  puts(arr);
                j=rightpos-1;
                templp=leftpos;
                temprp=rightpos;
                while(j>templp)
                {
                    if(arr[j]=='0')
                    {
 
                    if((co[j]-co[templp])>(co[temprp]-co[j]))
                    {
                        tempsum1=tempsum1-co[j]+co[temprp];
                        arr[j]='1';
                        temprp--;
 
                    }
                    else if(( co[j]-co[templp])<=(co[temprp]-co[j]))
                    {
                        tempsum1=tempsum1-co[templp]+co[j];
                        while(j>temprp)
                        {
                        arr[j]='1';
                        j--;
                        }
                    }
                    else;
 
                    }
                    j--;
                }
              //  printf(" left%d ,right%d",leftpos,rightpos);
 
 
               // printf("tempsum1=%d\n",tempsum1);
 
                if(tempsum1>tempsum)
                sum=sum+tempsum;
                else
                sum=sum+tempsum1;
 
 
            }
 
                i++;
        }
        printf("%d\n",sum);
	}
return 0;
}
