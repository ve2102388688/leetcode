#include <bits/stdc++.h>
using namespace std;

/** \brief      nextGreatestLetter 两个数组的交集 350
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-1
 * 
 *  \param[in] nums   输入数组
 *  \param[in] nums   输入数组
 *  \return           查找的下标
 */
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> res;

    int size1 = nums1.size();
    int size2 = nums2.size();
    int i = 0, j = 0;
    while (i < size1 && j < size2) {
        while (i < size1 && j < size2 && nums1[i] < nums2[j]) ++i;
        while (i < size1 && j < size2 && nums1[i] > nums2[j]) ++j;
        if (i < size1 && j < size2 && nums1[i] == nums2[j]) {           /**<注意，一定要有下标判断 */
            res.push_back(nums1[i]);
            /**<去重 */
            // while (i < size1 - 1 && nums1[i] == nums1[i + 1]) ++i;      /**<防止越界，只能比较到倒数第二个 */
            // while (j < size2 - 1 && nums2[j] == nums2[j + 1]) ++j;      /**<防止越界，只能比较到倒数第二个 */
            ++i, ++j;
        }
    }
    return res;
}


int main(int argc, char *argv[])
{
    vector<int> nums1 = {3,7,9};
    vector<int> nums2 = {0,0,1,4,4,4,6,7};
    vector<int> output = intersection(nums1, nums2);
    for (const auto &e : output)
        cout << e << " ";

    cout << "\n";   

    return 0;
}