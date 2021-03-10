#include <bits/stdc++.h>
using namespace std;

/** \brief      findLongestWord 通过删除字母匹配到字典里最长单词 524
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-26
 * 
 *  \param[in] s            输入字符串
 *  \param[in] dictionary   输入字典
 *  \return        最长字典顺序最小的字符串
 */
string findLongestWord(string& s, vector<string>& dictionary) {
    string answer = "";
    for (const auto& str : dictionary) {
        for (int i = 0, j = 0; i < s.size(); ++i) {
            if(s[i] == str[j]) ++j;                     /**<相等时子串，移动即可 */
            if(j == str.size())
                if(str.size() > answer.size() || (str.size() == answer.size() && answer > str))
                    answer = str;                       /**<找到新的目标 */
        }
    }
    return answer;
}

int main(int argc, char *argv[])
{
    vector<string> str = {"ale","apple","monkey","plea"};
    string s = "abpcplea";
    string output = findLongestWord(s, str);
    cout << output << " ";

    cout << "\n";

    return 0;
}