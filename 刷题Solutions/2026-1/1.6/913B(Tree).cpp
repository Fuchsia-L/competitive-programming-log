#include <iostream>
#include <vector>
using namespace std;
vector<int> tree[1020];
bool isL(int num)
{
    return tree[num].empty();
}
// 很有灵魂的树状bfs
bool fun(int num)
{
    if (tree[num].empty())
        return true;
    int count = 0;
    for (int child : tree[num])
    {
        if (isL(child))
            count++;
    }
    if (count < 3)
        return false;
    for (int child : tree[num])
    {
        if (fun(child) == false)
            return false;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        tree[x].push_back(i);
    }

    if (fun(1))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}