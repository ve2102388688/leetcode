#include <bits/stdc++.h>
using namespace std;

// 验证指针大小问题，这个函数其实已经退化成指针了
int getSize(int data[]) {
    return sizeof(data);
}

int main(int argc, char *argv[])
{
    int data[] = {1,2,3,4,5};
    int size1 = sizeof(data);

    int *data2 = data;
    int size2 = sizeof(data2);
    
    int size3 = sizeof(data2);

    printf("%d, %d, %d\n", size1, size2, size3);

    return 0;
}