#include <bits/stdc++.h>
using namespace std;

/** \brief      search 搜索旋转排序数组II 81
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-2
 * 
 *  \param[in] nums   输入数组
 *  \param[in] target 输入目标
 *  \return           查找的下标
 */
bool search(vector<int>& nums, int target) {
    /**<去重 */
    int size = nums.size();
    if (size == 0)
        return false;
    int lastIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (nums[lastIndex] != nums[i]) {
            nums[++lastIndex] = nums[i];
        }
    }

    int low = 0, high = lastIndex;
    while (low <= high) {
        int mid = (high + low) / 2;
        if (nums[mid] == target)
            return true;

        if (nums[low] <= nums[mid]) {
            if (target >= nums[low] && target < nums[mid]) 
                high = mid -1;
            else
                low = mid + 1;
        } else {
            if (target > nums[mid] && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return false;
}


bool search2(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = (high + low) / 2;
        if (nums[mid] == target)
            return true;
        /**<10111和1110111101这种。此种情况下nums[start] == nums[mid]，分不清到底是前面有序还是后面有序，此时start++即可。相当于去掉一个重复的干扰项 */ 
        if (nums[low] == nums[mid]) {
            ++low;
            continue;
        }

        if (nums[low] < nums[mid]) {                           /**<前半部分有序 */
            if (target >= nums[low] && target < nums[mid]) 
                high = mid -1;                                 /**<target在前半部分 */
            else
                low = mid + 1;
        } else {                                               /**<后半部分有序 */
            if (target > nums[mid] && target <= nums[high])
                low = mid + 1;                                 /**<target在后半部分 */
            else
                high = mid - 1;
        }
    }
    return false;
}


int main(int argc, char *argv[])
{
    vector<int> nums1 = {2,5,6,0,0,1,2};
    int output = search2(nums1, 0);
    cout << output << " ";

    cout << "\n";   

    return 0;
}