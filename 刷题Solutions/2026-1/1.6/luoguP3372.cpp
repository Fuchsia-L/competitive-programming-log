#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int a[100003], tree[400002], lazy[400002];
void build_tree(int node, int l, int r)
{
    if (l == r)
    {
        tree[node] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build_tree(node * 2, l, mid);
    build_tree(node * 2 + 1, mid + 1, r);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
void add(int node, int l, int r, int tarl, int tarr, int num)
{
    if (tarl <= l && tarr >= r)
    {
        lazy[node] += num;
        tree[node] += num * (r - l + 1);
        return;
    }
    if (tarr < l || tarl > r)
        return;
    int mid = (l + r) / 2;
    add(node * 2, l, mid, tarl, tarr, num + lazy[node]);
    add(node * 2 + 1, mid + 1, r, tarl, tarr, num + lazy[node]);
    lazy[node] = 0;
    return;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build_tree(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int x, l, r;
        cin >> x >> l >> r;
        if (x == 1)
        {
        }
    }
    return 0;
}