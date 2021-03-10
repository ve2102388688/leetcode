#include <bits/stdc++.h>
using namespace std;

/** \brief      reverseString  反转字符串
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-7
 * 
 *  \param[in] s 输入数组         
 *  \return      void
 */
void reverseString(vector<char>& s) {
    // int size = s.size();
    // if(size == 0)
    //     return;

    // for (int i = 0; i < size / 2; i++) {
    //     std::swap(s[i], s[size - 1 - i]);
    // }

    reverse(s.begin(), s.end());
}

int main(int argc, char *argv[])
{
    vector<char> nums = {'a','b','c'};

    reverseString(nums);
    for(const auto& e : nums)
        std::cout << e << " ";
    std::cout << "\n";

    return 0;
}