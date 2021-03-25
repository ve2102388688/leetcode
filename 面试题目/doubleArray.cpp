#include <bits/stdc++.h>
using namespace std;


void addMatrix(int row, int col, int *a, int *b, int *c) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            c[i*col+j] = a[i*col+j] + b[i*col+j];
        }
    }
}

int main(int argc, char *argv[])
{
    int a[5][1] = {1};
    int b[5][1] = {0};
    int c[5][1] = {0};

    const int s = 5;
    addMatrix(s, 1, a[0], b[0], c[0]);
    //addMatrix(5, 1, (int *)a, (int *)b, (int *)c);
    return 0;
}
