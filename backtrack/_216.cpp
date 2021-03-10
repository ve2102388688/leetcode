#include <bits/stdc++.h>
using namespace std;

/** \brief      backtrack 回溯函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-16
 * 
 *  \param[in] n  输入n
 *  \param[in] k  输入k
 *  \param[in] start 开始位置
 *  \param[in] track 路径
 *  \return          void
 */
vector<vector<int>> res;
void backtrack(int n, int k, int start, vector<int> &track) {
    /**<结束条件 */
    if(track.size() == k && n == 0) {
        res.push_back(track);
        return;
    }
    if(n < 0)                                  /**<非法目标和 */
        return;

    for (int i = start; i <= 9; ++i) {
        track.push_back(i);                     /**<做选择 */
        backtrack(n-i, k, i+1, track);
        track.pop_back();                       /**<撤销选择 */
    }
}

/** \brief      combinationSum3 组合总和III 216
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-16
 * 
 *  \param[in] k   输入数组
 *  \param[in] n   目标和
 *  \return        返回组合个数
 */
vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> track;
    backtrack(n, k, 1, track);
    return res;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> output = combinationSum3(3, 9);
    for (const auto&e : output) {
        for (const auto&i : e)
            std::cout << i << ' ';
        std::cout << '\n';
    }
    

    return 0;
}