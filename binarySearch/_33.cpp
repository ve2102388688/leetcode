#include <bits/stdc++.h>
using namespace std;

/** \brief      search 搜索旋转排序数组 33
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-1
 * 
 *  \param[in] nums   输入数组
 *  \param[in] target 输入目标
 *  \return           查找的下标
 */
int search(vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        if(nums[i] == target)
            return i;
    }
    return -1;
}

// int search(vector<int>& nums, int target) {
//     int lo = 0, hi = nums.size() - 1;
//     while (lo < hi) {
//         int mid = (lo + hi) / 2;
//         if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
//             lo = mid + 1;
//         else
//             hi = mid;
//     }
//     return lo == hi && nums[lo] == target ? lo : -1;
// }

int search2(vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return mid;
        
        if (nums[low] <= nums[mid]) {                           /**<前半部分有序 */
            if (target >= nums[low] && target < nums[mid])
                high = mid - 1;                                 /**<target在前半部分 */
            else 
                low = mid + 1;
        } else {                                                   /**<后半部分有序 */
            if (target > nums[mid] && target <= nums[high])
                low = mid + 1;                                 /**<target在后半部分 */
            else 
                high = mid - 1;
        }
    }
    return -1;
}

int main(int argc, char *argv[])
{
    vector<int> nums1 = {4,5,6,7,0,1,2};
    int output = search2(nums1, 0);
    cout << output << " ";

    cout << "\n";   

    return 0;
}