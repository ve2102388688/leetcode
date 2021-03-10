#include <bits/stdc++.h>
using namespace std;


/** \brief      twoSum 两数之和
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-3
 * 
 *  \param[in] numbers  输入数组
 *  \param[in] start    开始位置
 *  \param[in] target   目标值
 *  \return             返回两数之和
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
 *  \date       2020-2-3
 * 
 *  \param[in] nums     输入数组
 *  \param[in] start    开始位置
 *  \param[in] target   目标值
 *  \return             返回三数和
 */
vector<vector<int>> threeSum(vector<int>& nums, int start, int target) {
    int size = nums.size();
    vector<vector<int>> res;

    for (int i = start; i < size; i++) {                                /**<暴力第一个元素 */
        vector<vector<int>> tuples = twoSum(nums, i + 1, target-nums[i]);
        for (auto &e : tuples) {
            e.push_back(nums[i]);
            res.push_back(e);
        }
        while(i < size-1 && nums[i] == nums[i+1]) ++i;              /**<跳过所有相同的 */
    }
    return res;
}

/** \brief      fourSum 四数之和
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-3
 * 
 *  \param[in] nums     输入数组
 *  \param[in] target   目标值
 *  \return             返回四数和
 */
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int size = nums.size();
    vector<vector<int>> res;

    for(int i = 0; i < size; ++i) {
        vector<vector<int>> triples = threeSum(nums, i+1, target-nums[i]);
        for (auto &e : triples){
            e.push_back(nums[i]);
            res.push_back(e);
        }
        while(i < size-1 && nums[i] == nums[i+1]) ++i;              /**<跳过所有相同的 */
    }
    return res;
}


int main(int argc, char *argv[])
{
    vector<int> nums = { 1, 0, -1, 0, -2, 2};
    vector<vector<int>> output = fourSum(nums, 0);
    for(const auto& e : output) {
        for(const auto& i : e)
            cout << i << ", ";
        cout << "\n";
    }

    return 0;
}