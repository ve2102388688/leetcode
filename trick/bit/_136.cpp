#include <bits/stdc++.h>
using namespace std;

/** \brief      singleNumber  只出现一次的数字
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-5
 * 
 *  \param[in] nums 输入数组
 *  \return         返回出现一次的数字
 */ 
int singleNumber(vector<int> &nums)
{
    // *******Method1
    for (size_t i = 1; i < nums.size(); ++i)
        nums[0] ^= nums[i];
    return nums[0];

    // *******Method2
    return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
}

int main(int argc, char *argv[])
{
    vector<int> nums = {3,1, 1};
    int ans = singleNumber(nums);
    std::cout << ans << std::endl;

    return 0;
}