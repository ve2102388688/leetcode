#include <bits/stdc++.h>
using namespace std;


/** \brief      backtrack 回溯函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-4
 * 
 *  \param[in] left   左括号数量
 *  \param[in] right  右括号数量
 *  \param[in] track  轨迹
 *  \return           void
 */
vector<string> res;
void backtrack(int left, int right, string& track) {
    if(left < 0 || right < 0)                       /**<数量小于0，不合法*/
        return;
    if(left > right)                                /**<剩下的左括号数量多，不合法 */
        return ;
    if(left == 0 && right == 0) {                   /**<左右括号数量都减至0，答案 */
        res.push_back(track);
        return;
    }

    track.push_back('(');                           /**加入左括号 */
    backtrack(left - 1, right, track);
    track.pop_back();                               /**撤销左括号 */

    track.push_back(')');                           /**加入右括号 */
    backtrack(left, right-1, track);
    track.pop_back();                               /**撤销右括号 */
}

/** \brief      generateParenthesis 括号生成 22
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-4
 * 
 *  \param[in] n  输入数组
 *  \return       返回合法括号组
 */
vector<string>& generateParenthesis(int n) {
    if(n == 0)
        return res;

    string track;
    backtrack(n, n, track);                     /**左、右括号初始值都为n */

    return res;
}

int main(int argc, char *argv[])
{
    vector<string> output = generateParenthesis(3);
    for(const auto& e : output) {
        cout << e << "\n";
    }
    cout << "\n";

    return 0;
}