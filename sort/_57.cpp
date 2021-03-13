#include <bits/stdc++.h>
using namespace std;


/** \brief      insert 合并区间 56
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-12
 *  \remark     排序再解决问题
 * 
 *  \param[in] nums 输入二维数组
 *  \return         void
 */ 
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    if (intervals.size() == 0)
        return {newInterval};

    vector<vector<int>> res;
    int flag = true;
    int n = intervals.size();
    for (int i = 0; i <n ; ++i) {
        if (flag && intervals[i][1]>newInterval[0]) {
            res.push_back({intervals[i][0], newInterval[1]});
            flag = false;
        } else if(flag && (i==n-1 || newInterval[1]<intervals[i+1][0]) ){
            res.push_back(newInterval);
            flag = false;
        } else if (flag == false && res.back()[1] >= intervals[i][0]) {
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        } else {
            res.push_back(intervals[i]);
        }
    }
    return res;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> nums = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> nums2 = {4, 8};

    vector<vector<int>> output = insert(nums, nums2);
    for (const auto &e : output) {
        for (const auto &i : e)
            std::cout << i << ' ';
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}