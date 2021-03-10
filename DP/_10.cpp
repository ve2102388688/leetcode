#include <bits/stdc++.h>
using namespace std;

/** \brief      dp 动态规划函数
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-27
 *  \remark     动态规划，自顶向下+备忘录
 * 
 *  \param[in] text1 输入字符串1
 *  \param[in] i     起始位置1
 *  \param[in] text2 输入字符串2
 *  \param[in] j     起始位置2
 *  \return          返回是否能匹配
 */
unordered_map<string, bool> memo;
bool dp(string &s, int i, string &p, int j) {
    int m = s.size();
    int n = p.size();
    /**<base case */
    if (j == n){                    /**<p结束，若s不结束false */
        return i == m;
    }
    if (i == m) {                   /**<s结束，p必须是以*相隔的偶数个 */
        if ((n-j)%2 == 1)           /**<剩下的必须是成对出现，不是直接false */
            return false;
        for(; j < n ; j +=2){       /**<成对且没对相隔* */
            if(p[j+1] != '*')
                return false;
        }
        return true;
    }
    string key = to_string(i) + ',' + to_string(j);
    if(memo.count(key))
        return memo[key];

    bool res = false;
    if (s[i] == p[j] || p[j] == '.') {
        if (j < n-1 && p[j+1] == '*')
            res = dp(s, i, p, j + 2) || dp(s, i + 1, p, j);
        else
            res = dp(s, i + 1, p, j + 1);
    } else {
        if (j < n-1 && p[j+1] == '*')
            res = dp(s, i, p, j + 2);
        else
            res = false;
    }
    memo[key] = res;

    return res;
}

/** \brief      isMatch 正则表达式匹配 10
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-26
 *  \remark     dp[i+1][j-1]表示s[i+1,...,j-1]的需要最少插入次数
 * 
 *  \param[in] text1 输入字符串1
 *  \param[in] text2 输入字符串2
 *  \return          返回是否能匹配
 */
bool isMatch(string& s, string& p) {
    return dp(s, 0, p, 0);
}

int main(int argc, char *argv[])
{
    string text1("aad");
    string text2("c*a*b");

    int output = isMatch(text1, text2);
    std::cout << output << '\n';

    return 0;
}