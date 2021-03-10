#include <bits/stdc++.h>
using namespace std;

/** \brief      backtrack 回溯函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-18
 * 
 *  \param[in] nums    输入数组
 *  \param[in] visited 输入访问数组
 *  \param[in] track   路径
 *  \return            void
 */
vector<vector<int>> res;
void backtrack(vector<int> &nums, vector<bool> &visited, vector<int> &track) {
    /**<结束条件 */
    if (nums.size() == track.size()) {
        res.push_back(track);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        /**剪枝条件： 排除重复的数字 */
        if(visited[i] || (i>0 && nums[i]== nums[i-1] && !visited[i-1]))
            continue;
        track.push_back(nums[i]);               /**<做选择 */
        visited[i] = true;
        backtrack(nums, visited, track);
        visited[i] = false;
        track.pop_back();                       /**<撤销选择 */
    }
}

/** \brief      permute 全排列II 47
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-18
 * 
 *  \param[in] nums  输入数组
 *  \return          返回所有排列
 */
vector<vector<int>>& permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());                 /**<对数组进行排序 */
    vector<bool> visited(nums.size(), false);
    
    vector<int> track;
    backtrack(nums, visited, track);
    return res;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {1, 1, 3};
    vector<vector<int>> output = permuteUnique(nums);
    for (const auto&e : output) {
        for (const auto&i : e)
            std::cout << i << ' ';
        std::cout << '\n';
    }
    cout << "\n";

    return 0;
}