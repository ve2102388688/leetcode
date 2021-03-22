#include <bits/stdc++.h>
using namespace std;

/** \brief      intervalSechedule 最大的活动安排问题
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-16
 * 
 *  \param[in] intervals   输入区间
 *  \return                最大的活动数目
 */
int intervalSechedule(vector<vector<int>>& intervals) {
    int n = intervals.size();
    if (n == 0)
        return 0;
    /**<按照结束时间升序 */
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) { return (a[1] > b[1]) ? false : true; });
    
    int count = 1;              /**<至少安排一条活动 */
    int end = intervals[0][1];
    for (int i = 1; i<n; ++i){
        if(intervals[i][0] >= end) {        /**<只要下一个活动开始时间比最后一条早就可以了 */
            ++count;
            end = intervals[i][1];
        }
    }
    return count;
}

/** \brief      eraseOverlapIntervals 无重叠区间 435
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-16
 * 
 *  \param[in] intervals   输入区间
 *  \return                无重叠区间
 */
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    return intervals.size() - intervalSechedule(intervals);     /**<活动安排问题取反 */
}

int main(int argc, char *argv[])
{
    vector<vector<int>> nums1 = {{1,2}, {2,3}, {3,4}, {1,3}};
    int output = eraseOverlapIntervals(nums1);
    cout << output << " ";

    cout << "\n";

    return 0;
}