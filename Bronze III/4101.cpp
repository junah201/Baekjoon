#include <bits/stdc++.h>
using namespace std;

int a, b;

int main()
{
    while (1)
    {
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0)
            return 0;
        if (a > b)
            printf("Yes\n");
        else
            pritnf("No\n");
    }
}