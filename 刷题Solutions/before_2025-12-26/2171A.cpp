#include <iostream>
using namespace std;
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int ans = 0;
        for (int i = 0; i * 4 <= n; i++)
        {
            if ((n - i * 4) % 2 == 0)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}