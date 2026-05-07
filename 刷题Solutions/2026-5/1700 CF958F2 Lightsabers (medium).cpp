#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> cnt_have(m + 1, 0);
    vector<int> permu(n + 1);
    vector<int> cnt_target(m + 1, 0);
    vector<int> cnt_window(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> permu[i];
        cnt_have[permu[i]]++;
    }
    bool f = false;
    for (int i = 1; i <= m; i++)
    {
        cin >> cnt_target[i];
        if (cnt_target[i] > cnt_have[i])
            f = true;
    }
    if (f)
    {
        cout << -1;
        return 0;
    }
    cnt_window = cnt_have;
    int r = 1, l = 1;
    long long ans;
    for (r = n; r >= 1; r--)
    {
        int now = permu[r];
        cnt_window[now]--;
        if (cnt_target[now] > cnt_window[now])
        {
            cnt_window[now]++;
            break;
        }
    }
    long long diff = 0;
    for (int i = 1; i <= m; i++)
    {
        diff += cnt_window[i] - cnt_target[i];
    }
    while (cnt_window[permu[l]] > cnt_target[permu[l]] && l <= r)
    {
        diff--;
        cnt_window[permu[l]]--;
        l++;
    }
    ans = diff;
    for (r = r + 1; r <= n; r++)
    {
        diff++;
        cnt_window[permu[r]]++;
        while (cnt_window[permu[l]] > cnt_target[permu[l]] && l <= r)
        {
            diff--;
            cnt_window[permu[l]]--;
            l++;
        }
        ans = min(ans, diff);
        // cout << l << "~" << r << " , diff =" << diff << "\n";
    }
    ans = max((long long)0, ans);
    cout << ans << "\n";
    system("pause");
    return 0;
}

/*

9 3
3 3 1 2 2 1 3 1 1
3 1 1

5 4
1 2 3 4 1
1 2 1 1 1
*/