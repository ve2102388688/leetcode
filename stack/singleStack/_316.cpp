#include <bits/stdc++.h>
using namespace std;


/** \brief      removeDuplicateLetters 去除重复字母 316
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-17
 * 
 *  \param[in] s   输入字符串
 *  \return        返回结果的字典序最小
 */
string removeDuplicateLetters(string& s) {
    int nums[26] = {0};             /**<统计每个字母出现的次数*/
    for(const auto& e : s)
        nums[e - 'a'] += 1;

    bool visited[26] = {false};                     /**<是否已经在栈中出现，若已经出现过了，直接舍弃，没有出现入单调栈 */
    string sta;                                     /**<string模拟单调栈，单调递增栈，由于需要求解字母顺序最小的 */
    for(const auto& e : s) {
        if(visited[e-'a'] == false) {               /**<如果栈中已经存在，为了保证最小的字典顺序， 直接跳过*/
            while(!sta.empty() && sta.back()>e) {
                /**<什么时候出栈？显然是后面还有的时候 */
                if (nums[sta.back()-'a'] != 0){
                    visited[sta.back() - 'a'] = false;
                    sta.pop_back();
                } else 
                    break;          /**<只出现一次，不可出栈，直接退出 */
            }
            /**<加入栈 */
            sta.push_back(e);
            visited[e - 'a'] = true;
        }
        --nums[e - 'a'];
    }
    return sta;
}

int main(int argc, char *argv[])
{
    string s = "bcabc";
    string output = removeDuplicateLetters(s);
    cout << output << " ";

    cout << "\n";

    return 0;
}