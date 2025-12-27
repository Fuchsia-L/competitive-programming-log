#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int find_near_sqrt(int n)
{
    int x = int(sqrt(n));
    if (x * x < n)
        x++;
    // cout << "when n = " << n << " , x=" << x << "\n"; ////////////////////////////////////
    return x;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ans;
        ans.resize(n + 2);
        for (int i = n - 1; i >= 0; i--)
        {
            // cout << " i =  " << i << "\n"; //////////////////////////////
            int s = find_near_sqrt(i);
            int left = s * s - i;
            // cout << "left will be" << left << " " << s * s - n << " s=" << s << " n=" << n << "\n";
            for (int j = left; j <= i; j++)
                ans[j] = s * s - j;
            i = left;
        }
        for (int j = 0; j < n; j++)
        {
            cout << ans[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}