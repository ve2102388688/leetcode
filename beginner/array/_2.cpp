#include <bits/stdc++.h>
using namespace std;

/** \brief      removeDuplicates  买卖股票的最佳时机II
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-4
 * 
 *  \param[in] nums 输入数组         
 *  \return         返回最大利润
 */ 
int maxProfit(vector<int> &prices)
{
    // *********************************************************************************Method1
    // if (prices.size() <= 1)
    //     return 0;

    // int maxMoney = 0;
    // int buyDate = -1;
    // int sellData = -1;
    // int flag = true;
    // int pre = prices[0];
    // for (size_t i = 1; i < prices.size(); ++i)
    // {
    //     if (pre < prices[i] && flag)
    //     {
    //         buyDate = i - 1;                             /**<购买时间点 */
    //         flag = false;
    //     }
    //     else if (pre >= prices[i] && buyDate != -1)
    //     {
    //         sellData = i - 1;                            /**<售卖时间点 */
    //         maxMoney += prices[sellData] - prices[buyDate];
    //         buyDate = sellData = -1;                     /**<寻找下一个时间点 */
    //         flag = true;
    //     }

    //     if (pre < prices[i] && !flag && i == prices.size() - 1)
    //     {
    //         sellData = i;
    //         maxMoney += prices[sellData] - prices[buyDate];
    //     }

    //     pre = prices[i];
    // }
    // return maxMoney;

    // *********************************************************************************Method2
    // if (prices.size() <= 1) // 当数组最多一个元素，则不需要购买，利润为0
    //     return 0;

    // int maxMoney = 0, Profit = 0;
    // for (int i = 1; i < prices.size(); i++)
    // {
    //     // 寻找上升段，当然最极端的上升沿是只有两个数
    //     if ((Profit = prices[i] - prices[i - 1]) > 0)
    //         maxMoney += Profit;
    // }
    // return maxMoney;

    // *********************************************************************************Method3
    int n = prices.size();
    int dp[n][2]; // [][0]:手中没有股票时（最大利润）; [][1]:手中有股票时（最大利润）

    // 边界条件，之后从1开始
    dp[0][0] = 0;          //第零天手中没有股票，利润为0
    dp[0][1] = -prices[0]; //第零天手中有股票，亏了

    for (size_t i = 1; i < n; ++i)
    {
        dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]); //手中没有股票的结果=+前一天就没有+前一天有后卖了（买股票收益）
        dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]); //手中有股票的结果=+前一天就有+前一天没有后买了（卖股票亏损）
    }

    return dp[n - 1][0]; // 返回[n-1][0]
}

int main(int argc, char *argv[])
{
    vector<int> nums = {7, 1, 3, 5, 7};

    int len = maxProfit(nums);
    std::cout << len << std::endl;

    return 0;
}