/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;

struct xy
{
    double x;
    double y;
    bool x_start;
    bool y_start;
    int idx;
};

struct compare
{
    bool operator()(const xy &a, const xy &b)
    {
        if (a.x != b.x)
            return a.x > b.x;
        if (a.y != b.y)
            return a.y > b.y;
        return a.idx > b.idx;
    }
};

//           x,  y,   x start, y start,  point index
priority_queue<xy, vector<xy>, compare> points;

xy points_top()
{
    if (points.empty())
    {
        xy tmp;
        tmp.idx = -1;
        return tmp;
    }

    xy first = points.top();
    points.pop();

    if (!points.empty())
    {
        xy second = points.top();

        if (first.x == second.x && first.y == second.y && first.x_start != second.x_start && first.y_start == second.y_start)
        {
            points.pop();
            return points_top();
        }
    }
    return first;
}

double solution(vector<vector<double>> rectangles)
{
    double answer = 0;

    for (int i = 0; i < rectangles.size(); i++)
    {
        double sx = rectangles[i][0];
        double sy = rectangles[i][1];
        double ex = rectangles[i][2];
        double ey = rectangles[i][3];
        // top start
        points.push({sx, sy, true, true, i});
        // bottom start
        points.push({sx, ey, true, false, i});
        // top end
        points.push({ex, sy, false, true, i});
        // bottom end
        points.push({ex, ey, false, false, i});
    }

    while (!points.empty())
    {
        // same_x에 값을 넣기
        vector<xy> same_x;
        same_x.push_back(points_top());

        // 종료 조건
        if (points.empty() || same_x.front().idx == -1)
            break;

        double now_x = same_x[0].x;

        while (!points.empty())
        {
            if (points.top().x != now_x)
                break;
            same_x.push_back(points_top());
        }

        // 가로 dis 미리 구해두기
        double next_x = -1;
        if (!points.empty())
            next_x = points.top().x;

        // 다음 x로 현재 x값 이동 시키기
        if (next_x != -1)
        {
            for (int i = 0; i < same_x.size(); i++)
            {
                xy tmp = same_x[i];
                tmp.x = next_x;
                points.push(tmp);
            }
        }

        // 세로 dis들을 스택을 이용해서 구하기
        stack<xy> s;
        vector<double> dis;

        for (int i = 0; i < same_x.size(); i++)
        {
            xy a = same_x[i];
            if (!s.empty() && s.top().y_start == true && a.y_start == false)
            {
                if (s.size() == 1)
                    dis.push_back(a.y - s.top().y);
                s.pop();
            }
            else
                s.push(a);
        }

        // 구한 dis를 이용해서 넓이 더하기
        for (auto i : dis)
        {
            answer += i * (next_x - now_x);
        }
    }

    return answer;
}

int main()
{
    int N;
    scanf("%d", &N);
    vector<vector<double>> v;
    while (N--)
    {
        vector<double> tmp;
        double a, b, c, d;
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
        tmp.push_back(a);
        tmp.push_back(b);
        tmp.push_back(a + c);
        tmp.push_back(b + d);
        v.push_back(tmp);
    }
    double answer = solution(v);
    if (answer == (int)answer)
        printf("%.0lf", answer);
    else
        printf("%.2lf", answer);
    return 0;
}