/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    printf(__format);
#endif
}

int N;
char str[52];

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf(" %[^\n]", &str);
        printf("%d. %s\n", i, str);
    }

    return 0;
}