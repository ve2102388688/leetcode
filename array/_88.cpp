#include <bits/stdc++.h>
using namespace std;

/** \brief      merge 合并两个有序数组 88
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-29
 * 
 *  \param[in] nums1    输入数组1
 *  \param[in] m        数组1长度
 *  \param[in] nums2    输入数组2
 *  \param[in] n        数组2长度
 *  \return             void
 */
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> res;

    /**<二路并归--典型代码 */
    int i = 0;
    int j = 0;
    while(i < m && j < n) {
        if(nums1[i] < nums2[j]){
            res.push_back(nums1[i]);
            ++i;
        }else{
            res.push_back(nums2[j]);
            ++j;
        }
    }
    while (i < m){
        res.push_back(nums1[i]);
        ++i;
    }
    while (j < n){
        res.push_back(nums2[j]);
        ++j;
    }
    
    for (int i = 0; i < res.size(); ++i)
        nums1[i] = res[i];
}

void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int end = m + n - 1;
    int i = m - 1;
    int j = n - 1;
    while (i >= 0 && j >= 0)                    /**<其中一个数组为空为止 */
        nums1[end--] = (nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];

    if (i < 0) {
        for (int k = 0; k <= j; ++k)                /**<注意等号 */
            nums1[k] = nums2[k];
    }
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    merge2(nums, 3, nums2, 3);
    for(const auto & e : nums)
        std::cout << e << ' ';
    std::cout << '\n';

    return 0;
}