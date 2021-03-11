#include <bits/stdc++.h>
using namespace std;


/** \brief      nextGreaterElement	下一个更大元素I 496  
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-4
 *  \remark     单调栈
 * 
 *  \param[in] nums1  数组1
 *  \param[in] nums2  数组2
 *  \return           下一个更大的元素
 */
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    int m = 2 * n - 1;              /**<假想数组重复一次 */

    vector<int> res(n);
    stack<int> sta;
    for (int i = m; i >= 0; --i) {
        while (!sta.empty() && sta.top() <= nums[i%n])      /**<个子矮的出栈  */
            sta.pop();
        res[i%n] = sta.empty() ? -1 : sta.top();
        sta.push(nums[i % n]);
    }
    return res;                                             /**<个子高的入栈 */
}

int main(int argc, char *argv[])
{
    vector<int> nums1 = {1, 2, 1};
    vector<int> output = nextGreaterElements(nums1);
    for(const auto& e : output) {
        cout << e << " ";
    }
    cout << "\n";

    return 0;
}