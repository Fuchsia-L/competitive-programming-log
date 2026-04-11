#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1), b(n + 1), book(200009, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (i > n - k && i <= k)
                book[a[i]] = 1;
        }
        int f = 1;
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
            if (i <= n - k || i > k)
            {
                if (b[i] != -1 && b[i] != a[i])
                {
                    f = 0;
                }
            }
            else
            {
                if (b[i] != -1)
                {
                    if (book[b[i]] == 1)
                    {
                        book[b[i]]++;
                        continue;
                    }
                    f = 0;
                }
            }
        }

        if (f)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}