// 10610  30

#include <bits/stdc++.h>
using namespace std;

char N[100002];
vector<int> v;
int len, sum, chk = 0;

int main()
{
    scanf("%s", &N);
    len = strlen(N);

    for (int i = 0; i < len; i++)
    {
        v.push_back(N[i] - '0');
        sum += N[i] - '0';
        if (N[i] == '0')
            chk = 1;
    }
    if (sum % 3 || chk == 0)
    {
        printf("-1");
        return 0;
    }

    sort(v.begin(), v.end(), greater<int>());

    for (auto i : v)
        printf("%d", i);

    return 0;
}