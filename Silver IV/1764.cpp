// 1764 듣보잡
// https://www.acmicpc.net/source/40639129

#include <bits/stdc++.h>
using namespace std;

int N, M;
string input;
set<string> s;
vector<string> v;

int main()
{
    scanf("%d %d", &N, &M);
    while (N--)
    {
        getline(cin, input);
        s.emplace(input);
    }
    while (M--)
    {
        getline(cin, input);
        auto check = s.emplace(input);
        if (!check.second)
            v.push_back(input);
    }
    sort(v.begin(), v.end());
    printf("%lu\n", v.size());
    for (auto i : v)
        cout << i << "\n";
    return 0;
}