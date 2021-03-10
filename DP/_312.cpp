#include <bits/stdc++.h>
using namespace std;

/** \brief      maxCoins 戳气球 312
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-9
 * 
 *  \param[in] nums 输入数组
 *  \return         返回硬币的最大数量
 */
int maxCoins(vector<int>& nums) {
    int size = nums.size();
    vector<int> points(size+2, 1); /**<添加首尾添加元素1 */
    for (int i = 0; i < size; ++i)
        points[i + 1] = nums[i];
    
    int n = points.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));       /**<无效空间初值为0 */

    for (int i=n-2; i >= 0; --i) {
        for (int j=i+1; j < n; ++j) {
            for (int k = i + 1; k < j; ++k)
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + points[i] * points[k] * points[j]);
        }
    }
    return dp[0][n-1];
}


int main(int argc, char *argv[])
{
    vector<int> nums = {3, 1, 5, 8};
    int output = maxCoins(nums);
    std::cout << output << std::endl;

    return 0;
}