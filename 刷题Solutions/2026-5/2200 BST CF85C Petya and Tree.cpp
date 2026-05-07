#include <bits/stdc++.h>
using namespace std;
struct node
{
    int fa_idx, val;
    int l_idx = -1, r_idx;
    int maxx, minn;
};
struct ppp
{
    int left = -0x3f3f3f;
    long long sum = 0;
    int right = INT_MAX;
    int cnti = 0;
    int idx;
};
bool cmp2(int p2, pair<int, double> &p1)
{
    return p1.first > p2;
}
int main()
{
    //   ios::sync_with_stdio(false);
    //   cin.tie(nullptr);
    int n, k, head_idx;
    cin >> n;
    vector<node> v(n + 1);
    queue<int> leaf_idx;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].fa_idx >> v[i].val;
        v[i].maxx = v[i].minn = v[i].val;
    }
    for (int i = 1; i <= n; i++)
    {
        if (v[i].fa_idx == -1)
        {
            head_idx = i;
            continue;
        }
        if (v[i].val > v[v[i].fa_idx].val)
        {
            v[v[i].fa_idx].r_idx = i;
        }
        else
        {
            v[v[i].fa_idx].l_idx = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        // cout << i << " : " << v[i].l_idx << " " << v[i].r_idx << "\n";
        if (v[i].l_idx == -1)
        {
            leaf_idx.push(i);
        }
    }
    while (!leaf_idx.empty())
    {
        int now_idx = leaf_idx.front();
        leaf_idx.pop();
        int fa = v[now_idx].fa_idx;
        // cout << "now idx = " << now_idx << " , fa = " << fa << "\n"; ///////////
        if (fa == -1)
        {
            break;
        }
        if (v[fa].r_idx == now_idx)
            v[fa].maxx = max(v[fa].maxx, v[now_idx].maxx);
        else
            v[fa].minn = min(v[fa].minn, v[now_idx].minn);
        if (v[fa].val != v[fa].maxx && v[fa].val != v[fa].minn)
        {
            // cout << "node " << fa << " , l/r = " << v[fa].minn << " " << v[fa].maxx << "\n"; ////////////
            leaf_idx.push(fa);
        }
    }

    queue<ppp> find_ans;
    ppp p1;
    p1.idx = head_idx;
    find_ans.push(p1);
    vector<pair<int, double>> ans; // left , sum
    int cnt = 0;
    while (!find_ans.empty())
    {
        ppp nowppp = find_ans.front();
        find_ans.pop();
        if (v[nowppp.idx].l_idx == -1)
        {
            ans.push_back({nowppp.left, (double)nowppp.sum / nowppp.cnti});
            continue;
        }
        ppp pl, pr;
        pl = pr = nowppp;
        pl.cnti++;
        pr.cnti++;
        pl.right = min(pl.right, v[pl.idx].val);
        pr.left = max(pr.left, v[pr.idx].val);
        pl.sum += v[v[pl.idx].r_idx].minn;
        pr.sum += v[v[pr.idx].l_idx].maxx;
        pl.idx = v[pl.idx].l_idx;
        pr.idx = v[pr.idx].r_idx;
        if (pl.left < pl.right)
            find_ans.push(pl);
        if (pr.left < pr.right)
            find_ans.push(pr);
    }
    sort(ans.begin(), ans.end());
    cin >> k;
    while (k--)
    {
        int key;
        cin >> key;
        auto i = upper_bound(ans.begin(), ans.end(), key, cmp2);
        i--;
        cout << fixed << setprecision(10) << (*i).second << "\n";
    }
    system("pause");
    return 0;
}