#include <bits/stdc++.h>
using namespace std;

void getNext(int *next, const string& s) {
    int size = s.size();
    int j = 0;              /**<j前缀末尾 */
    next[0] = 0;            /**<一个字母没有相等前后缀 */

    /**<i表示后缀末尾 */
    for (int i = 1; i < size; ++i) {
        while (j>0 && s[i]!=s[j])       /**<j需要大于0，因为下标有j-1 */
            j = next[j - 1];            /**<从j-1的回退值开始回退 */
        if (s[i]==s[j])
            ++j;
        next[i] = j;
    }
}

int mystrStr(string& s, string& pattern) {
    int size = pattern.size();
    if (size == 0)
        return 0;

    int next[size];
    getNext(next, pattern);

    int j = 0;
    for (int i = 0; i < s.size(); ++i) {
        while (j>0 && s[i]!=pattern[j])
            j = next[j-1];
        if(s[i] == pattern[j])
            ++j;
        if (j == size)
            return i - size + 1;
    }
    return -1;
}

int main(int argc, char *argv[])
{
    string s = "aabaabaaf";
    string t = "aabaaf";
    int pos = mystrStr(s, t);
    cout << pos << '\n';

    return 0;
}