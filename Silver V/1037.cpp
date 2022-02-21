//1037  약수

#include <stdio.h>
#include <algorithm>

using namespace std;

long int N,num;
long int input[50] = {0,};
int check=0;
int check2=0;
int idx=0;

int main() {
    scanf("%ld",&N);
    for(int i=0;i<N;i++) scanf("%ld",&input[i]);
    sort(input,input+N);
    if(N==1) printf("%ld",input[0]*input[0]);
    else if(N%2==1) printf("%ld",input[N/2]*input[N/2]);
    else if(N%2==0) printf("%ld",input[N/2-1]*input[N/2]);
    return 0;
}

/*
#include <stdio.h>
#include <algorithm>

using namespace std;

long int N,num;
long int input[50] = {0,};
int check=0;
int check2=0;
int idx=0;

int main() {
    scanf("%ld",&N);
    for(int i=0;i<N;i++) scanf("%ld",&input[i]);
    sort(input,input+N);
    for(int i=2;i<10;i++) {
        num = input[N-1]*i;
        //입력받은 배열의 모든 요소로 num을 나누었을때 모두 나누어 떨어지면
        for(int j=0;j<N;j++) {
            check=1;
            //나누어 떨어지지 않으면 check을 0으로 만들고 브레이크
            if(num%input[j]!=0) {
                check=0;
                break;
            }
        }
        //모든 요소로 나누어 떨어져서 check가 1이면
        if(check==1){
            //num의 모든 약수가 배열과 일치하면
            idx = 0;
            for(int k=2;k<num-1;k++) {
                check2 = 1;
                if(num%k==0) {
                    if(input[idx++]!=k) {
                        check2=0;
                        break;
                    }
                }
            }
            if(check2==1) {
                printf("%ld\n",num);
                break;
            }
        }
    }
    return 0;
}
*/