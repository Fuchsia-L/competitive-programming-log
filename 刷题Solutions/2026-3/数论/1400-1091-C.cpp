#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    priority_queue<ll> k;
    cin >> n;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            k.push(i);
            if (i != n / i)
                k.push(n / i);
        }
    }
    priority_queue<ll, vector<ll>, greater<>> ans;
    while (!k.empty())
    {
        ll p = k.top(), sum = 1;
        ll c = n / p;
        k.pop();
        sum = n * (n + 1) / 2;
        sum = (sum - (p - 1) * p / 2 * c) / p;
        ans.push(sum);
    }
    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
    return 0;
}