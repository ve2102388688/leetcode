#include <bits/stdc++.h>
using namespace std;

void printNUmber(vector<char>& str) {
    int n = str.size();
    bool isLeadZero = true;
    for (int i = 0; i < n; ++i) {
        if (isLeadZero && str[i]=='0'){
            if (i == n-1)
                cout << 0;
            continue;
        }

        isLeadZero = true;
        cout << str[i];
    }
    cout << '\n';
}

void print1_n_recu(vector<char>& str, int n, int index) {
    if(index == n-1) {
        printNUmber(str);
        return;
    }
    for (int i = 0; i < 10; ++i) {
        str[index+1] = i + '0';
        print1_n_recu(str, n, index+1);
    }
}

void print1_n(int n) {
    if (n<=0)
        return;
    
    vector<char> str(n);
    for (int i = 0; i < 10; ++i) {
        str[0] = i + '0';
        print1_n_recu(str, n, 0);
    }
}

int main(int argc, char *argv[])
{
    print1_n(10);

    return 0;
}