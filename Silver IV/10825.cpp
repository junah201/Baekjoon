/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INF LONG_LONG_MAX

signed main()
{
    int N;
    cin >> N;

    vector<tuple<int, int, int, string>> A(N);

    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        string d;
        cin >> d >> a >> b >> c;

        A[i] = {-a, b, -c, d};
    }

    sort(A.begin(), A.end());

    for (auto [a, b, c, s] : A)
    {
        cout << s << "\n";
    }

    return 0;
}