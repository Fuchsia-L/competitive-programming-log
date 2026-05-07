#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node
{
    ll now, len;
};
ll n, k;
vector<vector<pair<int, ll>>> road;
vector<ll> main_road, pre_node;
ll max_length = 0, max_node = 0;
void bfs(int start)
{
    pre_node[start] = -1;
    vector<int> used(n + 1, 0);
    used[start] = 1;
    max_length = 0, max_node = 0;
    queue<node> q;
    q.push({start, 0});
    while (!q.empty())
    {
        node nownode = q.front();
        q.pop();
        for (auto nn : road[nownode.now])
        {
            int next = nn.first;
            ll v = nn.second;
            if (main_road[next] != 1 && used[next] != 1)
            {
                used[next] = 1;
                int next_len = nownode.len + v;
                q.push({next, next_len});
                if (max_length < next_len)
                {
                    max_length = next_len;
                    max_node = next;
                }
                pre_node[next] = nownode.now;
            }
        }
    }
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin >> n >> k;
    road.resize(n + 1);
    main_road.resize(n + 1, 0);
    pre_node.resize(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        road[u].push_back({v, c});
        road[v].push_back({u, c});
    }
    // find zhi jing
    bfs(1);
    bfs(max_node);
    int tail = max_node;
    vector<int> main_pre(n + 1);
    while (max_node != -1)
    {
        main_pre[max_node] = pre_node[max_node];
        main_road[max_node] = 1;
        max_node = pre_node[max_node];
    }
    vector<ll> main_road_len(n + 1);
    ll idx = 1, head = 1;
    ll ans = INT_MAX, now_ans = 0;
    vector<ll> pre_sum(n + 1, 0);

    // count child tree and pre_sum
    // cout << "yail=" << tail << "\n";
    ll max_c = 0;
    for (int i = tail; i != -1; i = main_pre[i])
    {
        bfs(i);
        main_road_len[idx] = max_length;
        max_c = max(max_c, max_length);
        idx++;
        if (main_pre[i] != -1)
        {
            for (auto findd : road[i])
            {
                if (findd.first == main_pre[i])
                {
                    // cout << idx << "--" << pre_sum[idx - 1] + findd.second << "\n";
                    pre_sum[idx] = pre_sum[idx - 1] + findd.second;
                    break;
                }
            }
        }
    }
    tail = 1;
    if (idx - 1 <= k)
    {
        cout << max_c << "\n";
        return 0;
    }
    deque<pair<ll, ll>> dq;
    for (int i = 1; i < k; i++)
    {
        while (!dq.empty() && (dq.front().first < tail))
            dq.pop_front();
        while (!dq.empty() && dq.back().second < main_road_len[i])
            dq.pop_back();
        dq.push_back({i, main_road_len[i]});
    }
    for (int i = k; i < idx; i++)
    {
        // cout << i << " ->"; //////////////////

        while (!dq.empty() && (dq.front().first < tail))
            dq.pop_front();
        while (!dq.empty() && dq.back().second < main_road_len[i])
            dq.pop_back();
        dq.push_back({i, main_road_len[i]});
        // cout << "--"; ///////////////
        now_ans = max(max(pre_sum[tail], pre_sum[idx - 1] - pre_sum[i]), dq.front().second);
        ans = min(ans, now_ans);
        // cout << pre_sum[tail] << " " << pre_sum[idx - 1] - pre_sum[i] << " " << dq.front().second << "\n";
        tail++;
    }
    cout << ans << "\n";
    // system("pause"); /////////////////////

    return 0;
}
