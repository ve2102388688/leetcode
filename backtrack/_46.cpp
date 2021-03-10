#include <bits/stdc++.h>
using namespace std;

/** \brief      backtrack 回溯函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-16
 * 
 *  \param[in] nums  输入数组
 *  \param[in] track 路径
 *  \return          void
 */
vector<vector<int>> res;
void backtrack(vector<int> &nums, vector<int> &track) {
    /**<结束条件 */
    if (nums.size() == track.size()) {
        res.push_back(track);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        /**剪枝条件：排除重复的数字 */
        if(find(track.cbegin(), track.cend(), nums[i]) != track.cend())
            continue;
        track.push_back(nums[i]);               /**<做选择 */
        backtrack(nums, track);
        track.pop_back();                       /**<撤销选择 */
    }
}

/** \brief      permute 全排列 46
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-16
 * 
 *  \param[in] nums  输入数组
 *  \return          返回所有排列
 */
vector<vector<int>>& permute(vector<int>& nums) {
    vector<int> track;
    backtrack(nums, track);
    return res;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {1, 2, 3};
    vector<vector<int>> output = permute(nums);
    for (const auto&e : output) {
        for (const auto&i : e)
            std::cout << i << ' ';
        std::cout << '\n';
    }
    cout << "\n";

    return 0;
}