#include <bits/stdc++.h>
using namespace std;

/** \brief      lastStoneWeightII 最后一块石头的重量II 1049
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-22
 *  \remark     dp[i]，容量为i背包最大可装重量
 * 
 *  \param[in] stones  输入数组
 *  \return            凑出总金额为n需要的最少完全平方数
 */
int lastStoneWeightII(vector<int>& stones) {
    vector<int> dp(15001, 0);
    int sum = 0;
    for (const auto &e : stones)
        sum += e;
    int target = sum / 2;

    int n = stones.size();
    for (int i = 0; i < n; ++i){
        for (int j = target; j >= stones[i]; --j)
            dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
    }
    return sum - 2 * dp[target];
}

int main(int argc, char *argv[])
{
    vector<int> nums = {2,7,4,1,8,1};
    int output = lastStoneWeightII(nums);
    std::cout << output << std::endl;

    return 0;
}