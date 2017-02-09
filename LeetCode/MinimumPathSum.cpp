/*
 * 问题分类: 动态规划
 *
 * 解题思路:
 * c[i, j] = min(c[i - 1, j], c[i, j - 1])
 */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        vector<int> sums(grid[0].size(), 0);
        for (int i = 0; i != grid.size(); ++i)
        {
            if (i == 0)
                sums[0] = grid[i][0];
            else
                sums[0] += grid[i][0];
            for (int j = 1; j != sums.size(); ++j)
            {
                if (i == 0)
                    sums[j] = sums[j - 1] + grid[i][j];
                else
                    sums[j] = min(sums[j], sums[j - 1]) + grid[i][j];
            }
        }
        return sums[sums.size() - 1];
    }
};
