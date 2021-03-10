#include <bits/stdc++.h>
using namespace std;


/** \brief      missingNumber 丢失的数 268
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-7
 * 
 *  \param[in] numbers  输入数组
 *  \return             返回两数之和
 */
int missingNumber(vector<int>& nums) {
    int size = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < size; i++) {
        if(nums[i] != i)
            return i;
    }
    return size;
}

/** \brief      missingNumber 丢失的数 268
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-7
 * 
 *  \param[in] numbers  输入数组
 *  \return             返回两数之和
 */
int missingNumber2(vector<int>& nums) {
    int size = nums.size();
    int sum = 0;
    for (int i = 1; i <= size; i++) {           /**高斯求和，减去数组和 */
        sum += i;
        sum -= nums[i - 1];
    }
    return sum;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {3,0,1};
    int output = missingNumber2(nums);
    cout << output << "\n";

    return 0;
}