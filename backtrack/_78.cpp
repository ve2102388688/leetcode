#include <bits/stdc++.h>
using namespace std;


/** \brief      backtrack 回溯函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-16
 * 
 *  \param[in] nums  输入数组
 *  \param[in] start 开始位置的子集
 *  \param[in] track 路径
 *  \return          void
 */
vector<vector<int>> res;
void backtrack(vector<int> &nums, int start, vector<int>& track) {
    /**<不需要判断出口，因为每次执行都会产生一个结果 */
    res.push_back(track);

    /**<从start开始，防止重复，子集其实是组合，不是排序 */
    for (int i = start; i < nums.size(); ++i) {
        track.push_back(nums[i]);
        backtrack(nums, i + 1, track);
        track.pop_back();
    }
}

/** \brief      subsets 子集 78
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-16
 * 
 *  \param[in] nums  输入数组
 *  \return          返回所有子集，由于是全局变量，所以可以返回引用
 */
vector<vector<int>>& subsets(vector<int>& nums) {
    vector<int> track;
    backtrack(nums, 0, track);
    return res;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {1, 2, 3};
    vector<vector<int>> output = subsets(nums);
    for (const auto&e : output) {
        for (const auto&i : e)
            std::cout << i << ' ';
        std::cout << '\n';
    }
    cout << "\n";

    return 0;
}