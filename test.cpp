#include <bits/stdc++.h>
using namespace std;

//这个cmp是先按照a进行降序排序，如果a相同然后对b升序排序，如果b相同最后对c降序排序 
int cmp(const void* a, const void* b)  {
    return ((int*)a)[0] == ((int*)b)[0] ? ((int*)b)[1] > ((int*)a)[1] : ((int*)a)[0] > ((int*)b)[0];
}

int main(void)
{
    /**二维矩阵分块遍历 */
    int k = 0;
    int array[9][9];
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j) {
            int hang = i / 3 * 3 + j / 3;
            int lie = i % 3 * 3 + j % 3 ;
            array[hang][lie] = k++;
        }
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
    }
    cout << '\n';

    /**C++ 二维数组第一列升序，第一列相同第二列降序 */
    vector<vector<int>> v = {{5, 4}, {6, 4}, {6, 7}, {2, 3}, {5, 2}, {1, 8}};
    sort(v.begin(), v.end(), [](const vector<int> &a, const vector<int> &b) { return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0]; });

    for(const auto& e : v){
        for(const auto& i : e) {
            cout << i << ", ";
        }
        cout << '\n';
    }
    cout << '\n';

    /**C 二维数组第一列升序，第一列相同第二列降序 */
    int v2[6][2] = {{5, 4}, {6, 4}, {6, 7}, {2, 3}, {5, 2}, {1, 8}};
    int hang = sizeof(v2) / sizeof(v2[0]);
    qsort(v2, hang, sizeof(v2[0]), cmp);

    int lie = sizeof(v2[0]) / sizeof(v2[0][0]);
    for(int i = 0; i < hang; ++i){
        for(int j = 0; j < lie; ++j) {
            cout << v2[i][j] << ", ";
        }
        cout << '\n';
    }
}