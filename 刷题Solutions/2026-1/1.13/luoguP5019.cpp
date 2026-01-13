#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;
    vector<int> v;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    queue<pair<int, int>> q;
    q.push({1, n});
    while (!q.empty())
    {
        ans++;
        auto now = q.front();
        q.pop();
        int l = now.first, r = now.second;
        int il = l, ir;
        // cout << "l=" << l << "---r=" << r << "\n";
        while (l <= r)
        {
            ir = l;
            v[l]--;
            if (v[l] == 0)
            {
                if (il != ir)
                {
                    q.push({il, ir - 1});
                }
                il = ir + 1;
            }
            else if (l == r)
            {
                q.push({il, ir});
            }
            l++;
        }
    }
    cout << ans << "\n";
    return 0;
}