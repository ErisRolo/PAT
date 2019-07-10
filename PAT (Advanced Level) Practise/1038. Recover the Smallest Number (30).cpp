#include <bits/stdc++.h>
using namespace std;

int compare(string a, string b) {
    string ab = a + b;
    string ba = b + a;
    return ab < ba;
}

int main() {
    int N;
    vector<string> nums;
    string buffer;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> buffer;
        nums.push_back(buffer);
    }
    sort(nums.begin(), nums.end(), compare);
    stringstream ss;
    int num;
    // 排除全0情况，先找最大的字符串看是否为0
    ss << nums[nums.size() - 1];
    ss >> num;
    if(num == 0) {
        cout << 0 << endl;
        return 0;
    }
    // 注意清除原来的输入
    ss.clear();
    ss << nums[0];
    ss >> num;
    cout << num;
    for(int i = 1; i < nums.size(); i++) {
        cout << nums[i];
    }
    cout << endl;
    return 0;
}
