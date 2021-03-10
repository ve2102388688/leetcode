#include <bits/stdc++.h>
using namespace std;

/** \brief      backtrack 回溯函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-16
 * 
 *  \param[in] candidates  输入数组
 *  \param[in] target      剩下和
 *  \param[in] start       开始位置的子集
 *  \param[in] track       路径
 *  \return                void
 */
vector<vector<int>> res;
void backtrack(vector<int>& candidates, int target, int start, vector<int>& track) {
    if(target == 0) {           /**<递归出口 */
        res.push_back(track);
        return;
    }
    if (target < 0)             /**<非法目标和 */
        return;

    for (int i = start; i < candidates.size(); ++i){
        track.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], i,track); /**<下一次也是从i开始，允许数字重复 */
        track.pop_back();
    }
}

/** \brief      combinationSum  组合总和39
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-16
 *  \remark     dp[i]，凑出总金额为i需要的最少硬币数量
 * 
 *  \param[in] candidates  输入数组
 *  \param[in] target      输入数组
 *  \return                和为target的所有组合
 */
vector<vector<int>>& combinationSum(vector<int>& candidates, int target) {
    vector<int> track;
    backtrack(candidates, target, 0, track);
    return res;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {2,3,5};
    vector<vector<int>> output = combinationSum(nums, 8);
    for (const auto&e : output) {
        for (const auto&i : e)
            std::cout << i << ' ';
        std::cout << '\n';
    }
    cout << "\n";

    return 0;
}