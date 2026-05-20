#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        cin >> a[i];
    }
    int k = n;
    stack<int> ans;
    while (a[k] != k)
    {
        k = a[k];
        ans.push(k);
    }
    ans.push(k);
    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
    system("pause");
    return 0;
}