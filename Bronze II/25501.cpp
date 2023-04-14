/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;

int N;
char inp[1002];
int r_cnt, p_cnt;

int recursion(const char *s, int l, int r)
{
    r_cnt++;
    if (l >= r)
        return 1;
    else if (s[l] != s[r])
        return 0;
    else
        return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char *s)
{
    return recursion(s, 0, strlen(s) - 1);
}

int main()
{
    scanf("%d", &N);
    while (N--)
    {
        scanf(" %s", &inp);
        r_cnt = 0;
        int result = isPalindrome(inp);
        printf("%d %d\n", result, r_cnt);
    }

    return 0;
}