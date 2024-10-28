#include <iostream>
#include <vector>
using namespace std;

vector<int> light;

void change(int num) {
    light[num] = 1 - light[num];  // 0과 1을 서로 바꿈
}

int main() {
    int a;
    cin >> a;
    light.resize(a + 1, 0);

    for (int i = 1; i <= a; i++) {
        cin >> light[i];
    }

    int temp;
    cin >> temp;
    vector<pair<int, int>> st(temp);

    for (int i = 0; i < temp; i++) {
        cin >> st[i].first >> st[i].second;
    }

    for (pair<int, int> q : st) {
        int sex = q.first;
        int num = q.second;

        if (sex == 1) {  // 남학생
            for (int i = num; i <= a; i += num) {
                change(i);
            }
        } else if (sex == 2) {  // 여학생
            change(num);
            int count = 1;
            while (num - count > 0 && num + count <= a && light[num - count] == light[num + count]) {
                change(num - count);
                change(num + count);
                count++;
            }
        }
    }

    for (int i = 1; i <= a; i++) {
        cout << light[i] << " ";
        if (i % 20 == 0) {
            cout << "\n";
        }
    }

    return 0;
}