    #include<stdio.h>
    #define inchar getchar_unlocked
     
    void inIntPos(int *a) 
    {
      int n = 0;
      int ch = inchar();
      while (ch < '0' || ch > '9') ch = inchar();
      while (ch >= '0' && ch <= '9') 
      {
        n = (n << 3) + (n << 1) + (ch & 15);
        ch = inchar();
      }
      *a = n;
    }
     
    int main()
    {
      int t, n, x, i, j, k, len, temp, max_gap, temp_sum;
      char str[100005];
      int coor[2], fl = 0;
    	scanf("%d", &t);
      while(t--){
     
        scanf("%d", &n);
        scanf("%s",str);
     
        i=0;
        temp_sum = 0;
        
        inIntPos(&coor[fl]);
        fl ^= 1;
        
        while(str[i] == '0'){
          inIntPos(&coor[fl]);
          fl ^= 1;
          i++;
        
          temp_sum += coor[fl^1] - coor[fl];
        }
        len = temp_sum;
        
        while(i<n){
          if(str[i] == '0'){
            max_gap = coor[fl^1] - coor[fl];
            temp_sum = max_gap;
     
            for(j=i+1; j<n; j++){
              inIntPos(&coor[fl]);
              fl ^= 1;
     
              temp = coor[fl^1] - coor[fl];
              temp_sum += temp;
              if(temp > max_gap){
                max_gap = temp;
              }
              if(str[j] == '1'){
                break;
              }
            }
            if(j==n){
              len += temp_sum;
            }
            else{
              len += temp_sum - max_gap;
            }
            i = j;
          }
     
          i++;
          if(i<n){
            inIntPos(&coor[fl]);
            fl ^= 1;
          }
        }
        printf("%d\n", len);
      }
    	return 0;
    } 
