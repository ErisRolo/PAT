

























//**
//* 分析：给BST，找LCA，一开始在输入的时候，选择先判断大小，交换次序输出，结果只有19分
//*       debug发现一开始的写法，总是认为较大的数可能为根结点，是被样例那个只有左孩子的子树误导了，但如果出现只有右孩子的子树就会出错
//*       所以i应该>=a或者<=b，改正后为20分，debug发现结果对了但输出有错，继续改正，得29分
//*       继续dubug发现两个数相同时输出有错，给出一组实用样例 2 8 7 9 4 -3 0 9
//*       注释部分为不加交换输出更简洁的代码
//**/
//
//#include <bits/stdc++.h>
//using namespace std;
//
//int m, n, x, a, b;
//bool isswap;
//vector<int> tree;
//map<int, bool> mp;
//
//int main() {
//    scanf("%d%d", &m, &n);
//    for(int i = 0; i < n; i++) {
//        scanf("%d", &x);
//        tree.push_back(x);
//        mp[x] = true;
//    }
//    while(m--) {
//        scanf("%d%d", &a, &b);
//        if(mp.find(a) != mp.end() && mp.find(b) != mp.end()) {
//            isswap = false;
//            if(a > b) {
//                swap(a, b);
//                isswap = true;
//            }
//            for(auto i : tree) {
////				if((i>=a&&i<=b)||(i<=a&&i>=b)) {
////					if(i==a||i==b) {
////						if(i==a)
////							printf("%d is an ancestor of %d.\n",a,b);
////						else
////							printf("%d is an ancestor of %d.\n",b,a);
////
////					} else
////						printf("LCA of %d and %d is %d.\n",a,b,i);
////				}
//                if(i >= a && i <= b) {
//                    if(i != a && i != b) {
//                        if(isswap)
//                            printf("LCA of %d and %d is ", b, a);
//                        else
//                            printf("LCA of %d and %d is ", a, b);
//                        printf("%d.\n", i);
//                    } else {
//                        if(i == a)
//                            printf("%d is an ancestor of %d.\n", a, b);
//                        else if(i == b)
//                            printf("%d is an ancestor of %d.\n", b, a);
//                    }
//                    break;
//                }
//            }
//        } else {
//            if(mp.find(a) == mp.end() && mp.find(b) == mp.end()) {
//                printf("ERROR: %d and %d are not found.\n", a, b);
//            } else if(mp.find(a) == mp.end() && mp.find(b) != mp.end()) {
//                printf("ERROR: %d is not found.\n", a);
//            } else if(mp.find(a) != mp.end() && mp.find(b) == mp.end()) {
//                printf("ERROR: %d is not found.\n", b);
//            }
//        }
//    }
//    return 0;
//}
