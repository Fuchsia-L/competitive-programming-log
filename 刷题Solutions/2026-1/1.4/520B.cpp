#include <iostream>
#include <queue>
using namespace std;

int main()
{
    const int maxn = 1e4 + 2;
    int n, m, book[maxn] = {0}, ans = 0;
    cin >> n >> m;
    if (n >= m)
    {
        cout << n - m << "\n";
        return 0;
    }
    while (m > n)
    {
        if (m % 2 == 0)
            m /= 2;
        else
            m += 1;
        ans++;
    }
    ans += n - m;
    cout << ans << "\n";
    /* 我勒个超时。
    queue<pair<int, int>> a;
    a.push({n, 0});
    while (!a.empty())
    {
        auto now = a.front();
        a.pop();
        if (now.first == m)
        {
            cout << now.second << "\n";
            return 0;
        }
        int x1 = now.first - 1, x2 = now.first * 2;
        if (x1 > 0 && book[x1] == 0)
            a.push({x1, now.second + 1});
        if (x2 > 0 && x2 <= m + 1 && book[x2] == 0)
            a.push({x2, now.second + 1});
    }
    */
    return 0;
}