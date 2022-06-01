#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
string name;
set<string> s;

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        cin >> name;
        s.insert(name);
    }
    for (int i = 0; i < M; i++)
    {
        cin >> name;
        ans += s.count(name);
    }
    cout << ans;
    return 0;
}