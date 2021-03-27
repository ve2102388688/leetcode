#include <bits/stdc++.h>
using namespace std;

/** \brief      findMedianSortedArrays 数组中的第K个最大元素 215
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-25
 * 
 *  \param[in] nums1  输入数组1
 *  \param[in] nums2  输入数组2
 *  \return           返回这两个正序数组的中位数
 */
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size();
    int size2 = nums2.size();
    vector<int> res;
    int i = 0, j = 0;
    while (i < size1 && j < size2) {
        if (nums1[i] < nums2[j])
            res.push_back(nums1[i++]);
        else
            res.push_back(nums2[j++]);
    }
    while (i < size1)
        res.push_back(nums1[i++]);
    while (j < size2)
        res.push_back(nums2[j++]);

    int n = size1 + size2;
    return (n % 2 == 0) ? (res[n/2]+res[n/2-1]) / 2 : res[n/2];
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1,3};
    vector<int> nums2 = {2};

    double output = findMedianSortedArrays(nums, nums2);
    std::cout << output << '\n';

    return 0;
}