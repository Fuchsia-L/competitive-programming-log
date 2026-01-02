#include <iostream>
using namespace std;
const int maxn = 1e5 + 2;
long long a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int ans = 1;
    int ind = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > a[i - 1])
            ind++;
        else
        {
            ind = 1;
        }
        // cout << i << " ,ans=" << ans << " ind=" << ind << endl;
        ans = max(ans, ind);
    }
    cout << ans << "\n";
    return 0;
}