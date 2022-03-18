// 17219 비밀번호 찾기
//  https://www.acmicpc.net/source/40647307

#include <bits/stdc++.h>
using namespace std;

int N, M;
string site, passward;
vector<pair<string, string>> v;

string bs(string key)
{
    int low = 0;
    int high = (int)v.size() - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (v[mid].first == key)
            return v[mid].second;
        else if (v[mid].first > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return v[mid].second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    while (N--)
    {
        cin >> site >> passward;
        v.emplace_back(site, passward);
    }

    sort(v.begin(), v.end());

    while (M--)
    {
        cin >> site;
        cout << bs(site) << "\n";
    }
    return 0;
}