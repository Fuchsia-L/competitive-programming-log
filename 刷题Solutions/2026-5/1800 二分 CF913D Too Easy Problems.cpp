#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, long long> a, pair<int, long long> b)
{
    return a.second < b.second;
}
int main()
{
    int n;
    long long t;
    cin >> n >> t;
    vector<pair<int, long long>> timu(n + 1);
    vector<int> pos(n + 1, 0), idx(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> timu[i].first >> timu[i].second;
        pos[timu[i].first]++;
        idx[i] = i;
    }
    int head = 0, us = 0;
    for (int i = 1; i <= n; i++)
    {
        pos[i] += pos[i - 1];
    }
    sort(idx.begin() + 1, idx.end(), [&](int a, int b)
         { return timu[a].first < timu[b].first; });
    int ans, l = 1, r = n, mid, ansk = 0;
    priority_queue<pair<long long, int>> pq;
    while (l <= r)
    {
        sort(idx.begin() + 1, idx.end(), [&](int a, int b)
             { return timu[a].first < timu[b].first; });
        mid = (l + r) / 2;
        int p = pos[mid - 1] + 1;
        // cout << "mid = " << mid << " , p = " << p << "\n"; /////////////////
        sort(idx.begin() + p, idx.end(), [&](int a, int b)
             { return cmp(timu[a], timu[b]); });
        bool f = false;

        long long sum = 0;
        for (int cnt = 0; cnt <= mid && cnt + p <= n; cnt++)
        {
            //     cout << "~~" << p << " " << cnt << "\n";
            sum += timu[idx[p + cnt]].second;
            if (sum > t)
                break;
            if (cnt + 1 == mid)
                f = true;
        }
        if (f)
        {
            ansk = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ansk << "\n"
         << ansk << "\n";
    int p = 0;
    if (ansk > 0)
        p = pos[ansk - 1] + 1;
    sort(idx.begin() + 1, idx.end(), [&](int a, int b)
         { return timu[a].first < timu[b].first; });
    sort(idx.begin() + p, idx.end(), [&](int a, int b)
         { return cmp(timu[a], timu[b]); });
    long long sum = 0;

    for (int now = 0; now < ansk; now++)
    {
        // cout << "~p,now+p" << p << " " << now + p << "\n";
        sum += timu[idx[now + p]].second;
        if (sum > t)
            break;
        cout << idx[now + p] << " ";
    }
    system("pause");
    return 0;
}