

#include <iostream>
using namespace std;
int main() {
    int n, num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        string s = to_string(num);
        int len = s.length();
        int a = stoi(s.substr(0, len / 2));
        int b = stoi(s.substr(len / 2, len / 2));
        if (a * b != 0 && num % (a * b) == 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

//#include <cstdio>
//#include <string>
//#include <iostream>
//using namespace std;
//
//int main() {
//    int n;
//    string s, s1, s2;
//    scanf("%d", &n);
//    for(int i = 0; i < n; i++) {
//        cin >> s;
//        int len = s.length();
//        s1 = s.substr(0, len / 2);
//        s2 = s.substr(len / 2, len / 2);
//        if(stoi(s) / (stoi(s1)*stoi(s2)) == len / 2 && (stoi(s1)*stoi(s2)) != 0)
//            cout << "Yes" << endl;
//        else
//            cout << "No" << endl;
//    }
//    return 0;
//}
