#include <bits/stdc++.h>
using namespace std;


/** \brief      jump 跳跃游戏II 45
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-23
 * 
 *  \param[in] nums   输入数组
 *  \return           最少的跳跃次数
 */
int jump(vector<int>& nums) {
    int n = nums.size();
    int jumps = 0;              /**<跳跃步数 */
    int farthest = 0;           /**<跳的最远 */
    int end = 0;                /**<处理[i,end]最远跳跃距离 */

    for (int i = 0; i < n-1; ++i) {
        farthest = max(farthest, i+nums[i]);
        if(end == i) {          /**<这个分段结束 */
            end = farthest;
            ++jumps;
        }
    }
    return jumps;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {2,3,1,1,4};

    int output = jump(nums);
    std::cout << output << '\n';

    return 0;
}