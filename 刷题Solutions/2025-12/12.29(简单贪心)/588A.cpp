#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, ans = 0, minn = 111;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int ni, pi;
        cin >> ni >> pi;
        minn = min(minn, pi);
        ans += minn * ni;
    }
    cout << ans;
    return 0;
}