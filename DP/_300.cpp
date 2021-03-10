#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;


/** \brief      lengthOfLIS2 最长递增子序列 200
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-21
 *  \remark     dp[i]表示以nums[i]结尾的最长递增子序列
 * 
 *  \param[in] root 输入数组
 *  \return         返回最长递增子序列
 */
int lengthOfLIS2(vector<int>& nums) {
    int size = nums.size();
    vector<int> dp(size);
    fill(dp.begin(), dp.end(), 1);          /**<初始状态 */

    for(int i = 0; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            if(nums[j] < nums[i])           /**<只要发现前面的数值较小，dp[i]=max(最长子序列+1, dp[i]) */
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int res = 0;                            /**<循环一次，寻找最大值 */
    for (int i = 0; i < size; ++i) {
        res = max(res, dp[i]);
    }
    return res;
}

/** \brief      lengthOfLIS 最长递增子序列 200
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-21
 *  \remark     技巧性很强
 * 
 *  \param[in] root 输入数组
 *  \return         返回最长递增子序列
 */
int lengthOfLIS(vector<int>& nums) {
    vector<int> top;                    /**每堆牌的牌顶，同一位置多次放置被覆盖 */

    int piles = 0;                      /**牌堆的数量 */
    int size = nums.size();
    for (int i = 0; i < size; ++i) {    /**牌的数量处理完，也就结束了 */
        int proke = nums[i];

        int left = 0;                   /**左开右闭 */
        int right = piles;
        /**<左侧二分查找 */
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (top[mid] == proke){
                right = mid;
            } else if (top[mid] > proke) {
                right = mid;
            } else if (top[mid] < proke) {
                left = mid + 1;
            }
        }
        if(left == piles) {             /**没有找到合适的牌堆，新建一堆，压入容器 */
            ++piles;
            top.push_back(proke);
        } else {
            top[left] = proke;          /**同一位置多次覆盖，保证同一位置的数越来越小 */
        }
    }
    return piles;                       /**牌堆的数量就是最长递增序列 */
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {10,9,2,5,3,7,101,18};

    int output = lengthOfLIS2(nums);
    std::cout << output << '\n';

    return 0;
}