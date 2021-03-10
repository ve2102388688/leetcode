#include <bits/stdc++.h>
using namespace std;

/** \brief      combinationSum4 组合总和Ⅳ 377
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-16
 * 
 *  \param[in] nums   输入数组
 *  \param[in] target 目标和
 *  \return           返回组合个数
 */
int combinationSum4(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> dp(target+1, 0);
    /**<base case: dp[0]=1 */
    dp[0] = 1;
    
    /**<这里是排列，需要交换顺序 */
    for (int i = 0; i <= target; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >= nums[j] && dp[i] < INT_MAX - dp[i - nums[j]])
                dp[i] += dp[i-nums[j]];
        }
    }
    return dp[target];
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 2, 3};

    int output = combinationSum4(nums, 4);
    std::cout << output << '\n';

    return 0;
}