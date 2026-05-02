/*
 * SPFA 判负环 (Negative Cycle Detection)
 * Date: 2026-04 (extracted from P3385 练习)
 *
 * 思路:
 *   SPFA = 队列优化的 Bellman-Ford。
 *   记录每个点的【出队次数】 cnt[u]。若 cnt[u] >= n，
 *   说明 u 被反复松弛 → 源点可达的负环存在
 *   （n 个点最短路最多松弛 n-1 次）。
 *
 * 局限: 只能检测「源点 src 可达」的负环。
 *       若要全图判负环，把所有点初始入队、dist 全置 0。
 *
 * 复杂度: 最坏 O(n*m)。
 *
 * 典型题目: P3385【模板】负环
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// graph[u] = { {v, w}, ... }，节点编号 1..n
// 返回 true 表示存在源点 src 可达的负环
bool hasNegativeCycle(int n, int src,
                     const vector<vector<pair<int, ll>>> &graph)
{
    vector<ll> dist(n + 1, LLONG_MAX);
    vector<int> cnt(n + 1, 0);
    vector<bool> inQueue(n + 1, false);

    dist[src] = 0;
    queue<int> q;
    q.push(src);
    inQueue[src] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inQueue[u] = false;
        if (++cnt[u] >= n)
            return true; // 出队 n 次 → 负环

        for (auto [v, w] : graph[u])
        {
            if (dist[u] + w < dist[v])
            { // 松弛
                dist[v] = dist[u] + w;
                if (!inQueue[v])
                {
                    q.push(v);
                    inQueue[v] = true;
                }
            }
        }
    }
    return false;
}

/* ── 用法示例 (对应 P3385) ──────────────────────────
int n, m; cin >> n >> m;
vector<vector<pair<int, ll>>> graph(n + 1);
while (m--) {
    int u, v, w; cin >> u >> v >> w;
    graph[u].push_back({v, w});
    if (w >= 0) graph[v].push_back({u, w});  // P3385 特定：非负边视作无向
}
cout << (hasNegativeCycle(n, 1, graph) ? "YES" : "NO") << "\n";
─────────────────────────────────────────────────── */
