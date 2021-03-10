#include <bits/stdc++.h>
using namespace std;

/** \brief      wordBreak 单词拆分 139
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-12
 *  \remark     dp[i]，[0,...i-1]能否用dict凑出
 * 
 *  \param[in] s        输入字符串
 *  \param[in] wordDict 输入数组
 *  \return             返回能否用wordDict凑出s
 */
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> memo;
    for (const auto& e : wordDict)
        memo.insert(e);

    int n = s.size();
    vector<bool> dp(n + 1, false);
    /**base case: 空串不需要凑 */
    dp[0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if(dp[j] && memo.count(s.substr(j, i-j))) {         /**<分成两块，前面+后面，后面必须要在字典中 */
                dp[i] = true;
                break;
            }
        } 
    }
    return dp[n];
}

int main(int argc, char *argv[])
{
    vector<string> wordDict = {"apple", "pen"};
    bool output = wordBreak("applepenapple", wordDict);
    std::cout << output << std::endl;

    return 0;
}