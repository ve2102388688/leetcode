#include <bits/stdc++.h>
using namespace std;

/** \brief      coinChange 零钱兑换 322
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-9
 *  \remark     dp[i]，凑出总金额为i需要的最少硬币数量
 * 
 *  \param[in] coins  输入数组
 *  \param[in] amount 输入数组
 *  \return           凑出总金额为amount需要的最少硬币数量
 */
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount+1);                   /**<由于需要求最小值，刚开始赋值成不可能的总金额amount+1 */
    
    /**<base case: dp[0]=0 */
    dp[0] = 0;

    int n = coins.size();
    for (int i = 1; i <= amount; ++i) {
        for (int j = 0; j < n; ++j)                         /**<遍历数组coins */
            if((i - coins[j]) >= 0)
                dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
    }
    return dp[amount] == amount+1 ? -1 : dp[amount];        /**<最后的元素没有改变，不能找零 */
}


int main(int argc, char *argv[])
{
    vector<int> nums = {1,2,5};
    int output = coinChange(nums, 11);
    std::cout << output << std::endl;

    return 0;
}