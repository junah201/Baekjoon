/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int T, N, max_num;
vector<int> DP;

int get_xor(int n)
{
    int mod = n % 4;

    switch (mod)
    {
    case 0:
        return n;
    case 1:
        return 1;
    case 2:
        return n + 1;
    case 3:
        return 0;
    }
    return -1;
}

int main()
{
    scanf("%d", &T);
    for (int i = 0, S, F; i < T; i++)
    {
        scanf("%d %d", &S, &F);
        printf("%d\n", get_xor(S - 1) ^ get_xor(F));
    }

    return 0;
}