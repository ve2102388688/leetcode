#include <bits/stdc++.h>
using namespace std;

/** \brief      findPeakElement 寻找峰值 162
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-2
 * 
 *  \param[in] nums   输入数组
 *  \return           峰值下标
 */
int findPeakElement(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = (high + low) / 2;
        /**<画图就出来了 */
        if (nums[mid] > nums[mid+1])
            high = mid;
        else 
            low = mid+1;
    }
    return low;
}


int main(int argc, char *argv[])
{
    vector<int> nums1 = {1,2,1,3,5,6,4};
    int output = findPeakElement(nums1);
    cout << output << " ";

    cout << "\n";   

    return 0;
}