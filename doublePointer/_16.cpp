#include <bits/stdc++.h>
using namespace std;

/** \brief      threeSumClosest 最接近的三数之和 16
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-27
 * 
 *  \param[in] nums   输入数组
 *  \param[in] target 输入目标
 *  \return           最近的三数之和
 */
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int result = nums[0] + nums[1] + nums[2];

    int size = nums.size();
    for (int i = 0; i < size-2; ++i) {
        // if (i > 0 && nums[i] == nums[i-1])                          /**<去重方法1 */
        //     continue;
        while (i<size-3 && nums[i] == nums[i+1])                       /**<去重方法2 */
            ++i;

        int low = i+1, high = size-1;
        while (low < high) {
            int sum = nums[i] + nums[low] + nums[high];
            if (abs(sum-target) < abs(result-target))               /**<寻找目标值最接近target */
                result = sum;

            int left = nums[low], right = nums[high];
            if (sum == target) {
                return target;
            } else if (sum < target) {
                while (low < high && left == nums[low]) ++low;      /**<左边去重 */
            } else if (sum > target)
                while (low < high && right == nums[high]) --high;   /**<右边去重 */
        }
    }
    return result;
}

int main(int argc, char *argv[])
{
    vector<int> nums1 = {1,1,1,5};
    int output = threeSumClosest(nums1, 100);
    cout << output << " ";

    cout << "\n";

    return 0;
}