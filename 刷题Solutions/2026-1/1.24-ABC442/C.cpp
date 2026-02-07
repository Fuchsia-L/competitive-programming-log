#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int book[200009] = {0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        book[a]++;
        book[b]++;
    }
    for (int i = 1; i <= n; i++)
    {
        ll k = n - book[i] - 1;
        if (k >= 3)
        {
            cout << k * (k - 1) * (k - 2) / 6 << " ";
        }
        else
            cout << "0 ";
    }
    return 0;
}