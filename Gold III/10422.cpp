/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int T, N;
unsigned long long DP[5002] = {
    0,
};

unsigned long long f(int idx)
{
    if (idx <= 1)
        return DP[1];

    if (DP[idx])
        return DP[idx];

    unsigned long long result = 0;

    for (int i = 1; i < idx; i++)
    {
        result += (f(idx - i) % mod) * (f(i - 1) % mod);
        result = result % mod;
    }
    result += f(idx - 1) % mod;
    DP[idx] = result % mod;
    return DP[idx];
}

int main()
{
    scanf("%d", &T);

    DP[1] = 1;

    for (int i = 1; i < 100; i++)
    {
        printf("%d\n", f(i));
    }

    while (T--)
    {
        scanf("%d", &N);
        if (N % 2 == 1)
            printf("0\n");
        else
        {
            printf("%llu\n", f(N / 2));
        }
    }

    return 0;
}

/*

1 2 5 14 42 132 429 1430 4862 16796 58786
1 1 2 5

*/

/*
f(1) = 1
f(n) = f(n-1)에서 옆에서 붙인거 + f(n-1)
     = 시그마 공식 + f(n-1)
     = {sigma f(1) ~ f(n-1)} + f(n-1)

1. 전 값에서 양옆에 덮기 A -> (A)
2. 전 값에서 양옆에 붙이기 A -> A()  ()A

f(n-1) + ()
f(n-2) + (())
f(n-3) + ((()))

( f(n-1) )


홀수면 안되고

n == 1    ->   1개
()

n == 2    ->   2개

()()
(())

n == 3    ->   5개

sigma f(1) ~ f(n-1) + f(n-1)

// f(n-1)
()()()
(())()

// f(n-2)
()(())

// f(n-1)
(()())
((()))

n == 8    ->   7개
()()()()
(())()()
()(())()
(()())()
((()))()

()()(())
(())(())

()((()))

()(()())

(()()())
((())())
(()(()))
((()()))
(((())))

n = 10    ->  11개
()()()()()

(())()()()
()(())()()
()()(())()
()()()(())

(())
(())((()))
((()))(())

((()))()()
()((()))()
()()((()))

(((())))()
()(((())))

((((()))))
규칙

N - 2에서 앞뒤 괄호 붙인거 2개 ()(())
새로운거 하나 ((()))

f(n) =

f(n) = f(n - 2) * 2 + 1 (중복 있음)

1, 3, 7, 15, 31

*/