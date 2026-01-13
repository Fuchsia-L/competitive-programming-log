#include <iostream>
#include <vector>
using namespace std;
class tree
{
private:
    vector<long long> a;
    int n;
    int lowbit(int x)
    {
        return x & -x;
    }

public:
    tree(int num)
    {
        n = num;
        a.assign(n + 2, 0);
    }
    void build(vector<long long> &b)
    {
        for (int i = 1; i <= n; i++)
        {
            a[i] += b[i];
            int j = i + lowbit(i);
            if (j <= n)
                a[j] += a[i];
        }
    }
    /*单点修改*/
    void update(int x, int v)
    {
        for (; x <= n; x += lowbit(x))
        {
            a[x] += v;
        }
    }
    /*单点查询*/
    long long getsum(int x)
    {
        long long ans = 0;
        for (; x > 0; x -= lowbit(x))
        {
            ans += a[x];
        }
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<long long> b;
    int n;
    cin >> n;
    b.resize(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    tree tree1(n);
    tree1.build(b);
    return 0;
}