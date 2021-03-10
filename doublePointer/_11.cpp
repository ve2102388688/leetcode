#include <bits/stdc++.h>
using namespace std;

/** \brief      maxArea 盛最多水的容器 11
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-23
 * 
 *  \param[in] height   输入数组
 *  \return             最多盛水
 */
int maxArea(vector<int>& height) {
    int low = 0; int high = height.size()-1;
    int less = min(height[0], height[high]);
    int res = less*high;                                        /**<盛水体积 */

    while (low < high) {
        while (low < high && height[low] <= less)   ++low;      /**<找到第一个更大的元素 */
        while (low < high && height[high] <= less)   --high;    /**<找到第一个更大的元素 */

        less = min(height[low], height[high]);
        res = max(res, less * (high - low));
    }
    return res;
}

int maxArea2(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int ans = 0;
    while (l < r) {
        int area = min(height[l], height[r]) * (r - l);
        ans = max(ans, area);
        if (height[l] <= height[r]) {
            ++l;
        }
        else {
            --r;
        }
    }
    return ans;
}

int main(int argc, char *argv[])
{
    vector<int> nums1 = {4,4,4,4};
    int output = maxArea(nums1);
    cout << output << " ";

    cout << "\n";

    return 0;
}