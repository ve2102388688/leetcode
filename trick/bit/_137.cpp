#include <bits/stdc++.h>
using namespace std;

/** \brief      singleNumber 只出现一次的数字II 137
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-13
 *  \remark     异或
 * 
 *  \param[in] nums  输入数组
 *  \return          返回只出现一次的元素
 */
int singleNumber(vector<int>& nums) {
    int one = 0, two = 0;
    for (const auto &e : nums) {
        /**
         * 1. 加入one中、不加入two中
         * 2. 加入two中、不加入one中
         * 3. 出现两次不会加入one，同时从two移除
        */
        one = ~two & (one^e);       /**<将e加入one中 */
        two = ~one & (two^e);       /**<将e不加入two中 */
    }
    return one;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {2,2,2,99};

    int output = singleNumber(nums);
    std::cout << output << '\n';

    return 0;
}