#include <bits/stdc++.h>
using namespace std;
vector<long long> node;
int len;

bool check(long long x)
{
    long long first = node[0] + 2 * x, last = node[len - 1] - 2 * x;
    for (int i = 0; i < len; i++)
    {
        if (node[i] > first)
        {
            first = node[i];
            break;
        }
    }
    for (int i = len - 1; i >= 0; i--)
    {
        if (node[i] < last)
        {
            last = node[i];
            break;
        }
    }
    if ((last - first + 1) / 2 > x)
    {
        return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            long long x;
            cin >> x;
            node.push_back(x);
        }
        sort(node.begin(), node.end());
        node.erase(unique(node.begin(), node.end()), node.end());
        len = node.size();
        long long l = 0, r = node[len - 1], mid;
        long long ans = r;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (check(mid))
            {
                r = mid - 1;
                ans = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << ans << "\n";
        node.clear();
    }
    return 0;
}