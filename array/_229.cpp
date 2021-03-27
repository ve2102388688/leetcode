#include <bits/stdc++.h>
using namespace std;

/** \brief      majorityElement 求众数II 229
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-25
 * 
 *  \param[in] nums  输入数组
 *  \return          返回重复出现n/3次的数
 */
vector<int> majorityElement(vector<int>& nums) {
    int times = nums.size()/3;
    vector<int> ans;
    unordered_map<int, int> memo;

    for(const auto& e : nums) {
        ++memo[e];
    }
    for(const auto& e : memo) {
        if(e.second > times)
            ans.push_back(e.first);
    }
    return ans;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1,1,1,3,3,2,2,2};
    vector<int> output = majorityElement(nums);
    for(const auto& e : output) {
        cout << e << ", ";
    }
    cout << "\n";

    return 0;
}