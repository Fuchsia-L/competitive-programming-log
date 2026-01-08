#include <iostream>
using namespace std;
int main()
{
    int n, a[2002] = {0}, child[2002] = {0}, leaf[2002] = {0};
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> a[i];
        child[a[i]]++;
    }
    for (int i = 2; i <= n; i++)
    {
        if (child[i] == 0)
            leaf[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        // cout << "i= " << leaf[i] << "\n";
        if (child[i] != 0 && leaf[i] < 3) // 这里的判断易错。不要漏掉如果一个节点有孩子，但它的孩子里一个叶子都没有的情况
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}