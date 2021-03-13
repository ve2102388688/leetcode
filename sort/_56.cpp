#include <bits/stdc++.h>
using namespace std;


/** \brief      merge 合并区间 56
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-12
 *  \remark     排序再解决问题
 * 
 *  \param[in] nums 输入二维数组
 *  \return         void
 */ 
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;

    sort(intervals.begin(), intervals.end());       /**<排序 */
    for (const auto &e : intervals){
        if (!res.empty() && e[0]<= res.back()[1]) {     /**<当前左边<=res的最后一个的右边，直接合并 */
            res.back()[1] = max(e[1], res.back()[1]);
        } else {
            res.push_back(e);                           /**<没有重叠 */
        }
    }
    return res;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> nums = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> output = merge(nums);
    for (const auto &e : output) {
        for (const auto &i : e)
            std::cout << i << ' ';
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}