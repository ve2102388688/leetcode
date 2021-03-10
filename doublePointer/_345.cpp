#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

/** \brief      reverseVowels 反转字符串中的元音字母 345
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-2-25
 * 
 *  \param[in] s   输入字符串
 *  \return        反转字符串中的元音字母
 */
string& reverseVowels(string& s) {
    unordered_set<char> memo({'a','A','e','E','i','I','o','O','u','U'});
    
    int low = 0, high = s.size() - 1;
    while (low < high) {
        while (low < high && memo.count(s[low]) == 0) ++low;
        while (low < high && memo.count(s[high]) == 0) --high;
        char temp = s[low];
        s[low] = s[high];
        s[high] = temp;
        ++low, --high;
    }
    return s;
}

int main(int argc, char *argv[])
{
    string str = "leetcode";
    string output = reverseVowels(str);
    cout << output << " ";

    cout << "\n";

    return 0;
}