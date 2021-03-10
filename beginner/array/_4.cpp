#include <bits/stdc++.h>
using namespace std;

/** \brief      rotate  判断是否存在重复元素
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-4
 * 
 *  \param[in] nums 输入数组
 *  \return         false不存在重复元素，true存在重复元素
 */ 
bool containsDuplicate(vector<int> &nums)
{
    //// *******Method1
    //// 不用考虑元素数量小于1，因此下面的循环从1开始
    //int n = nums.size();
    //if (n <= 1)
    //    return false;

    //// 排序后，重复数是相邻的
    //std::sort(nums.begin(), nums.end());
    //for (size_t i = 1; i < n; i++)
    //    if (nums[i-1] == nums[i])
    //        return true;
    //return false;

    // *******Method2(hash)
    std::unordered_set<int> numsSet;
    for (const auto& e : nums) {
        if (!numsSet.insert(e).second)      // insert返回的是std::pair<pos, bool>，表示位置和是否成功
            return true;
    }
    return false;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {3,1};
    bool ans = containsDuplicate(nums);
    std::cout << boolalpha << ans << std::endl;

    return 0;
}