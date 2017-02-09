/*
 * 问题分类：动态规划
 *
 * 解题思路：
 * 
 */

class Solution {
public:
	int integerBreak(int n) {
		if (n < 2)
			return -1;
		vector<int> products(n + 1, 0);
		products[1] = 0;
		products[2] = 1;
		for (int i = 3; i <=n; ++i)
		{
			for (int j = 1; j != i; ++j)
			{
				products[i] = max(products[i], j * (i - j)); // 剩余的项不可分割
				products[i] = max(products[i], j * products[i - j]); // 剩余的项可分割，动态规划
			}
		}
		return products[n];
	}
};
