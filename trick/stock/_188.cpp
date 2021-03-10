#include <bits/stdc++.h>
using namespace std;


int maxProfit2(vector<int> &prices) {
    /**压缩的动态规划 */
    int n = prices.size();
    int dp_0 = 0, dp_1 = INT_MIN;
    for (int i = 0; i < n; ++i) {
        int temp = dp_0;
        dp_0 = max(dp_0, dp_1 + prices[i]);
        dp_1 = max(dp_1, temp - prices[i]);
    }
    return dp_0;
}
/** \brief      maxProfit 最佳买卖股票时机含冷冻期 309
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-20
 *  \remark     动态规划
 * 
 *  \param[in] prices  输入数组
 *  \return            返回股票收益最大值
 */
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if (k >= n/2)  return maxProfit2(prices);

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, 0)));
    /**<base case: 0天有股票是负值 */
    for (int i = 1; i <= k; ++i)
        dp[0][i][1] = -prices[0];

    for (int i = 1; i < n; ++i) {
        for (int j = k; j >= 1; --j) {
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j-1][0] - prices[i]);
        }
    }
    return dp[n - 1][k][0];
}

int main(int argc, char *argv[])
{
    vector<int> nums = {3,2,6,5,0,3};
    int output = maxProfit(2, nums);
    std::cout << output << '\n';

    return 0;
}