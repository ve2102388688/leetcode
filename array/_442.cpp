#include <bits/stdc++.h>
using namespace std;

/** \brief      findDuplicates 数组中重复的数据 442
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-31
 * 
 *  \param[in] numbers  输入数组
 *  \return             返回重复出现两次的数
 */
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;

    for (const auto& e : nums) {
        int absE = abs(e);              /**<自己制作一个hash */
        if(nums[absE-1] < 0)            /**<为负数，已经反转过一次了 */
            res.push_back(absE);
        else
            nums[absE - 1] *= -1;
    }
    return res;
}


int main(int argc, char *argv[])
{
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> output = findDuplicates(nums);
    for(const auto& e : output) {
        cout << e << ", ";
    }
    cout << "\n";

    return 0;
}