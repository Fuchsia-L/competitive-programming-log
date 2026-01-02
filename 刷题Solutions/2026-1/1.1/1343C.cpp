#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long a, ans = 0, choose;
        cin >> choose;
        for (int i = 2; i <= n; i++)
        {
            cin >> a;
            if (a * choose < 0) // 用if ((a > 0) != (choose > 0)) 更稳，不会溢出
            {
                ans += choose;
                choose = a;
            }
            else
            {
                choose = max(choose, a);
            }
        }
        ans += choose;
        cout << ans << "\n";
    }
    return 0;
}