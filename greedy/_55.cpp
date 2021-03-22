#include <bits/stdc++.h>
using namespace std;


/** \brief      canJump 跳跃游戏 55
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-22
 * 
 *  \param[in] nums   评分
 *  \return           能否到达最后一个下标
 */
bool canJump2(vector<int>& nums) {
    int n = nums.size();
    int jump = 0;                   /**<每次选择的最优跳跃点 */

    while(jump < n-1) {
        if (nums[jump] == 0)        /**<最优跳跃点为0,false */
            return false;

        int farthestIndex = 0;
        int farthest = INT_MIN;
        /**<每次从这个范围内，选择最有潜力的跳跃点*/
        for (int i = 1; i <= nums[jump]; ++i) {
            int temp = i + nums[i+jump];
            if (temp >= n-1)
                return true;
            if (farthest < temp) {
                farthest = temp;
                farthestIndex = i+jump;
            }
        }
        jump = farthestIndex;       /**<更新最优跳跃点 */
    }
    return true;
}

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int fastest = 0;                            /**<全局最远点 */

    for (int i = 0; i < n-1; ++i) {
        fastest = max(fastest, i+nums[i]);      /**<取每个跳跃最远点 */
        if (fastest==i)                         /**<发现是0，无法跳跃 */
            return false;
    }
    return fastest >= n - 1;
}


int main(int argc, char *argv[])
{
    vector<int> nums = {1,2};

    bool output = canJump(nums);
    std::cout << output << '\n';

    return 0;
}