/*
 * 问题分类: 动态规划
 *
 * 解题思路: 
 * 假设 c[m,n] 代表从 m x n 的网格开始位置走到结束位置的所有不同路径.
 * c[m, n] = c[m -1, n] + c[m, n - 1] (m != 1 and n != 1)
 * 或者
 * c[m, 1] = c[m - 1, 1] (m != 1)
 * 或者
 * c[1, n] = c[1, n - 1] (n != 1)
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> sums(m + 1, 1);
        for (int j = 2; j <= n; ++j)
        {
            sums[1] = 1;
            for (int i = 2; i <= m; ++i)
                sums[i] += sums[i - 1];
        }
        return sums[m];
    }
};

