#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> c(n + 1), ans(n + 1);
    vector<int> used(n + 1, 0);
    vector<int> rode(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> ans[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        rode[i] = x;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (used[i])
            continue;
        bool f = 1;
        int now = i;
        int next = now;
        // cout << "check i = " << i << "\n";
        while (used[next] == 0)
        {
            // cout << next << " ";
            used[next] = 1;
            next = rode[next];
            if (used[next] == 2)
                f = 0;
        }
        // cout << "\n01 ok\n";
        int idx = rode[next], sumx = ans[next];
        while (idx != next && f)
        {
            // cout << idx << " ";
            sumx = min(sumx, ans[idx]);
            idx = rode[idx];
        }
        while (used[now] != 2)
        {
            used[now] = 2;
            now = rode[now];
        }
        // cout << "\n02 ok\n";
        if (f)
        {
            // cout << "i = " << i << " , add " << sumx << "\n";
            sum += sumx;
        }
    }
    cout
        << sum << "\n";
    // system("pause");
    return 0;
}
