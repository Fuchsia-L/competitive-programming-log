#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, m, sum = 0;
        cin >> n >> k;
        priority_queue<int, vector<int>> b;
        priority_queue<int, vector<int>, greater<int>> a;
        for (int i = 1; i <= n; i++)
        {
            cin >> m;
            sum += m;
            a.push(m);
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> m;
            b.push(m);
        }
        while (k--)
        {
            if (a.top() < b.top())
            {
                sum -= a.top();
                a.pop();
                a.push(b.top());
                sum += b.top();
                b.pop();
            }
            else
                break;
        }
        cout << sum << "\n";
    }
    // system("pause");
    return 0;
}