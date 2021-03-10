#include <bits/stdc++.h>
using namespace std;

/** \brief      maxProfit 买卖股票的最佳时机III 123
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-20
 *  \remark     动态规划
 * 
 *  \param[in] prices  输入数组
 *  \return            返回股票收益最大值
 */
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, 0)));

    /**<base case: 0天有股票是负值 */
    dp[0][1][1] = -prices[0];
    dp[0][2][1] = -prices[0];

    for (int i = 1; i < n; ++i) {
        for (int k = 2; k >= 1; --k) {
            dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
            dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
        }
    }
    return dp[n - 1][2][0];
}


int maxProfit2(vector<int>& prices) {
    int n = prices.size();

    /**<base case: 持有股票都是负无穷，没有就是0 */
    int dp_1_0 = 0;
    int dp_1_1 = INT_MIN;
    int dp_2_1 = INT_MIN;
    int dp_2_0 = 0;

    for (const auto& price : prices) {
        dp_1_0 = max(dp_1_0, dp_1_1 + price);
        dp_1_1 = max(dp_1_1, -price);
        dp_2_0 = max(dp_2_0, dp_2_1 + price);
        dp_2_1 = max(dp_2_1, dp_1_0 - price);
    }
    return dp_2_0;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1,2,3,4,5};
    int output = maxProfit2(nums);
    std::cout << output << '\n';

    return 0;
}