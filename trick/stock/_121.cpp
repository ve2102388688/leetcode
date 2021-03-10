#include <bits/stdc++.h>
using namespace std;

/** \brief      maxProfit 买卖股票的最佳时机 121
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
    int size = prices.size();

    int dp_0 = 0, dp_1 = INT_MIN;
    for (int i = 0; i < size; ++i) {
        dp_0 = max(dp_0, dp_1 + prices[i]);
        dp_1 = max(dp_1, -prices[i]);
    }

    return dp_0;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    int output = maxProfit(nums);
    std::cout << output << '\n';

    return 0;
}