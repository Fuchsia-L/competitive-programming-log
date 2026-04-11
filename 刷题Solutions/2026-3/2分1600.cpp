#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = 0;
        cin >> n;
        vector<int> child(n + 1);
        for (int i = 2; i <= n; i++)
        {
            int x;
            cin >> x;
            child[x]++;
        }
        child[0] = 1;
        sort(child.begin(), child.end());
        int d = 0, numleft = -1;
        vector<int> left;
        for (int i = 1; i <= n; i++)
        {
            if (!child[i])
            {
                continue;
            }
            if (child[i - 1] == 0)
            {
                ans += (n - i + 1);
                d = i - 1;
            }
            if (i - d < child[i])
            {
                left.push_back(child[i] - (i - d));
                numleft++;
            }
        }
        if (numleft != -1)
        {

            sort(left.begin(), left.end());

            // 二分找边界。
            //
            int l = 0, r = left[numleft], amid;
            while (l <= r)
            {
                int mid = (l + r) / 2, sum = 0;
                for (int i = upper_bound(left.begin(), left.end(), mid) - left.begin(); i <= numleft; i++)
                    sum = sum + left[i] - mid;
                if (mid >= sum)
                {
                    r = mid - 1;
                    amid = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            ans += amid;
        }
        cout << ans << "\n";
    }
    system("pause");
    return 0;
}