#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, minn = 0, ans = 1, con = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x >= minn)
        {
            minn = x;
            con++;
            ans = max(ans, con);
            // cout << i << " ,con=" << con << endl; /////////////////////////////////////////////////
        }
        else
        {
            ans = max(ans, con);
            con = 1;
            minn = x;
        }
    }
    cout << ans;
    return 0;
}