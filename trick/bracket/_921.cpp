#include <bits/stdc++.h>
using namespace std;

/** \brief      minAddToMakeValid 使括号有效的最少添加 921
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-24
 * 
 *  \param[in] S  输入括号
 *  \return       最少添加括号数
 */
int minAddToMakeValid2(string& S) {
    int n = 0;

    stack<char> sta;
    for (const auto &e : S) {
        if(e=='(')
            sta.push(e);
        else if (!sta.empty() && sta.top() == '(')
            sta.pop();
        else
            ++n;                                        /**<未匹配的右括号数量 */
    }
    return sta.size() + n;                              /**<未匹配的左括号数量 */
}

int minAddToMakeValid(string& S) {
    int addTimes = 0;
    int match = 0;
    for (const auto& e : S) {
        match += (e == '(') ? 1 : -1;
        if (match == -1) {                              /**<发现左括号 */
            ++addTimes;
            ++match;                                    /**<自动补一个上去 */
        }
    }
    return match + addTimes;                            /**<残留左括号数量 + 补的数量 */
}

int main(int argc, char *argv[])
{
    string nums = "()))((";
    int output = minAddToMakeValid(nums);
    std::cout << output << '\n';

    return 0;
}