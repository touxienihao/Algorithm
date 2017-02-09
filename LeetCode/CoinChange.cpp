/*
 *
 */

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount <= 0 || coins.empty())
            return 0;
        vector<int> counts(amount + 1, -1);
        counts[0] = 0;
        for (int i = 1; i <= amount; ++i)
        {
            int count = -1;
            for (int j = 0; j != coins.size(); ++j)
            {
                int index = i - coins[j];
                if (index < 0 || counts[index] == -1)
                    continue;
                if (count == -1)
                    count = counts[index];
                else
                    count = min(count, counts[index]);
            }
            if (count != -1)
                counts[i] = count + 1;
        }
        return counts[amount];
    }
};

int main()
{
    Solution s;
    vector<int> coins{1, 2, 5};
    s.coinChange(coins, 10);
    return 0;
}
