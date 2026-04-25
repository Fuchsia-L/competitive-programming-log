/*
 * 0-1 字典树 (Binary Trie / 0-1 Trie) 通用模板
 * Author: Fuchs
 * Date: 2026-04-25
 * Description:
 * 把数当作固定位宽（K 位）的二进制串存进二叉字典树，每层一位（高位在上）。
 * 支持 O(K) 插入、O(K) 查询"已有数中与 x 异或最大的值"。
 * 经典用途：最大子段异或、子集最大异或对、可异或的多重集合维护。
 *
 * 复杂度：单次 insert / query_max 均为 O(K)，K 通常取 30（int）或 60（long long）。
 * 节点数上界：插入 n 个数 → 至多 (n+1) * K 个节点。
 */

#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

template <int K = 30>
struct BinaryTrie
{
    // ch[u][0/1]：节点 u 走 0 或 1 的子节点编号；0 视为空
    // cnt[u]：经过该节点的数的个数（支持 erase 用；纯 insert/query 可不要）
    vector<array<int, 2>> ch;
    vector<int> cnt;
    int tot; // 当前已用节点数（节点编号 1..tot，根是 1）

    BinaryTrie(int n_hint = 100000)
    {
        // 预留 (n+1) * K 个节点 + 1 个根
        ch.assign((n_hint + 1) * K + 2, {0, 0});
        cnt.assign((n_hint + 1) * K + 2, 0);
        tot = 1; // 根节点编号为 1
    }

    // 清空（多测时调用）
    void clear()
    {
        for (int i = 0; i <= tot; i++)
        {
            ch[i][0] = ch[i][1] = 0;
            cnt[i] = 0;
        }
        tot = 1;
    }

    // 插入一个数 x
    void insert(long long x)
    {
        int u = 1;
        for (int i = K - 1; i >= 0; i--)
        {
            int b = (x >> i) & 1;
            if (!ch[u][b])
                ch[u][b] = ++tot;
            u = ch[u][b];
            cnt[u]++;
        }
    }

    // 删除一个数 x（要求之前 insert 过；否则结构会乱）
    void erase(long long x)
    {
        int u = 1;
        for (int i = K - 1; i >= 0; i--)
        {
            int b = (x >> i) & 1;
            u = ch[u][b];
            cnt[u]--;
        }
    }

    // 查询：已插入的数中，与 x 异或最大值是多少
    // 注意：要求树非空，否则返回结果无意义
    long long query_max(long long x)
    {
        int u = 1;
        long long res = 0;
        for (int i = K - 1; i >= 0; i--)
        {
            int b = (x >> i) & 1;
            int want = b ^ 1; // 想走反位拿到该位的 1
            if (ch[u][want] && cnt[ch[u][want]] > 0)
            {
                res |= (1LL << i);
                u = ch[u][want];
            }
            else
            {
                u = ch[u][b]; // 只能走同位，该位贡献 0
            }
        }
        return res;
    }
};

/*
 * 用法示例：求 a[1..n] 的最大子段异或
 *
 * int n; cin >> n;
 * vector<int> a(n + 1);
 * for (int i = 1; i <= n; i++) cin >> a[i];
 *
 * BinaryTrie<30> trie(n);
 * trie.insert(0);                  // p[0] = 0 必须先插入
 * long long p = 0, ans = 0;
 * for (int i = 1; i <= n; i++) {
 *     p ^= a[i];
 *     ans = max(ans, trie.query_max(p));
 *     trie.insert(p);
 * }
 * cout << ans << "\n";
 *
 * 多测：每组开头 trie.clear();
 */
