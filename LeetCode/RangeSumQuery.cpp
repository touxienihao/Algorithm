/*
 * 问题分类:
 *
 * 解题思路: 
 *
 */

class NumArray {
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i != nums.size(); ++i)
        {
            sum += nums[i];
            sums.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        if (i == 0)
            return sums[j];
        else
            return sums[j] - sums[i - 1];
    }

private:
    vector<int> sums;
};
