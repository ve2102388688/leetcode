#include <bits/stdc++.h>
using namespace std;

/** \brief      findTargetSumWays 目标和 494
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-10
 * 
 *  \param[in] nums 输入数组
 *  \param[in] S    目标值
 *  \return         方案总数
 */
int findTargetSumWays(vector<int>& nums, int S) {
    int sum = 0;
    for (const auto &e : nums)
        sum += e;
    if(sum < S || (sum+S)%2 == 1)
        return 0;
    
    sum  = (sum+S) / 2;
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= sum; ++j) {    /**<注意这里是0 */
            if ((j - nums[i-1]) >= 0)
                dp[i][j] = dp[i - 1][j] + dp[i-1][j-nums[i-1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}


/** \brief      findTargetSumWays 目标和 494
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-10
 * 
 *  \param[in] nums 输入数组
 *  \param[in] S    目标值
 *  \return         方案总数
 */
int findTargetSumWays2(vector<int>& nums, int S) {
    int sum = 0;
    for (const auto &e : nums)
        sum += e;
    if(sum < S || (sum+S)%2 == 1)
        return 0;
    
    sum  = (sum+S) / 2;
    vector<int> dp(sum + 1, 0);
    /**<base case */
    dp[0] = 1;

    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        for (int j = sum; j >= 0; --j) {    /**<需要倒序， 因为不能覆盖上一次的结果，注意这里是0 */
            if(j >= nums[i])
                dp[j] += dp[j - nums[i]];
        }
    }
    return dp[sum];
}

int main(int argc, char *argv[])
{
    vector<int> nums = {0,0,0,0,0,0,0,0,1};
    int output = findTargetSumWays2(nums, 1);
    std::cout << output << std::endl;

    return 0;
}