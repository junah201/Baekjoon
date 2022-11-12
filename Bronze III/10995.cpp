/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int N;

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N * 2; j++)
        {
            if (i % 2 == j % 2)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}