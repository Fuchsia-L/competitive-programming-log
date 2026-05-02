#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        queue<long long> a, b, c, d;
        for (int i = 1; i <= n; i++)
        {
            long long x;
            cin >> x;
            if (x % 6 == 0)
            {
                a.push(x);
            }
            else if (x % 3 == 0)
            {
                b.push(x);
            }
            else if (x % 2 == 0)
            {
                c.push(x);
            }
            else
            {
                d.push(x);
            }
        }
        while (!a.empty())
        {
            cout << a.front() << " ";
            a.pop();
        }
        while (!b.empty())
        {
            cout << b.front() << " ";
            b.pop();
        }
        while (!d.empty())
        {
            cout << d.front() << " ";
            d.pop();
        }
        while (!c.empty())
        {
            cout << c.front() << " ";
            c.pop();
        }
        cout << "\n";
    }
    system("pause");
    return 0;
}
