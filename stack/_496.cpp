#include <bits/stdc++.h>
using namespace std;


/** \brief      nextGreaterElement	下一个更大元素I 496  
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-4
 * 
 *  \param[in] nums1  数组1
 *  \param[in] nums2  数组2
 *  \return           下一个更大的元素
 */
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size();
    int size2 = nums2.size();
    if(size2 == 0)
        return {};
    unordered_map<int, int> map;
    stack<int> sta;

    for (int i = size2-1; i >= 0; --i) {
        while (!sta.empty() && sta.top() <= nums2[i]) {
            sta.pop();
        }

        map[nums2[i]] = sta.empty() ? -1 : sta.top();
        sta.push(nums2[i]);
    }

    vector<int> res;
    for (int i = 0; i < size1; ++i) {
        res.push_back(map[nums1[i]]);
    }
    return res;
}

int main(int argc, char *argv[])
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> output = nextGreaterElement(nums1, nums2);
    for(const auto& e : output) {
        cout << e << " ";
    }
    cout << "\n";

    return 0;
}