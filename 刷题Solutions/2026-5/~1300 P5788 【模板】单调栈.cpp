#include <bits/stdc++.h>
using namespace std;

int main()
{
    //   ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, cnt = 0;
    cin >> n;
    stack<pair<int, int>> s;
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (s.empty())
        {
            s.push({x, i});
        }
        else
        {
            while (!s.empty() && s.top().first < x)
            {
                ans[s.top().second] = i;
                s.pop();
            }
            s.push({x, i});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    system("pause");
    return 0;
}
