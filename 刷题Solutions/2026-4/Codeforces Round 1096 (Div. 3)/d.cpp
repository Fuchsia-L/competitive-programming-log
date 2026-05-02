#include <bits/stdc++.h>
using namespace std;
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x0 = 0, y0 = 0;
        cin >> n;
        vector<int> a(n * 2 + 1);
        for (int i = 1; i <= 2 * n; i++)
        {
            cin >> a[i];
            if (a[i] == 0)
            {
                if (x0 == 0)
                    x0 = i;
                else
                    y0 = i;
            }
        }
        int l, r, ans = 0, final = 0;
        vector<int> book(n + 1, 0);
        l = x0, r = x0;
        while (l >= 1 && r <= 2 * n && (a[l] == a[r]))
        {
            book[a[l]] = 1;
            l--;
            r++;
        }
        for (int i = 0; i <= n && book[i]; i++)
        {
            ans = i;
        }
        final = max(final, ans + 1);

        book.assign(n + 1, 0);
        l = y0, r = y0;
        while (l >= 1 && r <= 2 * n && (a[l] == a[r]))
        {
            book[a[l]] = 1;
            l--;
            r++;
        }
        for (int i = 0; i <= n && book[i]; i++)
        {
            ans = i;
        }
        final = max(final, ans + 1);

        book.assign(n + 1, 0);
        l = (y0 + x0) / 2, r = (x0 + y0 + 1) / 2;
        while (l >= 1 && r <= 2 * n && (a[l] == a[r]))
        {
            book[a[l]] = 1;
            l--;
            r++;
        }
        for (int i = 0; i <= n && book[i]; i++)
        {
            ans = i;
        }
        final = max(final, ans + 1);
        cout << final << "\n\n\n";
    }
    system("pause");
    return 0;
}
