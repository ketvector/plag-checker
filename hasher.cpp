#include"preprocess.hpp"
#include"hasher.hpp"
#include<cmath>

//Store line numbers with start and end characters.
vector<info> getInfo(string& a)
{
	vector<info> V ;
	int len = a.length();
	stringstream fss ;
	int currline = 0 , isStart = 1 , now = -1 , j = -1 ;
	for(int i = 0 ; i < len ; i++)
	{
		if(isStart == 1)
		{
			currline++;
			if(a[i] != '$')
			{
				j++;
				fss << a[i] ;
				now ++ ;
				info temp;
				temp.line = currline;
				temp.start = j;
				V.push_back(temp);
			}
			isStart = 0;
		}
		else if(a[i] == '\n' || a[i] == '\r')
		{
			V[now].end = j;
			isStart = 1;
		}
		else
		{
			j++;
			fss << a[i];
		}
	}
	a.assign(fss.str());
	return V;
}

//Rolling Rabin-Karp Hashing
vector<hash_structure> generateHashes(string& a , long long  k , long long q , vector<info> I)
{
	vector<hash_structure> V ;
	long long highDegree = mod( pow(BASE,k) , q ) ;
	int len = a.length()  ;
	long long hash = 1 ;
	int i;
	for(i=0 ; i<k ; i++)
	{
		hash = mod ( mod( (hash*BASE) , q ) + a[i] , q ) ;
	}
	hash = mod(hash*BASE , q);
	int start = findline(0,I) , end = findline(k-1,I);
	hash_structure temp ;
	temp.hash = hash ; temp.start = start ; temp.end = end ;
	for(; i< len-k+1 ; i++)
	{
		start = findline(i,I) ; 
		end = findline(i+k-1,I);
		hash = mod( mod( mod(hash-BASE*highDegree,q) + a[i] , q ) * BASE , q );
		temp.hash = hash ; temp.start = start ; temp.end = end ;
		V.push_back(temp);
	}
	return V; 
}

long long mod(long long a , long long m)
{
	long long x = a%m;
	if(x>=0)
		return x;
	else
		return x+m;
}
// binary search to find the line number of a given character.
int findline(int i , vector<info> I)
{
	int len = I.size();
	int left = 0 , right = len-1;
	int ret = -1 ;
	while(left <= right)
	{
		int mid = (left+right)/2 ;
		if(i >= I[mid].start && i <= I[mid].end)
		{
			return I[mid].line ;
		}
		else if(i < I[mid].start)
		{
			right = mid-1;
		}
		else if(i > I[mid].end)
		{
			left = mid+1;
		}
	}	
	return ret ;
}
