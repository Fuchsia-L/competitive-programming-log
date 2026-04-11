#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a = 1, b = 2, c, d, k;
        cin >> n;
        int num = 1, f = 1;
        while ((num <= n - 1) && f)
        {
            cout << "? " << a << " " << b << endl;
            cout.flush();
            cin >> k;
            if (k == 1)
            {
                cout << "! " << a << endl;
                cout.flush();
                f = 0;
            }
            num++;
            a += 2;
            b += 2;
        }
        if (f)
        {
            int k1, k2;
            cout << "? " << 1 << " " << a << endl;
            cout.flush();
            cin >> k1;
            cout << "? " << 2 << " " << a << endl;
            cout.flush();
            cin >> k2;
            if ((k1 == 1) || (k2 == 1))
            {
                cout << "! " << a << endl;
            }
            else
                cout << "! " << b << endl;
            cout.flush();
        }
    }
    return 0;
}