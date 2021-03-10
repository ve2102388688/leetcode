#include <bits/stdc++.h>
using namespace std;

/** \brief      twoSum 两数之和 II - 输入有序数组 167
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-31
 * 
 *  \param[in] numbers  输入数组
 *  \param[in] target   目标值
 *  \return             返回下标位置
 */
vector<int> twoSum(vector<int>& numbers, int target) {
    int low = 0;
    int high = numbers.size() - 1;

    while(low < high){
        int sum = numbers[low] + numbers[high];
        if (sum == target)
            return {low+1, high+1};
        else if (sum < target)
            ++low;
        else if (sum > target)
            --high;
    }
    return {-1, -1};
}

int main(int argc, char *argv[])
{
    vector<int> nums = {2,7,11,15};
    vector<int> output = twoSum(nums, 9);
    std::cout << output[0] << ", " << output[1] << '\n';

    return 0;
}