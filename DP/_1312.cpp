#include <bits/stdc++.h>
using namespace std;

/** \brief      minInsertions 让字符串成为回文串的最少插入次数 1312 
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-26
 *  \remark     dp[i+1][j-1]表示s[i+1,...,j-1]的需要最少插入次数
 * 
 *  \param[in] text1 输入字符串1
 *  \return          返回最长回文子序列
 */
int minInsertions(string& s) {
    int size = s.size();

    /**<base case, 主对角线值为0，不需要插入 */
    vector<vector<int>> dp(size, vector<int>(size, 0));

    for (int i = size-2; i >= 0; --i) {
        for (int j = i+1; j < size; ++j) {
            if(s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1];                    /**<两侧字符相等，不用插入 */
            else                                                /**<分类讨论，左侧或者右侧加入字符串，之后在操作一次即可 */
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
        }
    }
    return dp[0][size - 1];                                     /**<结果 */
}


/** \brief      minInsertions 让字符串成为回文串的最少插入次数 1312 
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-26
 *  \remark     dp[i+1][j-1]表示s[i+1,...,j-1]的需要最少插入次数
 *  \remark     状态压缩
 * 
 *  \param[in] text1 输入字符串1
 *  \return          返回最长回文子序列
 */
int minInsertions2(string& s) {
    int size = s.size();

    /**<base case, 主对角线值为0，不需要插入 */
    vector<int> dp(size);

    for (int i = size-2; i >= 0; --i) {
        int pre = 0;
        for (int j = i + 1; j < size; ++j) {
            int temp = dp[j];
            if (s[i] == s[j])
                dp[j] = pre;                                    /**<两侧字符相等，不用插入 */
            else                                                /**<分类讨论，左侧或者右侧加入字符串，之后在操作一次即可 */
                dp[j] = min(dp[j], dp[j - 1]) + 1;
            pre = temp;
        }
    }
    return dp[size-1];                                          /**<结果 */
}

int main(int argc, char *argv[])
{
    string text1("abcea");

    int output = minInsertions2(text1);
    std::cout << output << '\n';

    return 0;
}