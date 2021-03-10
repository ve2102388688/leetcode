#include <bits/stdc++.h>
using namespace std;

/** \brief      rob 打家劫舍 213
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-10
 * 
 *  \param[in] nums  输入数组
 *  \param[in] start 输入起点
 *  \param[in] end   输入终点
 *  \return          偷窃的最大金额
 */
int help(vector<int>& nums, int start, int end) {
    int dp_1 = 0;
    int dp_2 = 0;

    int dp = 0;                             /**<答案 */
    for (int i = end; i >= start; --i) {
        dp = max(dp_1, dp_2 + nums[i]);
        dp_2 = dp_1;                        /**注意赋值的顺序 */
        dp_1 = dp;
    }
    return dp;
}

/** \brief      rob 打家劫舍 213
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
    if (n==1)
        return nums[0];
    return max(help(nums, 0, n - 2), help(nums, 1, n - 1));
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1,2,3,1};
    int output = rob(nums);
    std::cout << output << std::endl;

    return 0;
}