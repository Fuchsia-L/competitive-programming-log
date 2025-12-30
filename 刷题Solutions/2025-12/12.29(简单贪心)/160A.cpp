#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, sum = 0;
    priority_queue<int, vector<int>> a;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        sum += x;
        a.push(x);
    }
    int ans = 0, ind = 0;
    while (ans <= sum)
    {
        ans += a.top();
        sum -= a.top();
        a.pop();
        ind++;
    }

    cout << ind;
    return 0;
}