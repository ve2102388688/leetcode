#include <bits/stdc++.h>
using namespace std;

/** \brief      maxSubArray1 最大子序和 53
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-22
 *  \remark     dp[i]表示以nums[i]结尾的最大子数组; 需要遍历数组才能找到最大值; 
 *  \remark     压缩空间
 * 
 *  \param[in] nums 输入数组
 *  \return         返回最大子序和
 */
int maxSubArray1(vector<int>& nums) {
    int size = nums.size();
    if (size == 0)
        return 0;

    int dp0 = nums[0];                    /**<第一个元素结尾的就是第一个元素值 */
    int dp1 = 0;                          /**<dp[i]只和dp[i-1]有关，这里只定义了两个变量 */
    int res = dp0;                        /**<寻找最大值 */

    for (int i = 1; i < size; ++i) {
        dp1 = max(nums[i], dp0 + nums[i]);
        dp0 = dp1;
        
        res = dp1 > res ? dp1 : res;
    }
    return res;
}


/** \brief      maxSubArray 最大子序和 53
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-22
 *  \remark     dp[i]表示以nums[i]结尾的最大子数组; 需要遍历数组才能找到最大值
 * 
 *  \param[in] nums 输入数组
 *  \return         返回最大子序和
 */
int maxSubArray(vector<int>& nums) {
    int size = nums.size();
    if (size == 0)
        return 0;

    vector<int> dp(size);
    dp[0] = nums[0];                    /**<第一个元素结尾的就是第一个元素值 */
    for (int i = 1; i < size; ++i) {
        dp[i] = max(nums[i], dp[i - 1] + nums[i]);
    }

    int res = INT_MIN;                  /**<寻找最大值 */
    for (int i = 0; i < size; ++i) {
        res = dp[i] > res ? dp[i] : res;
    }
    return res;
}


int main(int argc, char *argv[])
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    int output = maxSubArray1(nums);
    std::cout << output << '\n';

    return 0;
}