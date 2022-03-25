#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll K, L;

int main()
{
    scanf("%lld %lld", &K, &L);
    for (ll i = 2; i < L; i++)
        if (K % i == 0)
        {
            printf("BAD %lld", i);
            return 0;
        }
    printf("GOOD");
    return 0;
}

/*
이 문제가 C로 풀기 어려운 이유
 : 입력값이 10의 100승임

 10의 100승 >  넘사벽 >> 21억 ㅋㅋㅋ


 이럴 때 필요한게 파이썬

 따라서 int 는 21억까지 밖에 저장이 안되기 때문에
 문자열로 입력받아야 하는데, 문자열 연산은 어려움
 따라서 살짝 큰 수 A+B 같은 느낌의 문제이며

 결론 : 풀지 말자


*/