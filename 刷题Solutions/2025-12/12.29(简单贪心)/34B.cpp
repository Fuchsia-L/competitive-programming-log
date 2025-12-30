#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, ans = 0, m = 0;
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<>> a;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a.push(x);
    }
    while (m > 0 && !a.empty())
    {
        int top = a.top();
        a.pop();
        if (top >= 0)
            break;
        ans -= top;
        m--;
    }
    cout << ans;
    return 0;
}