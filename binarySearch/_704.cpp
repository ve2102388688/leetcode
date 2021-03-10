#include <bits/stdc++.h>
using namespace std;

/** \brief      search 二分查找 704
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-28
 * 
 *  \param[in] nums   输入数组
 *  \param[in] target 输入目标
 *  \return           查找的下标
 */
int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1;
    while (low <= high) {
        int mid = low + (high - low) / 2;       /**<每次都获取中间 */
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main(int argc, char *argv[])
{
    vector<int> nums1 = {1,1,1,5};
    int output = search(nums1, 100);
    cout << output << " ";

    cout << "\n";

    return 0;
}