#include <bits/stdc++.h>
using namespace std;

/** \brief      removeDuplicates  删除排序数组中的重复项
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-4
 * 
 *  \param[in] nums 输入数组         
 *  \return         返回去除重复项的长度
 */
int removeDuplicates(vector<int> &nums)
{
    // Method 1
    // 若不为空，则从1开始，即num值至少为1
    int size = nums.size();
    if (size <= 1)
        return size;

    int slow = 0;
    for (int i = 1; i < size; ++i) {
        if (nums[slow] != nums[i])
            nums[++slow] = nums[i];
    }
    return slow+1;

    // // Method 2
    // auto pos = std::unique(nums.begin(), nums.end());
    // return pos - nums.begin();
}


int main(int argc, char *argv[])
{
    vector<int> nums = {1, 1, 2};

    // nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
    int len = removeDuplicates(nums);
    std::cout << len << std::endl;

    return 0;
}