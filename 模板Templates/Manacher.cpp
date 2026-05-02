/*
 * Manacher 算法：求每个位置的最长回文半径，O(n)
 * Date: 2026-05 (extracted from P3805 练习)
 *
 * 思路:
 *   1. 在每个字符之间插 '#'，奇偶回文统一为奇数长度
 *      原串 "abba" → 处理串 "#a#b#b#a#"，所有回文中心都是单字符
 *   2. 维护"已知最右回文"中心 c 和右端 r = c + p[c]
 *   3. 新位置 i 在 [c-r, c+r] 内时，从镜像 i'=2c-i 抄保底:
 *        p[i] = min(p[i'], r - i)
 *   4. 仅对 r 之外的部分尝试扩展；每扩成功 r 严格右移
 *   5. r 单调右移 → 总扩展次数 ≤ n → amortized O(n)
 *
 * 直觉(蘑菇喻):
 *   每个位置头顶都有一朵蘑菇（最长回文范围）。
 *   大蘑菇内部镜像对称，所以右半边的小蘑菇直接抄左半边。
 *
 * 返回 p[]: 处理串 t 上以 t[i] 为中心的最长回文【半径】，
 *          它恰好等于原串里以该中心的最长回文【长度】。
 *
 * 哨兵 '^' '$' '#': 要求不出现在原串里；若不放心改用不可打印字符。
 *
 * 典型题目: 洛谷 P3805【模板】manacher
 */

#include <bits/stdc++.h>
using namespace std;

// 返回处理串 t 的半径数组（t.size() = 2*|s| + 3）
// 调用方一般直接 max_element(p.begin(), p.end()) 拿最长回文长度
vector<int> manacher(const string &s)
{
    int n = (int)s.size();
    string t;
    t.reserve(2 * n + 3);
    t += '^';
    for (char ch : s)
    {
        t += '#';
        t += ch;
    }
    t += '#';
    t += '$';

    int m = (int)t.size();
    vector<int> p(m, 0);
    int c = 0, r = 0; // 已知最右回文：中心 c、右端 r
    for (int i = 1; i < m - 1; i++)
    {
        if (i < r)
            p[i] = min(p[2 * c - i], r - i); // 保底（抄镜像）
        // 哨兵 ^ $ 保证 t[i-p[i]-1] 和 t[i+p[i]+1] 不会越界
        while (t[i - p[i] - 1] == t[i + p[i] + 1])
            p[i]++; // 真扩
        if (i + p[i] > r)
        { // 推进最右
            c = i;
            r = i + p[i];
        }
    }
    return p;
}

/* ── 用法示例 (P3805) ─────────────────────────────────────
ios::sync_with_stdio(false); cin.tie(0);   // |s| 大时必备
string s; cin >> s;
auto p = manacher(s);
int ans = *max_element(p.begin(), p.end());
cout << ans << "\n";

// 还原原串里某个回文的起始下标:
//   start_in_s = (i - p[i]) / 2
─────────────────────────────────────────────────────────── */
