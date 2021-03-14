#include <bits/stdc++.h>
using namespace std;

/** \brief      singleNumber 只出现一次的数字III 260
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-13
 *  \remark     异或
 * 
 *  \param[in] prices  输入数组
 *  \return            返回只出现一次的元素
 */
vector<int> singleNumber(vector<int>& nums) {
    int ans = 0;
    for (const auto &e : nums)              /**<求出答案，出现一次的两个值异或，肯定不为0 */
        ans ^= e;
    int bit = 1;
    while ((bit&ans)==0)                    /**<找到第一个不为0的位*/
        bit <<= 1;
    int a = 0, b = 0;
    for (const auto &e : nums) {            /**<分成两组 */
        if (bit&e)
            a ^= e;
        else
            b ^= e;
    }
    return {a, b};
}

int main(int argc, char *argv[])
{
    vector<int> nums1 = {1, 2, 1,3};
    vector<int> output = singleNumber(nums1);
    for(const auto& e : output) {
        cout << e << " ";
    }
    cout << "\n";

    return 0;
}