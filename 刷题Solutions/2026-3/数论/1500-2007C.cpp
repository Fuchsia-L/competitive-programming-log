#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll a, b, c;
        cin >> n >> a >> b;
        c = gcd(a, b);
        vector<ll> v;
        for (int i = 1; i <= n; i++)
        {
            ll x;
            cin >> x;
            v.push_back(x % c);
        }
        sort(v.begin(), v.end());
        ll rans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            rans = max(v[i + 1] - v[i], rans);
        }
        rans = max(c + v[0] - v[n - 1], rans);
        cout << c - rans << "\n";
    }
    return 0;
}

/*

锚点：对数组元素任意次 +a 或 +b，最小化极差
卡点：1. xa+yb 能凑出的数 ≡ 0 (mod gcd(a,b))，所以每个元素 mod g 是不变量
      2. 余数在 mod g 意义下是"环形"的，最小极差 = g - 最大间隙
突破：把余数想象成圆上的点，在最大空隙处"剪开"展成线段
模式：多个数各自做 +a/+b 操作 → 看 gcd 不变量 → 环上贪心
*/