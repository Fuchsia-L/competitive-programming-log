#include <bits/stdc++.h>
using namespace std;
long long x1 = 1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x;
    cin >> n >> m;
    priority_queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        q.push(x);
    }
    vector<int> v;
    v.resize(n + 2, 0);

    sort(v.begin() + 1, v.begin() + n + 1, greater<int>());
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += x1 * q.top() * v[i];
        q.pop();
    }
    cout << sum << "\n";
}