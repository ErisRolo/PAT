#include <bits/stdc++.h>
using namespace std;

vector<int> a, b, c;

void merge_sort(vector<int>& a, int b, int e, int step) {
    for (int i = b; i < e; i += step + step) {
        inplace_merge(a.begin() + i, a.begin() + min(e, i + step), a.begin() + min(e, i + step + step));
    }
}

void insert_sort(vector<int>& a, int b, int e) {
    while (b + 1 < e && a[b] <= a[b + 1])
        ++b;
    if (++b < e) {
        while (b > 0 && a[b] < a[b - 1]) {
            swap(a[b], a[b - 1]);
            --b;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    c.resize(n);
    b.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    a = c;
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        if (a == b) {
            printf("Insertion Sort\n");
            insert_sort(a, 0, n);
            flag = true;
            break;
        }
        insert_sort(a, 0, n);
    }
    if (!flag) {
        a = c;
        printf("Merge Sort\n");
        for (int step = 1; step <= n; step += step) {
            merge_sort(a, 0, n, step);
            if (a == b) {
                merge_sort(a, 0, n, step + step);
                break;
            }
        }
    }
    printf("%d", a[0]);
    for (int i = 1; i < n; ++i) {
        printf(" %d", a[i]);
    }
    printf("\n");
    return 0;
}
