#include <bits/stdc++.h>
using namespace std;
struct node
{
    int v, id;
    bool operator<(const node &other) const
    {
        return v > other.v;
    }
};
int main()
{
    int n, d = 0;
    cin >> n >> d;
    priority_queue<node> a;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        node in = {x, i};
        a.push(in);
    }
    vector<int> ans;
    int sum = 0;
    while (!a.empty())
    {
        node top = a.top();
        a.pop();
        d -= top.v;
        if (d < 0)
            break;
        sum++;
        ans.push_back(top.id);
    }
    cout << sum << "\n";
    for (int i = 0; i < sum; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}