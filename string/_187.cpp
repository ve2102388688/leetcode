#include <bits/stdc++.h>
using namespace std;

/** \brief      findRepeatedDnaSequences 重复的DNA序列 187
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-13
 * 
 *  \param[in] s  输入字符串
 *  \return       返回只出现1的次数
 */
vector<string> findRepeatedDnaSequences(string& s) {
    vector<string> res;
    int n = s.size();
    if (n <= 10)
        return {};

    unordered_multiset<string> mySet;
    for (int i = 0; i < n-9; ++i) {
        string temp = s.substr(i, 10);
        if(mySet.count(temp) == 1)      /**<已经出现了一次 */
            res.push_back(temp);
        mySet.insert(temp);             /**<每10个切片存进hashset */
    }
    return res;
}

int main(int argc, char *argv[])
{
    // string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    string s = "AAAAAAAAAAAAA";
    vector<string> output = findRepeatedDnaSequences(s);
    for(const auto& e : output) {
        cout << e << " ";
    }
    std::cout << '\n';

    return 0;
}