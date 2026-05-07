#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long, long long> &a, pair<long long, long long> &b)
{
    if (a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n + 1, 0);
        vector<pair<long long, long long>> b;
        b.push_back({-1, -1});
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            b.push_back({a[i], i});
            a[i] += a[i - 1];
        }
        sort(b.begin() + 1, b.end(), cmp);
        int left = 1;
        long long sum = 0, remov = 0;
        for (int i = 1; i <= n; i++)
        {
            long long hight = b[i].first, pos = b[i].second;
            if (pos < left)
                continue;
            sum += (a[pos] - a[left - 1]) - hight * (pos - left + 1);
            if (hight != 0)
                remov = max(remov, (long long)(pos - left));
            left = pos + 1;
            // cout << "at pos = " << pos << " , sum,remove = " << sum << " " << remov << "\n";
        }
        cout << sum + remov << "\n";
    }

    // system("pause");
    return 0;
}
