#include <bits/stdc++.h>
using namespace std;

int N, ans;
int inp[100002], sum[100002];

// 1 2 3 4 5
// 1 3 6 10 15

int get(int start, int end, int other_bee)
{
    int result = 0;
    if (start < end)
        result = sum[end] - sum[start];
    else
        result = sum[start - 1] - sum[end - 1];
    if ((other_bee > start && other_bee < end) || (other_bee < start && other_bee > end))
        result -= inp[other_bee];
    return result;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &inp[i]);

    sum[0] = inp[0];
    for (int i = 1; i < N; i++)
        sum[i] = sum[i - 1] + inp[i];
    // 벌통이 오른쪽 끝
    for (int i = 1; i < N - 1; i++)
        ans = max(ans, get(0, N - 1, i) + get(i, N - 1, 0));

    // 벌통이 왼쪽 끝
    for (int i = 1; i < N - 1; i++)
    {
        ans = max(ans, get(N - 1, 0, i) + get(i, 0, N - 1));
    }
    // 가운데
    for (int i = 1; i < N - 1; i++)
        ans = max(ans, get(0, i, N - 1) + get(N - 1, i, 0));
    printf("%d", ans);
}

/*
시작할 수 있는 분기
 1. 최소값 - 총 2개
 2. 가장 옆에 있는 값 - 총 4개

벌꿀의 위치
 1. 가운데
 2. 가장 옆에 있는 값
*/