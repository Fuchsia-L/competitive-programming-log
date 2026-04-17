#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        vector<pair<int, int>> sum(n + 1);
        vector<vector<int>> p(n + 1);
        vector<bool> used(n + 1, false);
        for (int i = 1; i <= n; i++)
            sum[i] = {i, 0};
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            int aa = a[i];
            while (aa > n)
                aa /= 2;
            while (aa >= 1)
            {
                p[aa].push_back(i);
                sum[aa] = {aa, sum[aa].second + 1};
                aa /= 2;
            }
        }
        sort(sum.begin() + 1, sum.end(), cmp);
        vector<int> order(n + 1);
        iota(order.begin(), order.end(), 1);
        sort(order.begin() + 1, order.end(), [&](int a, int b)
             { return p[a] < p[b]; });
        bool ff = true;
        for (int i = 1; i <= n && ff; i++)
        {
            int now = sum[i].first;
            bool f = true;
            for (int idx : p[now])
            {
                if (!used[idx])
                {
                    used[idx] = true;
                    f = false;
                    break;
                }
            }
            if (f)
                ff = false;
        }
        if (ff)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }

    return 0;
}