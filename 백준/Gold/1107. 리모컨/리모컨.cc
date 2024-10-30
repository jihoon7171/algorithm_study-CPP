#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include<climits>
using namespace std;

vector<bool> remote(10, true);

bool checking(int q) {
    string num = to_string(q);
    for (char ch : num) {
        if (!remote[ch - '0']) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;  // 목표 채널
    int a;     
    cin >> a;  // 고장난 버튼 개수

    for (int i = 0; i < a; i++) {
        int temp;
        cin >> temp;
        remote[temp] = false;  // 고장난 버튼은 false로 설정
    }

    
    int diff = abs(100 - n);

    int minPress = INT_MAX;

    for (int i = 0; i <=1000000; i++) {
        if (checking(i)) {  //
            int pressCount = abs(n - i) + to_string(i).size();
            minPress = min(minPress, pressCount);
        }
    }

    int answer = min(diff, minPress);
    cout << answer;
}