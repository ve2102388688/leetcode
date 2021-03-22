#include <bits/stdc++.h>
using namespace std;


/** \brief      findMinArrowShots 无重叠区间 435
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-16
 * 
 *  \param[in] intervals   输入区间
 *  \return                无重叠区间
 */
int findMinArrowShots(vector<vector<int>>& points) {
    int n = points.size();
    if (n == 0)
        return 0;
    /**<按照结束时间沈旭排序 */
    sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) { return (a[1] > b[1]) ? false : true; });

    int count = 1;                     /**<活动数量最少为1 */
    int end = points[0][1];
    for (int i = 1; i < n; ++i) {
        if (points[i][0] > end) {      /**<这里是等于，碰线也会爆 */
            ++count;
            end = points[i][1];
        }
    }
    return count;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> nums1 = {{1,2}, {2,3}, {3,4}, {1,3}};
    int output = findMinArrowShots(nums1);
    cout << output << " ";

    cout << "\n";

    return 0;
}