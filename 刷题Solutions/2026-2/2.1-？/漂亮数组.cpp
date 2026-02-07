#include <bits/stdc++.h>
using namespace std;
long long ans[200009] = {1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, num2 = 0, k = 0, k2 = 0;
        long long ans_fut = 0, ans_now = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                ans_fut++;
                k++;
            }
            else if (x == 2)
                ans_fut = ans_fut * 2 % 998244353;
            else
            {
                ans_now = (ans_now + ans_fut - k + 998244353) % 998244353;
                k2 = k;
            }
        }
        cout << ans_now << "\n";
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
long long ans[200009] = {1};
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    for (int i = 1; i <= 200009; i++)
    {
        ans[i] = ans[i - 1] * 2 % 998244353;
        ans[i - 1]--;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, num2 = 0, k = 0;
        long long ans_now = 0;
        vector<int> pre1;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                pre1.push_back(num2);
                k++;
            }
            else if (x == 2)
                num2++;
            else
            {
                for (int i = 0; i < k; i++)
                {
                    ans_now = (ans_now + ans[num2 - pre1[i]]) % 998244353;
                }
            }
        }
        cout << ans_now << "\n";
    }
    return 0;
}

*/