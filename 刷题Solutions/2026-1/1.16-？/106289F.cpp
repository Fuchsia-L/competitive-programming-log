#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll book[200005][2] = {0}, n;
int index = 1;
long long find_index(long long k)
{
    int l = 1, r = index, mid, ans;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (book[mid][0] <= k)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q, ai;
    cin >> n >> q;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>> pq; // 数量-id
    for (int i = 1; i <= n; i++)
    {
        cin >> ai;
        pq.push({ai, i});
    }
    int maxid = -1;
    ll move = 0, before = pq.top().first, after, derta = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        after = pq.top().first;
        sum += after;
        derta = i * (before - after);
        before = after;

        maxid = max(maxid, pq.top().second);
        if (derta != 0)
        {
            index++;
            book[index][0] = derta + book[index - 1][0];
        }
        book[index][1] = maxid;
        pq.pop();
    }
    index++;
    book[index][0] = sum;
    book[index][1] = n;
    long long num;
    for (int i = 1; i <= q; i++)
    {
        cin >> num;
        long long k = find_index(num);
        cout << book[k][1] << "\n";
    }

    return 0;
}