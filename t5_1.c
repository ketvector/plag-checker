#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long
 
#ifndef ONLINE_JUDGE
#define gc getchar
#define pc putchar
#else
#define gc getchar_unlocked
#define pc putchar_unlocked
#endif
 
int read_int() {
    char c = gc();
    while((c < '0' || c > '9') && c != '-') c = gc();
    int ret = 0, neg = 0;
    if (c == '-') neg = 1, c = gc();
    while(c >= '0' && c <= '9') {
        ret = 10 * ret + c - 48;
        c = gc();
    }
    return neg ? -ret : ret;
}
 
ll read_ll() {
    char c = gc();
    while((c < '0' || c > '9') && c != '-') c = gc();
    ll ret = 0;
    int neg = 0;
    if (c == '-') neg = 1, c = gc();
    while(c >= '0' && c <= '9') {
        ret = 10 * ret + c - 48;
        c = gc();
    }
    return neg ? -ret : ret;
}
 
#define MOD 1000000007
#define MUL(a, b) ((int)((1ll*(a)*(b))%MOD))
 
int pow_mod(int b, int e) {
    int r = 1;
    while(e) {
        if (e&1)
            r = MUL(r, b);
        e >>= 1;
        b = MUL(b, b);
    }
    return r;
}
 
char B[100000]; int A[100000];
 
int main() {
 
#ifndef ONLINE_JUDGE
    freopen("testcase.in", "r", stdin);
#endif
 
    int T, N, i, j, total, last, m, c;
 
    T = read_int();
    while(T--) {
        N = read_int();
        while((c = gc()) != '0' && c != '1');
        ungetc(c, stdin);
        i = 0;
        while((c = gc()) == '0' || c == '1')
            B[i++] = c-'0';
        for(i=0;i<N;i++)
            A[i] = read_int();
        total = A[N-1] - A[0];
        last = -1;
        for(i=0;i<N;i++) {
            if (B[i]) {
                if (last != -1) {
                    m = 0;
                    for(j=last+1;j<=i;j++)
                        if (m < A[j] - A[j-1])
                            m = A[j] - A[j-1];
                    total -= m;
                }
                last = i;
            }
        }
        if (last == -1)
            puts("-1");
        else
            printf("%d\n", total);
    }
 
    return 0;
}
