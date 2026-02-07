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
        int n, id, f = 0;
        long long maxn = -1;
        cin >> n;
        vector<long long> now(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> now[i];
            if (maxn < now[i])
            {
                maxn = now[i];
                id = i;
                f = 1;
            }
            else if (maxn == now[i])
            {
                f++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (now[i] == maxn && f % 2)
            {
                cout << "1";
            }
            else
                cout << "0";
        }
        cout << "\n";
    }
    return 0;
}
