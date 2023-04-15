/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
    scanf("%d", &N);
    vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < N; i++)
        printf("%d\n", A[i]);

    return 0;
}