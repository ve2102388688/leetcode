#include <bits/stdc++.h>
using namespace std;

/** \brief      intersect  两个数组的交集 II
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-5
 * 
 *  \param[in] nums1 输入数组1
 *  \param[in] nums2 输入数组2
 *  \return          输出交集，可以多次出现
 */ 
vector<int> intersect(vector<int> &nums1, vector<int> nums2)
{
    // ******Method1
    // vector<int> res;
    // sort(nums1.begin(), nums1.end());       /**<将数组排序 */
    // sort(nums2.begin(), nums2.end());

    // int i = 0, size1 = nums1.size();
    // int j = 0, size2 = nums2.size();
    // if(size1 == 0 || size2 == 0)            /**<任何一个数组为空，结束执行 */
    //     return res;

    // /**<求交集思想和求并集是一样的，代码还简单些 */    
    // while (i < size1 && j < size2) {
    //     if(nums1[i] < nums2[j]){
    //         ++i;                            
    //     } else if (nums1[i] == nums2[j]) {  /**<只关心相等的情况 */
    //         res.push_back(nums1[i]);
    //         ++i, ++j;
    //     } else {
    //         ++j;
    //     }
    // }
    // return res;     /**<这里是允许重复的 */

    // ******Method2
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> res;

    /**<注意使用的是back_inserter */
    set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(res));
    return res;
}

int main(int argc, char *argv[])
{
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> ans = intersect(nums1, nums2);
    
    for(const auto& e : ans)
        std::cout << e << " ";
    std::cout << "\n";

    return 0;
}