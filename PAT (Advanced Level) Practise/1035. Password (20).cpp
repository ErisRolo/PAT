/**
* 分析：注意字符串输入输出的问题，gets()被禁用太踏马不方便了
*       此题不能用getline，因为字符串中含有空格，getline遇到空格不结束
*       可用cin或scanf
**/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

struct account {
    string username;
    string password;
    bool flag;
};

int main() {
    int N, count = 0;
    scanf("%d", &N);
    account accounts[N];
    for(int i = 0; i < N; i++) {
        cin >> accounts[i].username;
        cin >> accounts[i].password;
        int len1 = strlen(accounts[i].username);
        int len2 = strlen(accounts[i].password);
        printf("len1=%d len2=%d\n", len1, len2);
        accounts[i].flag = false;
        for(int j = 0; j < accounts[i].password.size(); j++) {
            switch(accounts[i].password[j]) {
            case '1':
                accounts[i].password[j] = '@';
                accounts[i].flag = true;
                break;
            case '0':
                accounts[i].password[j] = '%';
                accounts[i].flag = true;
                break;
            case 'l':
                accounts[i].password[j] = 'L';
                accounts[i].flag = true;
                break;
            case 'O':
                accounts[i].password[j] = 'o';
                accounts[i].flag = true;
                break;
            default:
                break;
            }
        }
        if(accounts[i].flag == true)
            count++;
    }
    if(count == 0) {
        if(N == 1) {
            cout << "There is 1 account and no account is modified";
        } else {
            cout << "There are " << N << " accounts and no account is modified";
        }
    } else {
        cout << count << endl;
        for(int i = 0; i < N; i++) {
            if(accounts[i].flag == true)
                cout << accounts[i].username << " " << accounts[i].password << endl;
        }
    }
    return 0;
}
