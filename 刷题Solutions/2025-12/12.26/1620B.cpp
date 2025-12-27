#include <iostream>
using namespace std;
int w, h;
long long find_boundery(int n)
{
    int a, b, x;
    cin >> a;
    for (int i = 1; i <= n - 2; i++)
        cin >> x;
    cin >> b;
    return b - a;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> w >> h;
        long long maxans = 0;
        for (int i = 1; i <= 4; i++)
        {
            int num;
            cin >> num;
            if (i <= 2)
                maxans = max(maxans, h * find_boundery(num));
            else
                maxans = max(maxans, w * find_boundery(num));
        }
        cout << maxans << "\n";
    }
    return 0;
}