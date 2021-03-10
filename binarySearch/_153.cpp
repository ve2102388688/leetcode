#include <bits/stdc++.h>
using namespace std;

/** \brief      findMin 寻找旋转排序数组中的最小值 153
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-2
 * 
 *  \param[in] nums   输入数组
 *  \return           最小值
 */
int findMin(vector<int>& nums) {
    int minNumber = INT_MAX;
    for (const auto &e : nums) {
        minNumber = min(minNumber, e);
    }
    return minNumber;
}
/** \brief      findMin 寻找旋转排序数组中的最小值 153
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-2
 *  \remark     https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/er-fen-cha-zhao-wei-shi-yao-zuo-you-bu-dui-cheng-z/
 * 
 *  \param[in] nums   输入数组
 *  \return           最小值
 */
int findMin2(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {                        /**<这里就是要不相等，因为循环内没有判等的代码，否则死循环 */
        int mid = (high + low) /2;
        if (nums[mid] > nums[high]) {           /**<穷举几种情况， 发现这是突破口 */
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return nums[low];
}

int main(int argc, char *argv[])
{
    vector<int> nums1 = {3,4,5,1,2};
    int output = findMin2(nums1);
    cout << output << " ";

    cout << "\n";   

    return 0;
}