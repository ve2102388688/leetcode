#include <bits/stdc++.h>
using namespace std;

/** \brief      summaryRanges 汇总区间 228
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-6
 * 
 *  \param[in] nums  输入数组
 *  \return          返回两数之和
 */
vector<string> summaryRanges(vector<int>& nums) {
    int size = nums.size();
    vector<string> res;
    for (int i = 0; i < size; ){
        int left = i;
        ++i;
        while (i < size && nums[i] == nums[i-1]+1)
            ++i;
        
        if (left != i-1)
            res.push_back(to_string(nums[left]) + "->" + to_string(nums[i-1]));
        else
            res.push_back(to_string(nums[left]));
    }
    return res;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {0,1,2,4,5,7};
    vector<string> output = summaryRanges(nums);
    for(const auto& e :output)
        cout << e << "\n";
    cout << "\n";

    return 0;
}