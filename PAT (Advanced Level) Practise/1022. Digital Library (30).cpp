/**
* 分析：考查STL的综合使用
*       因为一个ID对应多个信息，题目要求根据除ID外任意信息进行查询，所以要使用map<string,set<int> >
*       因为不同的信息可以对应多个ID，比如作者写了多本书，出版社出版了多本书，是多对多的关系，所以不能直接用int而是要用set<int>
*       另外，卧槽踏马的这道题输入输出上全是坑，详情见代码注释
*
**/

#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
    int n, m;
    int type;
    char c;
    string query;
    int id;
    string title, author, key, pub, year;
    map<string, set<int> > mtitle, mauthor, mkey, mpub, myear;
    set<int>::iterator it;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        //坑一：输入编号id后需要接收空格，否则getline会把换行读入
        scanf("%d\n", &id);
        getline(cin, title);
        mtitle[title].insert(id);
        getline(cin, author);
        mauthor[author].insert(id);
        //坑二：因为可能会读取多个关键词，所以要判断输入的最后一个字符是空格还是换行
        while(cin >> key) {
            mkey[key].insert(id);
            c = getchar();
            if(c == '\n')
                break;
        }
        getline(cin, pub);
        mpub[pub].insert(id);
        getline(cin, year);
        myear[year].insert(id);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d: ", &type);
        getline(cin, query);
        cout << type << ": " << query << endl;
        //坑三：ID必须是7位，即使输入的时候没要求，输出的时候也要用0补齐
        switch(type) {
        case 1:
            if(mtitle.find(query) != mtitle.end()) {
                for(it = mtitle[query].begin(); it != mtitle[query].end(); it++)
                    printf("%07d\n", *it);
            } else {
                printf("Not Found\n");
            }
            break;
        case 2:
            if(mauthor.find(query) != mauthor.end()) {
                for(it = mauthor[query].begin(); it != mauthor[query].end(); it++)
                    printf("%07d\n", *it);
            } else {
                printf("Not Found\n");
            }
            break;
        case 3:
            if(mkey.find(query) != mkey.end()) {
                for(it = mkey[query].begin(); it != mkey[query].end(); it++)
                    printf("%07d\n", *it);
            } else {
                printf("Not Found\n");
            }
            break;
        case 4:
            if(mpub.find(query) != mpub.end()) {
                for(it = mpub[query].begin(); it != mpub[query].end(); it++)
                    printf("%07d\n", *it);
            } else {
                printf("Not Found\n");
            }
            break;
        case 5:
            if(myear.find(query) != myear.end()) {
                for(it = myear[query].begin(); it != myear[query].end(); it++)
                    printf("%07d\n", *it);
            } else {
                printf("Not Found\n");
            }
            break;
        default:
            break;
        }
    }
    return 0;
}
