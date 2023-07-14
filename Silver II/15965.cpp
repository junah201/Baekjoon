#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int MAX = 50000000;

int main()
{
    ll K;
    cin >> K;
    vector<char> isPrime(MAX, true);

    isPrime[0] = isPrime[1] = false;

    int cnt = 0;

    for (ll i = 2; i < MAX; i++)
        if (isPrime[i])
        {
            cnt++;
            if (cnt == K)
            {
                cout << i << endl;
                break;
            }

            for (ll j = i * i; j < MAX; j += i)
                isPrime[j] = false;
        }

    return 0;
}