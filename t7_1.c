 #include<stdio.h>
     
    long long a[100015];
    int pos[100015];
    char s[100015];
     
     //this is a comment
    inline long long
    Max(long long x, long long y) {
    	return x > y ? x : y;
    }
     
    inline long long
    Min(long long x, long long y) {
    	return x > y ? x : y;
    }
     
     
    inline long long
    Scan_u(){
    	long long int num = 0;
        	char c = getchar_unlocked();
        	while(!(c>='0' & c<='9'))
        	    c=getchar_unlocked();
        	while(c>='0' && c<='9'){
        	    num = (num<<1)+(num<<3)+c-'0';
        	    c=getchar_unlocked();
        	}
    	return num;
    }
     
    int 
    Inp(int n){
    	int i = 0, itr = 0;
    	while(i<n){
    		char c = getchar_unlocked();
    		if(c=='1')
    			pos[itr++] = i;
    		i++;
    	}
    	i = 0;
    	while(i<n){
    		a[i++] = Scan_u();
    	}
    	return itr;
    }
     
     
    int main() {
    	int t, tc;
    	t = Scan_u();
    	for(tc=0; tc<t; tc++) {
    		int itr; long long Ans = 0;
    		int n = Scan_u();
    		int totSeg = Inp(n);
    		int segStrt = pos[0], segEnd, segNo = 1;
    		while(segNo < totSeg){
    			segEnd = pos[segNo];
    			Ans+= a[segEnd] - a[segStrt];
    			int s = 0;
    			for(itr = segStrt+1; itr <= segEnd; itr++)
    				s = Max(s, a[itr] - a[itr-1]);
    			Ans -= s;
    			segStrt = pos[segNo];
    			segNo++;
    		}
    		Ans += a[n-1] - a[segStrt];
    		Ans += a[pos[0]] - a[0];
    		printf("%lld\n",Ans);
    	}
    	return 0;
    } 
