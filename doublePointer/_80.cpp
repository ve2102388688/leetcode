#include <bits/stdc++.h>
using namespace std;

/** \brief      removeDuplicates 删除排序数组中的重复项II 80
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-27
 * 
 *  \param[in] nums   输入数组
 *  \return           最多重复两次
 */
int removeDuplicates(vector<int>& nums) {
    int size = nums.size();
    if (size <= 2)
        return size;
    
    int slow = 1;
    for (int fast = 2; fast < size; ++fast) {
        if (nums[slow-1] != nums[fast])         /**<相邻两个，判断间隔一个 */
            nums[++slow] = nums[fast];
    }
    return slow+1;
}


int main(int argc, char *argv[])
{
    vector<int> nums1 = {0,0,1,1,1,1,2,3,3};
    int output = removeDuplicates(nums1);
    for (int i = 0; i < output; ++i)
        cout << nums1[i] << " ";

    cout << "\n";

    return 0;
}