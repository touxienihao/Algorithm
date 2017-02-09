/* 
 * 问题分类: 动态规划
 *
 * 解体思路: 
 * 假设我们从街的左边到右边依次进行抢劫.对于第 N 个房子,有两种选择.
 * 如果抢劫,当前总收益为第 N 个房子的现金加上前面的 N - 2 个房子的总收益.
 * 如果不抢劫,当前总收益为前面 N - 1 个房子的总收益.
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int a = nums[0]; // 只有一个房子时的收益.
        int b = max(nums[0], nums[1]); // 总共两个房子时的收益
        for (int i = 2; i != nums.size(); ++i) // 递归计算总共有 3 个房子到总共有 N 个房子时的收益.
        {
            int temp = max(nums[i] + a, b); // 对第 N 个房子,有两种选择,选取收益高的选择.
            a = b; // 保存 N - 2 个房子的总收益
            b = temp; // 保存 N - 1 个房子的总收益
        }
        return b;
    }
};
