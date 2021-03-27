#include <bits/stdc++.h>
using namespace std;


int help(vector<int>& nums, int low, int high, int k) {
    int temp_low = low, temp_high = high;
    int priot = nums[low];
    while (low < high) {
        while (low < high && nums[high]>=priot) --high;
        nums[low] = nums[high];
        while (low < high && nums[low]<=priot) ++low;
        nums[high] = nums[low];
    }
    nums[high] = priot;                                     /**<划分结束 */

    if (temp_high-high+1 == k)                              /**<以temp_high为起点 */
        return nums[high];
    else if(temp_high-high+1 > k)                           /**<在范围内 */
        return help(nums, high+1, temp_high, k);
    else                                                    /**<在范围外 */
        return help(nums, temp_low, high-1, k-(temp_high-high+1));
}

/** \brief      findKthLargest 数组中的第K个最大元素 215
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-25
 * 
 *  \param[in] nums  输入数组
 *  \return          返回第k个最大的元素(1 ≤ k ≤ 数组的长度)
 */
int findKthLargest(vector<int>& nums, int k) {
    return help(nums, 0, nums.size()-1, k);
}

int main(int argc, char *argv[])
{
    vector<int> nums = {3,2,3,1,2,4,5,5,6};

    int output = findKthLargest(nums, 4);
    std::cout << output << '\n';

    return 0;
}