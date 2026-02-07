#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, book[1002] = {0};
    cin >> t;
    while (t--)
    {
        memset(book, 0, sizeof(book));
        int n, k;
        ll ans = 0, x;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            ans += x / k;
            book[x % k]++;
        }
        int i = 1, j = k - 1;
        while (i < j)
        {
            while (book[j] && i < j)
            {
                int d = min(book[i], book[j]);
                book[j] -= d;
                book[i] -= d;
                ans += d;
                if (book[i] == 0)
                    i++;
            }
            if (i != j)
            {
                j--;
                if (i + j < k)
                    i++;
            }
        }
        if (i == j)
        {
            ans += book[i] / 2;
        }
        cout << ans << "\n";
    }
    return 0;
}