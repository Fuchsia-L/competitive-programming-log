#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        vector<bool> used(n + 1, false);
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (used[i] || p[i] == i || (p[p[i]] == i))
            {
                continue;
            }

            int sum = 0;
            int now = i, next = p[i];
            while (!used[next])
            {
                sum++;
                used[now] = true;
                now = next;
                next = p[next];
                // cout << now << " -> " << next << "\n";
            }
            sum++;
            // cout << "sum = " << sum << "\n\n";
            ans = ans + sum / 2 + sum % 2 - 1;
        }
        cout << ans << "\n";
    }
    system("pause");
    return 0;
}
