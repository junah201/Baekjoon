/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int N, inp[5], sum;

int main()
{
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &inp[i]);
        sum += inp[i];
    }

    sort(inp, inp + 5);

    printf("%d\n%d", sum / 5, inp[2]);

    return 0;
}