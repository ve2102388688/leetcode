#include <bits/stdc++.h>
using namespace std;

/** \brief      twoSum 两数之和II - 输入有序数组 167
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-31
 * 
 *  \param[in] numbers  输入数组
 *  \param[in] target   目标值
 *  \return             返回下标位置
 */
// vector<int> twoSum(vector<int>& numbers, int target) {
//     int low = 0;
//     int high = numbers.size() - 1;

//     while(low < high){                                  /**<这里是小于，主要是同一个元素不能取两次 */
//         int sum = numbers[low] + numbers[high];
//         if (sum == target)
//             return {low+1, high+1};
//         else if (sum < target)
//             ++low;
//         else if (sum > target)
//             --high;
//     }
//     return {-1, -1};
// }


/** \brief      twoSum 两数之和
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-31
 * 
 *  \param[in] numbers  输入数组
 *  \param[in] start    开始位置
 *  \param[in] target   目标值
 *  \return             返回下标位置
 */
vector<vector<int>> twoSum(vector<int>& numbers, int start, int target) {
    int low = start;
    int high = numbers.size() - 1;
    vector<vector<int>> res;

    while(low < high){                                  /**<这里是小于，主要是同一个元素不能取两次 */
        int sum = numbers[low] + numbers[high];
        int left = numbers[low], right = numbers[high];
        if (sum == target) {
            res.push_back({left, right});
            while(low < high && left == numbers[low]) ++low;        /**<跳过相同的元素 */
            while(low < high && right == numbers[high]) --high;     /**<跳过相同的元素 */
        } else if (sum < target) {
            while(low < high && left == numbers[low]) ++low;       /**<肯定会执行1次 */
        } else if (sum > target) {
            while(low < high && right == numbers[high]) --high;     /**<肯定会执行1次 */
        }
    }
    return res;
}


/** \brief      threeSum 三数之和
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-31
 * 
 *  \param[in] numbers  输入数组
 *  \param[in] target   目标值
 *  \return             返回下标位置
 */
vector<vector<int>> threeSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int size = nums.size();
    vector<vector<int>> res;

    for (int i = 0; i < size; i++) {                                /**<暴力第一个元素 */
        vector<vector<int>> SeconndSumThird = twoSum(nums, i + 1, target-nums[i]);
        for (auto &e : SeconndSumThird) {
            e.push_back(nums[i]);
            res.push_back(e);
        }

        while(i < size-1 && nums[i] == nums[i+1]) ++i;              /**<跳过所有相同的 */
    }

    return res;
}

int main(int argc, char *argv[])
{
    vector<int> nums = { 1,1,1,2,3};
    vector<vector<int>> output = threeSum(nums, 6);
    for(const auto& e : output) {
        for(const auto& i : e)
            cout << i << ", ";
        cout << "\n";
    }

    return 0;
}