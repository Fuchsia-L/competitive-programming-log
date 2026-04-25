#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        map<ll, ll> m;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            m[x]++;
        }
        for (int i = 1; i <= n; i++)
        {
            int y;
            cin >> y;
        }
        int len = m.size();
        vector<pair<ll, ll>> node;
        vector<ll> v1(len + 1, 0);
        vector<ll> v2(len + 1, 0);
        k++;
        for (auto x : m)
        {
            node.push_back({x.first, x.second});
        }
        for (int i = 1; i < len; i++)
        {
            node[i].second += node[i - 1].second;
        }
        ll head = 0, sum = 0;
        for (int i = 0; i < len; i++)
        {
            while (node[i].first - node[head].first + 1 > k)
                head++;
            sum = max(sum, node[i].second - (head > 0 ? node[head - 1].second : 0));
            v1[i] = sum;
        }
        head = len - 1;
        sum = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            while (node[head].first - node[i].first + 1 > k)
                head--;
            sum = max(sum, node[head].second - (i > 0 ? node[i - 1].second : 0));
            v2[i] = sum;
        }
        ll ans = 0;
        for (int i = 0; i < len; i++)
        {
            ans = max(ans, v1[i] + v2[i + 1]);
        }
        cout << ans << "\n\n";
    }
    system("pause");
    return 0;
}
