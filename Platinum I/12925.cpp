#include <iostream>
using std::cin;
using std::cout;

int main()
{
    int T;
    cin >> T;
    long long N;
    for (int t = 1; t <= T; t++)
    {
        cin >> N;
        int mat[2][2] = {{3, 5}, {1, 3}};
        int res[2] = {1, 0};
        while (N > 0)
        {
            if (N & 1)
            {
                int temp[2] = {mat[0][0] * res[0] + mat[0][1] * res[1], mat[1][0] * res[0] + mat[1][1] * res[1]};
                res[0] = temp[0] % 1000;
                res[1] = temp[1] % 1000;
            }
            int temp[2][2] = {{mat[0][0] * mat[0][0] + mat[0][1] * mat[1][0], mat[0][0] * mat[0][1] + mat[0][1] * mat[1][1]},
                              {mat[1][0] * mat[0][0] + mat[1][1] * mat[1][0], mat[1][0] * mat[0][1] + mat[1][1] * mat[1][1]}};
            mat[0][0] = temp[0][0] % 1000;
            mat[0][1] = temp[0][1] % 1000;
            mat[1][0] = temp[1][0] % 1000;
            mat[1][1] = temp[1][1] % 1000;
            N >>= 1;
        }
        int ans = (res[0] * 2 - 1) % 1000;
        if (ans < 10)
        {
            cout << "Case #" << t << ": 00" << ans << '\n';
        }
        else if (ans < 100)
        {
            cout << "Case #" << t << ": 0" << ans << '\n';
        }
        else
        {
            cout << "Case #" << t << ": " << ans << '\n';
        }
    }
    return 0;
}