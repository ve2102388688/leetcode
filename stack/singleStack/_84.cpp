#include <bits/stdc++.h>
using namespace std;


/** \brief      largestRectangleArea 柱状图中最大的矩形 84
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-17
 * 
 *  \param[in] heights   输入数组
 *  \return              能够勾勒出来的矩形的最大面积
 */
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    /**<左边界、有边界 */
    /**<left:小于该值的最小左下标 */
    /**<right:小于该值的最小右下标 */
    vector<int> left(n), right(n, n);

    stack<int> sta;
    /**<正序，单调增栈，left是该值右边第一个大于该值的下标 */
    for (int i = 0; i < n; ++i) {
        while (!sta.empty() && heights[sta.top()]>=heights[i]) {
            right[sta.top()] = i;
            sta.pop();
        }
        left[i] = sta.empty() ? -1 : sta.top();
        sta.push(i);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, (right[i]-left[i]-1)*heights[i]);

    return ans;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {2,1,5,4,6,2,3};
    int output = largestRectangleArea(nums);
    cout << output << " ";

    cout << "\n";
    return 0;
}