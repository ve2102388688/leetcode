#include <bits/stdc++.h>
using namespace std;

/** \brief      twoSum  两数之和
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-7
 * 
 *  \param[in] nums   输入数组
 *  \param[in] target 和
 *  \return           前后标号
 */ 
vector<int> twoSum(vector<int>& nums, int target) {
    // ******Method1，hash表
    map<int, int> a;
    for (size_t i = 0; i < nums.size(); ++i) {
        if(a.count(target-nums[i]) == 1)        /**<map不能重复，只能是0或者1 */
            return {a[target-nums[i]], i};
        a[nums[i]] = i;                         /**<将数组中的数存在map，<值,标号> */
    }
    return {};

    // // ******Method2，暴力破解
    // for (int i = 0; i < nums.size(); ++i) {
    //     for(int j = i+1; j < nums.size(); ++j) {
    //         if(nums[i] + nums[j] == target) {       /**<找到就ok */
    //             return {i, j};
    //         }
    //     }
    // }
    // return {};
}

int main(int argc, char *argv[])
{
    vector<int> nums = {3,2,4};
     vector<int> ans = twoSum(nums, 6);

    for(const auto& e : ans)
        std::cout << e << " ";
    std::cout << "\n";

    return 0;
}