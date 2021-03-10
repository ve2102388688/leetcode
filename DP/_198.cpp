#include <bits/stdc++.h>
using namespace std;

/** \brief      rob 打家劫舍 198
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-10
 * 
 *  \param[in] nums 输入数组
 *  \return         偷窃的最大金额
 */
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n+2, 0);

    /**<base case: dp[n]=dp[n+1]=0 */

    for (int i = n-1; i >= 0; --i) {                /**<倒着遍历的 */
        dp[i] = max(dp[i + 1], dp[i + 2] + nums[i]);
    }
    return dp[0];
}


/** \brief      rob 打家劫舍 198
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-10
 *  \remark     状态压缩
 * 
 *  \param[in] nums 输入数组
 *  \return         偷窃的最大金额
 */
int rob2(vector<int>& nums) {
    int n = nums.size();
    int dp_1 = 0;
    int dp_2 = 0;

    int dp = 0;                             /**<答案 */
    for (int i = n - 1; i >= 0; --i) {
        dp = max(dp_1, dp_2 + nums[i]);
        dp_2 = dp_1;                        /**注意赋值的顺序 */
        dp_1 = dp;
    }
    return dp;
}


int main(int argc, char *argv[])
{
    vector<int> nums = {1,2,3,1};
    int output = rob2(nums);
    std::cout << output << std::endl;

    return 0;
}