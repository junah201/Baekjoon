#include <stdio.h>
#include <queue>

using namespace std;

int fmap[200][200];
int smap[200][200];
deque<int> sx;
deque<int> sy;
deque<int> ti;
deque<char> ai;

int N, S, x, y, t1, t2, time, ang = 90;

int main()
{
    scanf("%d", &N);
    scanf("%d", &S);
    for (int i = 0; i < S; i++)
    {
        scanf("%d %d", &x, &y);
        smap[x][y] = 2;
    }
    scanf("%d", &S);
    for (int i = 0; i < S; i++)
    {
        scanf("%d %c", &t1, &t2);
        ti.push_back(t1);
        ai.push_back(t2);
    }
    sx.push_back(1);
    sy.push_back(1);
    smap[1][1] = 1;
    time = 1;
    while (1)
    {
        //이동
        if (ang == 0)
        {
            sx.push_front(sx.front());
            sy.push_front(sy.front() - 1);
        }
        else if (ang == 90)
        {
            sx.push_front(sx.front() + 1);
            sy.push_front(sy.front());
        }
        else if (ang == 180)
        {
            sx.push_front(sx.front());
            sy.push_front(sy.front() + 1);
        }
        else if (ang == 270)
        {
            sx.push_front(sx.front() - 1);
            sy.push_front(sy.front());
        }

        //꼬리 사망
        if (smap[sy.front()][sx.front()] == 1)
            break;
        //열매 먹기
        if (smap[sy.front()][sx.front()] != 2)
        {
            smap[sy.back()][sx.back()] = 0;
            sx.pop_back();
            sy.pop_back();
        }
        //꼬리 사망
        if (smap[sy.front()][sx.front()] == 1)
            break;
        else
            smap[sy.front()][sx.front()] = 1;
        //벽 사망
        if (sx.front() > N || sy.front() > N)
            break;
        else if (sx.front() == 0 || sy.front() == 0)
            break;
        //각도 변경
        if (!ti.empty() && time == ti.front())
        {
            if (ai.front() == 'D')
                ang += 90;
            else if (ai.front() == 'L')
                ang -= 90;
            if (ang >= 360)
                ang -= 360;
            else if (ang < 0)
                ang += 360;
            ti.pop_front();
            ai.pop_front();
        }
        time++;
    }
    printf("%d", time);
    return 0;
}