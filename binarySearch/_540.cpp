#include <bits/stdc++.h>
using namespace std;

/** \brief      singleNonDuplicate 有序数组中的单一元素 540
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-28
 * 
 *  \param[in] n   输入n
 *  \return        查找的下标
 */
int singleNonDuplicate(vector<int>& nums) {
    int res = 0;
    for (const auto& e : nums)
        res ^= e;
    return res;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    int output = singleNonDuplicate(nums);
    cout << output << " ";

    cout << "\n";

    return 0;
}