#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        bool f1 = false, f2 = false;
        long long sum = 0;
        cin >> n >> m;
        priority_queue<long long> p1, p2;
        for (int i = 1; i <= n; i++)
        {
            long long x;
            cin >> x;
            if (i % 2 == 1)
            {
                p1.push(x);
            }
            else
            {
                p2.push(x);
            }
            sum += x;
        }
        for (int i = 1; i <= m; i++)
        {
            int x;
            long long v;
            cin >> x;
            if (x % 2 == 1)
            {
                v = p1.top();
                if (v < 0 && f1)
                    v = 0;
                f1 = 1;
                p1.pop();
                p1.push(0);
            }
            else
            {
                v = p2.top();
                if (v < 0 && f2)
                    v = 0;
                f2 = 1;
                p2.pop();
                p2.push(0);
            }
            sum -= v;
        }
        cout << sum << "\n\n";
    }
    system("pause");
    return 0;
}