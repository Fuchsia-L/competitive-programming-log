/*
 * 差分数组 (Difference Array) 通用模板
 * Author: [Your Name]
 * Date: 2026-01-13
 * Description:
 * 用于 O(1) 复杂度实现区间 [l, r] 的加减操作。
 * 最终还原数组复杂度为 O(n)。
 * 适用场景：频繁的区间修改，较少的单点查询（或只在最后一次性查询）。
 */

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
struct DifferenceArray
{
    int n;
    vector<T> diff;   // 差分数组
    vector<T> result; // 还原后的原数组

    // 初始化：传入原数组大小（建议 1-based indexing）
    DifferenceArray(int size)
    {
        n = size;
        diff.resize(n + 2, 0); // 多开一点防止越界
    }

    // 通过原数组构建差分数组
    // array 应该是 1-based，即数据从 array[1] 开始
    void buildFrom(const vector<T> &array)
    {
        for (int i = 1; i <= n; i++)
        {
            add(i, i, array[i]); // 利用区间修改初始化
        }
    }

    // 核心操作：区间 [l, r] 增加 v
    // 差分思想：B[l] += v, B[r+1] -= v
    void add(int l, int r, T v)
    {
        if (l > r)
            return;
        diff[l] += v;
        diff[r + 1] -= v;
    }

    // 还原：计算前缀和得到原数组
    vector<T> restore()
    {
        result.resize(n + 1);
        result[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            // 前缀和：A[i] = A[i-1] + B[i]
            // 注意：这里 diff[i] 是累加过的变化量，如果 diff 初始化时已经是 B，则直接加
            // 如果是用 buildFrom 构建的，diff[i] 此时存储的就是 B[i]
            diff[i] += diff[i - 1];
            result[i] = diff[i];
        }
        return result;
    }

    // 调试打印
    void print()
    {
        restore();
        for (int i = 1; i <= n; i++)
            cout << result[i] << " ";
        cout << "\n";
    }
};