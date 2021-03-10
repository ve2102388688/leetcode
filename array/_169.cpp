#include <bits/stdc++.h>
using namespace std;


/** \brief      majorityElement 多数元素 169
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-3
 * 
 *  \param[in] numbers  输入数组
 *  \return             返回两数之和
 */
int majorityElement(vector<int>& nums) {
    int size = nums.size();
    unordered_map<int, int> res;

    for(const auto& e : nums) {
        ++res[e];
    }
    for(const auto& e : res) {
        if(e.second > size/2)
            return e.first;
    }

    return 0;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {2,2,1,1,1,2,2};
    int output = majorityElement(nums);
    cout << output << "\n";

    return 0;
}