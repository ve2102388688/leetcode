#include <bits/stdc++.h>
using namespace std;

/** \brief      swap  异或交换两元素
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-4
 * 
 *  \param[in] a 输入a
 *  \param[in] b 输入a
 *  \return      void
 */ 
void swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

/** \brief      rotate  旋转数组
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-4
 * 
 *  \param[in] nums 输入数组
 *  \param[in] k    移动次数
 *  \return         void
 */ 
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k %= n;                 /**<显然，结果是关于k的循环 */
    if (n <= 1 || k == 0)
        return;

    // Method 1
    // std::reverse(nums.begin(), nums.end());       //整个数组逆序
    // std::reverse(nums.begin(), nums.begin() + k); //前K个逆序
    // std::reverse(nums.begin() + k, nums.end());   //后面所有逆序

    // 自定义逆序 Method 2
    for (size_t i = n - 1, j = 0; j < i; ++j, --i)
        swap(&nums[i], &nums[j]);
    for (size_t i = k - 1, j = 0; j < i; ++j, --i)
        swap(&nums[i], &nums[j]);
    for (size_t i = n - 1, j = k; j < i; ++j, --i)
        swap(&nums[i], &nums[j]);
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 2};

    rotate(nums, 2);
    for (const auto &e : nums)
        std::cout << e << ' ';
    std::cout << std::endl;

    return 0;
}