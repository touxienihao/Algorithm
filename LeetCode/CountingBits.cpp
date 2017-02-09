/*
 */

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> sums(num + 1, 0);
        if (num == 0)
            return sums;
        sums[1] = 1;
        int count = 2;
        for (int i = 2; i <= num; ++i)
        {
            if (i - count == count)
                count = i;
            sums[i] = sums[i - count] + 1;
        }
        return sums;
};
