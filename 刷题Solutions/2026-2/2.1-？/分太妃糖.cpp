#include <bits/stdc++.h>
using namespace std;
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, a[102] = {0}, sum = 0;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2)
    {
        cout << "-1";
        return 0;
    }
    sum /= 2;

    vector<pair<int, int>> bag(sum + 2, {-1, 0}); // pre + item-id
    bag[0] = {0, 0};
    for (int i = 1; i <= n; i++)
    {
        for (int j = sum; j >= a[i]; j--)
        {
            // cout << i << " " << j << '\n';
            if (bag[j].first == -1 && bag[j - a[i]].first != -1)
            {
                bag[j].first = j - a[i];
                bag[j].second = i;
            }
        }
    }
    if (bag[sum].first == -1)
    {
        cout << "-1";
        return 0;
    }
    queue<int> v1, v2;
    for (int i = sum; i != 0; i = bag[i].first)
    {
        v1.push(a[bag[i].second]);
        a[bag[i].second] = -1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != -1)
        {
            v2.push(a[i]);
        }
    }
    int sum1 = 0, sum2 = 0;
    while (!v1.empty() || !v2.empty())
    {
        if (sum1 <= sum2)
        {
            sum1 += v1.front();
            cout << v1.front() << " ";
            v1.pop();
        }
        else
        {
            sum2 += v2.front();
            cout << v2.front() << " ";
            v2.pop();
        }
    }
    return 0;
}
