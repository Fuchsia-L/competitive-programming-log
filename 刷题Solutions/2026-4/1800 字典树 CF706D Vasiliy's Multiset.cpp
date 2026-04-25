#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int tr[6000006][2][2];
queue<int> tail;
void ins(ll n)
{
    int now = 0;
    for (int i = 30; i >= 0; i--)
    {
        // cout << "i = " << i << " , now = " << now << "\n";
        int d = ((n >> i) & 1);
        if (tr[now][d][0] == 0)
        {
            tr[now][d][0] = tail.front();
            tail.pop();
        }
        tr[now][d][1]++;
        now = tr[now][d][0];
    }
}
void era(ll n)
{
    int now = 0;
    for (int i = 30; i >= 0; i--)
    {
        int d = ((n >> i) & 1);
        int k = now;
        now = tr[now][d][0];
        tr[k][d][1]--;
        if (tr[k][d][1] == 0)
        {
            tail.push(tr[k][d][0]);
            tr[k][d][0] = 0;
        }
    }
}
ll maxx(ll n)
{
    int now = 0;
    ll ans = 0;
    for (int i = 30; i >= 0; i--)
    {
        int d = ((n >> i) & 1);
        if (tr[now][!d][1] != 0)
        {
            ans += ((long long)1 << i);
            now = tr[now][!d][0];
        }
        else
        {
            now = tr[now][d][0];
        }
    }
    return ans;
}
int main()
{
    for (int i = 1; i < 6000006; i++)
    {
        tail.push(i);
    }
    ins(0);
    ll t;
    cin >> t;
    while (t--)
    {
        char c;
        ll num;
        cin >> c >> num;
        if (c == '+')
            ins(num);
        else if (c == '-')
            era(num);
        else
            cout << maxx(num) << "\n";
    }
    system("pause");
    return 0;
}