#include <bits/stdc++.h>
using namespace std;

int N, M, ans = INT_MAX;
vector<pair<int, vector<int>>> sorted_meat;
map<int, int> price_meat;

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0, w, c; i < N; i++)
    {
        scanf("%d %d", &w, &c);
        sorted_meat.emplace_back(c, w);
    }
    sort(sorted_meat.begin(), sorted_meat.end());

    for (int i = 0; i < N; i++)
    {
        auto [c, w] = sorted_meat[i];
        if (price_meat.find(c) == price_meat.end())
        {
            price_meat.emplace(w);
        }
        else
        {
            price_meat[c].emplace_back(w);
        }
    }

    int tmp = 0;
    for (int i = 0; i < N; i++)
    {
        auto [c, w] = meat[i];
        if (i != 0 && meat[i].first == meat[i - 1].first)
            continue;
        if (tmp + w >= M)
        {
            ans = c;
            break;
        }
        tmp += w;
    }
    if (ans)
        printf("%d", ans);
    else
        printf("%d", -1);
}

// https://s.search.naver.com/p/intentblock/search.naver?ac=0&aq=0&bid=SYS-0000000001783649&display=10&fgn_city=&fgn_region=&lgl_lat=37.373382&lgl_long=126.938588&lgl_rcode=02410104&ngn_country=KR&nlu_query=%7B%22v%22%3A%223%22%2C%22intentblock%22%3A%221%22%2C%22qid%22%3A%22%EB%B6%88%EA%B4%91%EC%97%AD%EB%A7%9B%EC%A7%91%22%2C%22abt%22%3A%5B%7B%22eid%22%3A%22SBR1%22%2C%22value%22%3A%7B%22bucket%22%3A%22T2%22%2C%22is_control%22%3Afalse%7D%7D%5D%7D&query=%EB%B6%88%EA%B4%91%EC%97%AD+%EB%A7%9B%EC%A7%91&ssc=tab.itb.all&start=1&where=nx_bridge
// https://s.search.naver.com/p/intentblock/search.naver?ac=0&aq=0&bid=SYS-0000000001754221&display=10&fgn_city=&fgn_region=&lgl_lat=37.373382&lgl_long=126.938588&lgl_rcode=02410104&ngn_country=KR&nlu_query=%7B%22v%22%3A%223%22%2C%22intentblock%22%3A%221%22%2C%22qid%22%3A%22%EB%B6%88%EA%B4%91%EC%97%AD%EB%A7%9B%EC%A7%91%22%2C%22abt%22%3A%5B%7B%22eid%22%3A%22SBR1%22%2C%22value%22%3A%7B%22bucket%22%3A%22T2%22%2C%22is_control%22%3Afalse%7D%7D%5D%7D&query=%EB%B6%88%EA%B4%91%EC%97%AD+%EB%A7%9B%EC%A7%91&ssc=tab.itb.all&start=1&where=nx_bridge