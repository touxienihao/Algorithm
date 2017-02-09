/*
 * 问题分类: 动态规划
 *
 * 解题思路: 
 * 只需要考虑两种特殊情况:如果第一个房子被抢劫,第二个和最后一个不能被抢劫,
 * 可对剩下的 3...N-1 个房子应用 HouseRobber 的动态规划;如果第一个房子没有
 * 被抢劫,可对剩下的 2..N 个房子应用 HouseRobber 问题的动态规划.这两种情况
 * 的最大值为最优解.
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        return max(rob_aux(nums, 1, nums.size()), nums[0] + rob_aux(nums, 2, nums.size() - 1));
    }

    int rob_aux(vector<int>& nums, int begin, int end)
    {
        if (begin == end)
            return 0;
        if (end - begin == 1)
            return nums[begin];
        int a = nums[begin];
        int b = max(nums[begin], nums[begin + 1]);
        for (int i = begin + 2; i != end; ++i)
        {
            int cur = max(nums[i] + a, b);
            a = b;
            b = cur;
        }
        return b;
    }
};

