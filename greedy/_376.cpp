#include <bits/stdc++.h>
using namespace std;


/** \brief      wiggleMaxLength 摆动序列 376
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-16
 *  \remark     统计局部峰值的数量--贪心
 * 
 *  \param[in] nums   输入数组
 *  \return           最长的摆动长度
 */
int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    if (n == 0)
        return 0;
    
    /**<本体就是寻找波峰、波谷的数量 */
    int up = 1, down = 1;
    for (int i = 1; i < n; ++i) {
        if(nums[i] < nums[i-1])
            down = up + 1;                  /**<波谷：在上一次波峰加1 */
        else if(nums[i] > nums[i-1])
            up = down + 1;                  /**<波峰：在上一次波谷加1 */
    }
    return max(down, up);
}

int main(int argc, char *argv[])
{
    vector<int> nums1 = {1,17,5,10,13,15,10,5,16,8};
    int output = wiggleMaxLength(nums1);
    cout << output << " ";

    cout << "\n";

    return 0;
}