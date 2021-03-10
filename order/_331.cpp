#include <bits/stdc++.h>
#include "mycommon.hpp"
using namespace std;

/** \brief      isValidSerialization  验证二叉树的前序序列化 331
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-30
 * 
 *  \param[in] preorder 输入字符串
 *  \return             返会合法的前序线索化
 */
bool isValidSerialization(string& preorder) {
    int size = preorder.size();

    int slots = 1;
    for (int i = 0; i < size; ++i) {
        if(preorder[i] == ',') {
            --slots;                    /**<发现,不管是空结点还是非空结点，都会减1 */

            if(slots < 0)
                return false;

            if(preorder[i-1] != '#')    /**<如果前面是非空结点，+2 */
                slots += 2;
        }
    }
    slots = (preorder[size-1] == '#') ? --slots : ++slots;  /**<最后一个结点没有,要单独处理 */
    return slots == 0;
}

int main(int argc, char *argv[])
{
    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    bool output = isValidSerialization(preorder);
    std::cout << output << '\n';

    return 0;
}