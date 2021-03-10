#include <bits/stdc++.h>
using namespace std;

/** \brief      change 零钱兑换II 518
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-10
 * 
 *  \param[in] amount   金额
 *  \param[in] coins    输入数组
 *  \return             金额是amount的硬币方案数目
 */
int change(int amount, vector<int>& coins) {
    int n = coins.size();

    vector<vector<int>> dp(n+1, vector<int>(amount+1,0));
    for (int i = 0; i <= n; ++i)
        dp[i][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= amount; ++j) {
            if ((j - coins[i-1]) >= 0)
                dp[i][j] = dp[i][j - coins[i-1]] + dp[i - 1][j];    /**<注意：这里是i-1，因为之前对n多加一个元素 */
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][amount];
}


/** \brief      change 零钱兑换II 518
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-10
 * 
 *  \param[in] amount 金额
 *  \param[in] coins  输入数组
 *  \return           金额是amount的硬币方案数目
 */
int change2(int amount, vector<int>& coins) {
    int n = coins.size();

    vector<int> dp(amount+1, 0);
    /**<base case: weight=0，对应着一种方案 */
    dp[0] = 1;

    for (int i = 0; i < n; ++i) {           /**<注意循环开始和结束 */
        for (int j = 1; j <= amount; ++j) {
            if ((j - coins[i]) >= 0)
                dp[j] += dp[j - coins[i]];   /**<注意：这里是i，因为没有对n多加一个元素 */
        }
    }
    return dp[amount];
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 2, 5};
    int output = change2(5, nums);
    std::cout << output << std::endl;

    return 0;
}