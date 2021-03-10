#include <bits/stdc++.h>
using namespace std;

/** \brief      canPartition 分割等和子集 416
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-9
 *  \remark     dp[i][j]：用前i个物品，能否装入容量j
 * 
 *  \param[in] nums 输入数组
 *  \return         能否分割等和子集
 */
bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (const auto e : nums)
        sum += e;
    if (sum%2 == 1) return false;

    int m = nums.size();
    sum = sum / 2;
    vector<vector<bool>> dp(m+1, vector<bool>(sum+1, false));
    /**<当金额为0，不用凑，为真 */
    for (int i = 0; i <=m; ++i)
        dp[i][0] = true;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= sum; ++j) {
            if((j - nums[i-1]) >= 0)                    /**<不装入，装入(用剩下的i-1个物品，装入j-nums[i-1]) */
                dp[i][j] = dp[i - 1][j] || dp[i-1][j - nums[i-1]];        /**<物品从0号开始 */
            else                                        /**<容量不足，无法装入 */
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[m][sum];
}


/** \brief      canPartition 分割等和子集 416
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-9
 *  \remark     状态压缩
 * 
 *  \param[in] nums 输入数组
 *  \return         能否分割等和子集
 */
bool canPartition2(vector<int>& nums) {
    int sum = 0;
    for (const auto e : nums)
        sum += e;
    if (sum%2 == 1) return false;

    sum = sum / 2;
    vector<bool> dp(sum+1,false);
    /**<当金额为0，不用凑，为真 */
    dp[0] = true;

    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        for (int j = sum; j >= 1; --j) {                    /**<这里要倒序，因为上次内容不因该覆盖*/
            if ((j - nums[i]) >= 0)
                dp[j] = dp[j] || dp[j - nums[i]];
        }
    }
    return dp[sum];
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 5, 11, 5};
    bool output = canPartition2(nums);
    std::cout << output << std::endl;

    return 0;
}