#include <bits/stdc++.h>
using namespace std;

char key[22];
char A[102], B[102];

int key_len, A_len, B_len;

long long DP_A[102], DP_B[102];

int main() {
    scanf(" %s", key);
    scanf(" %s", A);
    scanf(" %s", B);

    key_len = strlen(key);
    A_len = strlen(A);
    B_len = strlen(B);

    for(int i=0;i<A_len;i++) {
        if(A[i] == key[0]) DP_A[i]++;
        if(B[i] == key[0]) DP_B[i]++;
    }

    for(int i=1;i<key_len;i++) {
        long long A_cnt = 0, B_cnt = 0;
        for(int j=0;j<A_len;j++) {
            if(A[j] == key[i - 1]) B_cnt += DP_A[j];
            if(B[j] == key[i - 1]) A_cnt += DP_B[j];
        }
        for(int j=A_len - 1;j>=0;j--) {
            if(A[j] == key[i - 1]) B_cnt -= DP_A[j];
            if(B[j] == key[i - 1]) A_cnt -= DP_B[j];
            
            if(A[j] == key[i]) DP_A[j] = A_cnt;
            if(B[j] == key[i]) DP_B[j] = B_cnt;
        }
    }

    long long ans = 0;
    for(int i=0;i<A_len;i++) {
        if(A[i] == key[key_len - 1]) ans += DP_A[i];
        if(B[i] == key[key_len - 1]) ans += DP_B[i];
    }

    printf("%lld", ans);
    return 0;
}