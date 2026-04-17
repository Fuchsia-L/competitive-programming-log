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
        vector<pair<int, int>> p(n + 2);
        vector<bool> used(n + 3, false);
        set<int> s;
        int now = 0, idx = 0;
        bool f = true;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if (x != now)
            {
                idx++;
                now = x;
                p[idx] = {i, x}; // position , value
                used[x] = true;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (!used[i])
            {
                s.insert(i);
            }
        }
        p[idx + 1] = {n + 1, n + 1};
        int idx2 = 1;
        for (int i = 1; i <= idx; i++)
        {
            cout << p[i].second << " ";
            for (int j = p[i].first + 1; j < p[i + 1].first; j++)
            {
                while (used[idx2])
                    idx2++;
                cout << idx2 << " ";
                idx2++;
            }
        }
        cout << "\n";
        for (int i = 1; i <= idx; i++)
        {
            cout << p[i].second << " ";
            for (int j = p[i].first + 1; j < p[i + 1].first; j++)
            {
                auto idx22 = s.lower_bound(p[i].second);
                idx22--;
                cout << *idx22 << " ";
                s.erase(idx22);
            }
        }
        cout << "\n";
    }
    return 0;
}
