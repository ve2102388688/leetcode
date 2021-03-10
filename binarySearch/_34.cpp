#include <bits/stdc++.h>
using namespace std;

/** \brief      left_bound 左侧二分搜索
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-2
 * 
 *  \param[in] nums   输入数组
 *  \param[in] target 输入目标
 *  \return           返回开始位置和结束位置
 */
int left_bound(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high-low) / 2;
        if (nums[mid] == target)                /**<左侧搜索 */
            high = mid - 1;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    /**<先判断非法情况 */
    if (low >= nums.size() || nums[low] != target)       /**<越界或者元素不存在 */
        return -1;
    return low;
}

/** \brief      right_bound 右侧二分搜索
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-2
 * 
 *  \param[in] nums   输入数组
 *  \param[in] target 输入目标
 *  \return           返回开始位置和结束位置
 */
int right_bound(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high-low) / 2;
        if (nums[mid] == target)                /**<右侧搜索 */
            low = mid + 1;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    /**<先判断非法情况 */
    if (high < 0 || nums[high] != target)       /**<越界或者元素不存在 */
        return -1;
    return high;
}

vector<int> searchRange2(vector<int>& nums, int target) {
    int left = left_bound(nums, target);
    int right = right_bound(nums, target);
    return {left, right};
}


/** \brief      searchRange 在排序数组中查找元素的第一个和最后一个位置 34
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-2
 * 
 *  \param[in] nums   输入数组
 *  \param[in] target 输入目标
 *  \return           返回开始位置和结束位置
 */
vector<int> searchRange(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high-low) / 2;
        if (nums[mid] == target)                /**<左侧搜索 */
            high = mid - 1;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    /**<先判断非法情况 */
    if (low >= nums.size() || nums[low] != target)
        return {-1, -1};

    int last = low;                             /**<尾后元素 */
    while (last < nums.size() && nums[low] == nums[last]) ++last;
        return {low, last-1};
}


int main(int argc, char *argv[])
{
    vector<int> nums1 = {8, 8, 8, 8, 8};
    vector<int> output = searchRange2(nums1, 8);
    for (const auto &e : output)
        cout << e << " ";

    cout << "\n";   

    return 0;
}