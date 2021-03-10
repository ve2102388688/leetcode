#include <bits/stdc++.h>
using namespace std;

/** \brief      removeElement 移除元素 27
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-29
 * 
 *  \param[in] nums     输入数组
 *  \param[in] target   查找的值
 *  \return             返回查找的位置
 */
int searchInsert(vector<int>& nums, int target) {
    int size = nums.size();
    if (size == 0)
        return 0;

    int i = 0;
    for (; i < size; ++i) {                
        if(nums[i] >= target)           /**<只要找到目标位置大于等于target，直接返回 */
            break;
    }
    return i;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1};

    int output = searchInsert(nums, 0);
    std::cout << output << '\n';

    return 0;
}