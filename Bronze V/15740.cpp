#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

char input_A[10002], input_B[10002];
int len_A, len_B;
int minus_A, minus_B;

vector <int> A, B, result;

int main() {
    scanf("%s %s", input_A, input_B);
    len_A = strlen(input_A);
    len_B = strlen(input_B);
    if(A[0] == '-') minus_A = 1;
    if(B[0] == '-') minus_B = 1;
    for(int i=0;i+minus_A<len_A;i++) {
        if(minus_A) A.push_back((A[i]-'0')*-1);
        else A.push_back((A[i]-'0')*1);
    }
    
    for(int i=0;i+minus_B<len_B;i++) {
        if(minus_B) B.push_back((B[i]-'0')*-1);
        else B.push_back((B[i]-'0')*1);
    }

    for(auto i : A) printf("%d ", i);
    printf("\n\n");
    for(auto i : B) printf("%d ", i);
    printf("1");
    return 0;
}