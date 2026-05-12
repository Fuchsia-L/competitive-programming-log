#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    int l = 1, r = n, mid, pos, x; // cout << "init -\n"; //////////////
    cout << "? " << 1 << " " << n << endl;
    cin >> pos;
    bool f = false; // f在左边，true
    if (pos == 1)
    {
        f = true;
        l = 2;
    }
    else if (pos == n)
    {
        r = n - 1;
    }
    else
    {
        cout << "? " << pos << " " << n << endl;
        cin >> x;
        if (x == pos)
        {
            f = true;
            l = pos + 1;
        }
        else
        {
            r = pos - 1;
        }
    }
    int ans;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (f)
        {
            cout << "? " << pos << " " << mid << endl;
            cin >> x;
            if (x == pos)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        else
        {
            cout << "? " << mid << " " << pos << endl;
            cin >> x;
            if (x == pos)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        // if (l == r)
        // {
        //     ans = l;
        // }
    }
    cout << "! " << ans << endl;
    system("pause");
    return 0;
}