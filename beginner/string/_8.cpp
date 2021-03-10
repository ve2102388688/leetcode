#include <bits/stdc++.h>
using namespace std;

/** \brief      countAndSay  外观数列
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-10
 * 
 *  \param[in] n 输入整数        
 *  \return      返回外观数列
 */
// string countAndSay(int n) {
//     if(n == 1)                                  /**<递归出口 */
//         return "1";

//     string lastResult = countAndSay(n - 1);     /**<上一次的结果 */
//     shared_ptr<string> result = make_shared<string>();

//     int splitPosition = 0;                      /**<不同数字的分割点，总是不同段的开始位置，如1112231，对于的splitPosition分别是0 3 5 6 */
//     int size = lastResult.size();
//     for (int i = 0; i < size; ++i) {
//         if(i == size-1){                        /**<下面的判断只有转折点才会执行，对于平缓的情况是无效的 */
//             result->append(to_string(i-splitPosition+1));
//             result->append(&lastResult[splitPosition], 1);
//         }else if(lastResult[i+1] != lastResult[splitPosition]) {    /**<找到分割点 */
//             result->append(to_string(i-splitPosition+1));           /**<注意下标从0开始，需要加1；追加次数 */
//             result->append(&lastResult[splitPosition], 1);          /**<追加字符；1表示1个字符 */
//             splitPosition = i+1;
//         }
//     }

//     return *result;                             /**<由于返回的值拷贝，所以内存不会泄漏 */
// }

/** \brief      isValid  有效的括号 20
 *  \author     wzk
 *  \copyright  GNU Public License
 *  \version    1.0 
 *  \date       2020-1-10
 * 
 *  \param[in] s 输入字符串       
 *  \return      返回是否有效的括号
 */
// ********** Method1
// bool isValid(string s) {
//     stack<char> brackets;
//     int size = s.size();

//     for(int i = 0; i < size; ){
//         if(s[i] == '(' || s[i] == '[' || s[i] == '{'){                          /**<处理左边--进栈，继续下一个*/
//             brackets.push(s[i++]);
//             continue;
//         }

//         if ((s[i] == ')' && (brackets.empty() || brackets.top() != '(')) ||     /**<处理右边--出栈，注意执行pop和top都需要栈不空 */
//             (s[i] == ']' && (brackets.empty() || brackets.top() != '[')) ||
//             (s[i] == '}' && (brackets.empty() || brackets.top() != '{')) ) {
//             return false;
//         }else{
//             brackets.pop();
//             ++i;
//         }
//     }

//     if(!brackets.empty())                                                       /**<最后栈不空，比如()[,最后[会留在栈中 */
//         return false;

//     return true;
// }

// ********** Method2
// char getChar(stack<char>& sta){
//     char ch = sta.top();
//     sta.pop();
//     return ch;
// }

bool isValid(string s) {
    stack<char> brackets;

    for(const auto& e : s){
        if(e == '(' )    brackets.push(')');
        else if(e == '[') brackets.push(']');
        else if(e == '{') brackets.push('}');
        // else if(brackets.empty() || (e!=getChar(brackets)))
        // else if (brackets.empty() || (e != brackets.top()  brackets.pop()))
            return false;
    }

    if(!brackets.empty())                                                       /**<最后栈不空，比如()[,最后[会留在栈中 */
        return false;

    return true;
}

int main(int argc, char *argv[])
{
    // string output = countAndSay(10);
    bool output = isValid("()");
    std::cout << output << std::endl;

    return 0;
}