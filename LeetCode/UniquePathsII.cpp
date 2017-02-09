/*
 * 问题分类: 动态规划
 *
 * 解题思路:
 *
 * c[i, j] = obstacleGrid[i][j] ? 0 : (c[i - 1,j] + c[i] + c[j - 1])
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty())
            return 0;
        vector<int> sums(obstacleGrid[0].size(), 0);
        for (int i = 0; i != obstacleGrid.size(); ++i)
        {
            if (i == 0)
                sums[0] = obstacleGrid[0][0] == 1 ? 0 : 1;
            else
                sums[0] = min(sums[0], obstacleGrid[i][0] == 1 ? 0 : 1);
            for (int j = 1; j != obstacleGrid[0].size(); ++j)
            {
                if (i == 0)
                    sums[j] = min(sums[j - 1], obstacleGrid[0][j] == 1 ? 0: 1);
                else
                    sums[j] = obstacleGrid[i][j] == 1 ? 0 : (sums[j] + sums[j - 1]);
            }
        }
        return sums[obstacleGrid[0].size() - 1];
    }
};
