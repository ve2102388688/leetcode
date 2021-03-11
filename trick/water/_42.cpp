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
int trap2(vector<int>& height) {
    int n = height.size();
    int res = 0;
    for (int i = 0; i < n - 1; ++i) {
        int lmax = 0, rmax = 0;
        for (int j = i; j < n; ++j)                         /**<找左边柱子的最大值 */
            rmax = (rmax > height[j]) ? rmax : height[j];
        for (int j = i; j >= 0; --j)                        /**<找右边柱子的最大值 */
            lmax = (lmax > height[j]) ? lmax : height[j];

        res += (min(lmax, rmax) - height[i]);               /**<接雨水的量 */
    }
    return res;
}

int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0)
        return 0;
        
    int res = 0;
    int low = 0, high = n-1;
    int lmax = height[0], rmax = height[n - 1];
    while (low <= high) {
        lmax = max(lmax, height[low]);              /**<左侧最大值 */
        rmax = max(rmax, height[high]);             /**<右侧最大值 */

        /**< res += min(lmax, rmax)-height */
        if (lmax < rmax) {
            res += (lmax - height[low]);
            ++low;
        }else {
            res += (rmax - height[high]);
            --high;
        }
    }
    return res;
}


int main(int argc, char *argv[])
{
    vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int output = trap(nums);
    std::cout << output << '\n';

    return 0;
}