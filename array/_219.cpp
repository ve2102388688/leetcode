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
// bool containsDuplicate(vector<int>& nums, int start, int end) {        
//     std::unordered_set<int> numsSet;
//     for (int i = start; i <= end; ++i) {
//         if (!numsSet.insert(nums[i]).second)
//             return true;
//     }
//     return false;
// }


// bool containsNearbyDuplicate(vector<int>& nums, int k) {
//     int size = nums.size();
//     if(size < 2 || k < 1)
//         return false;
    
//     if(size <= k+1)
//         return containsDuplicate(nums, 0, size-1);

//     for (int i = 0; i < size - k; ++i) {
//         if(containsDuplicate(nums, i, i+k))
//             return true;
//     }
//     return false;
// }


bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int size = nums.size();
    unordered_multiset<int> res;
    for (int i = 0; i < size; i++) {
        if(res.count(nums[i]))
            return true;
        res.insert(nums[i]);
        if(res.size() > k)
            res.erase(nums[i - k]);
    }
    return false;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1,2,3,1,2,3};
    int output = containsNearbyDuplicate(nums, 2);
    cout << output << "\n";

    return 0;
}