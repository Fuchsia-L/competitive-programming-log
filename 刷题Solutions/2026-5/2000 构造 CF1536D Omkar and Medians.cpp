#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll INF = 1e10;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        bool f = true;
        cin >> n;
        set<ll> s;
        s.insert(INF);
        s.insert(-INF);
        ll pre_val, now_val;
        cin >> pre_val;
        s.insert(pre_val);
        for (int i = 2; i <= n; i++)
        {
            cin >> now_val;
            s.insert(now_val);
            auto p = s.lower_bound(now_val);
            if (((*prev(p)) != pre_val) && ((*next(p)) != pre_val) && now_val != pre_val)
            {
                f = false;
            }
            pre_val = now_val;
        }
        if (f)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    // system("pause"); ////////////
    return 0;
}