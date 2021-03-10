#include <bits/stdc++.h>
using namespace std;

/** \brief      maxProfit 买卖股票的最佳时机 121
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-31
 * 
 *  \param[in] prices  输入数组
 *  \return            返回股票收益最大值
 */
int maxProfit(vector<int>& prices) {
    int min = INT_MAX;
    int maxMoney = 0;

    int size = prices.size();
    for (int i = 0; i < size; ++i) {
        maxMoney = std::max(maxMoney, prices[i]-min);       /**<一个阶段的最低点上的最大收益 */
        min = std::min(min, prices[i]);                     /**<下一个最低点 */
    }
    return maxMoney;
}

 
int main(int argc, char *argv[])
{
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    int output = maxProfit(nums);
    std::cout << output << '\n';

    return 0;
}