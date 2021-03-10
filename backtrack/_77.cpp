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
    if(track.size() == k) {
        res.push_back(track);
        return;
    }

    for (int i = start; i <= n; ++i) {
        track.push_back(i);                     /**<做选择 */
        backtrack(n, k, i+1, track);
        track.pop_back();                       /**<撤销选择 */
    }
}

/** \brief      combine 组合 77
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-16
 * 
 *  \param[in] n  输入n
 *  \param[in] k  输入k
 *  \return       返回所有组合
 */
vector<vector<int>>& combine(int n, int k) {
    if(n<=0 ||  k<=0)
        return res;
    vector<int> track;
    backtrack(n, k, 1, track);
    return res;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> output = combine(4, 2);
    for (const auto&e : output) {
        for (const auto&i : e)
            std::cout << i << ' ';
        std::cout << '\n';
    }
    cout << "\n";

    return 0;
}