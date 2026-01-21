#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll leftt[200009], rightt[200009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        ll x;
        cin >> n >> m >> k;
        memset(leftt, 0, sizeof(leftt));
        memset(rightt, 0, sizeof(rightt));
        vector<ll> r, ci;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            r.push_back(x);
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> x;
            ci.push_back(x);
        }
        sort(r.begin(), r.end());
        sort(ci.begin(), ci.end());
        for (int robot : r)
        {
            auto index = lower_bound(ci.begin(), ci.end(), robot);
            if (index != ci.end())
            {
                ll len = (*index) - robot;
                rightt[len]++;
            }
            if (index != ci.begin())
            {
                index--;
                ll len = robot - (*index);
                leftt[len]++;
            }
        }
        string s;
        cin >> s;
        ll pos = 0, rem = n;
        for (int i = 0; i < k; i++)
        {
            if (s[i] == 'R')
                pos++;
            else
                pos--;
            if (pos > 0)
            {
                rem -= rightt[pos];
                rightt[pos] = 0;
            }
            else
            {
                rem -= leftt[-pos];
                leftt[-pos] = 0;
            }
            cout << rem << " ";
        }
        cout << "\n";
    }
    return 0;
}