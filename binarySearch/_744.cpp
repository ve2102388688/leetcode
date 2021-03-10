#include <bits/stdc++.h>
using namespace std;

/** \brief      nextGreatestLetter 寻找比目标字母大的最小字母 744
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-3-1
 *  \remark     可能重复，右侧边界查找
 * 
 *  \param[in] nums   输入数组
 *  \param[in] target 输入目标
 *  \return           寻找比目标字母大的最小字母
 */
char nextGreatestLetter(vector<char>& letters, char target) {
    int low = 0, high = letters.size() - 1;
    while (low <= high) {
        int mid = (high + low) / 2;
        if (letters[mid] == target)
            low = mid + 1;                          /**<右侧边界查找 */
        else if (letters[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return letters[(high + 1) % letters.size()];    /**<出while，一定是low>high */
}

int main(int argc, char *argv[])
{
    vector<char> nums1 = {'e', 'e', 'n'};
    char output = nextGreatestLetter(nums1, 'e');
    cout << output << " ";

    cout << "\n";

    return 0;
}