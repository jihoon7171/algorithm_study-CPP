#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
using namespace std;

int a, b;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<int> parent(1000000);

int Find(int now) {
    if (parent[now] == now) return now;
   
    return parent[now] = Find(parent[now]);
}

void unions(int x, int y) {
    int rootx = Find(x);
    int rooty = Find(y);
    if (rootx == rooty) return;
    if (x < y) parent[rooty] = rootx;
    else parent[rootx] = rooty;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> a >> b;
    for (int i = 0; i <= a; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < b; i++) {
        int n, m, c;
        cin >> n >> m >> c;
        if (n == 1) {
            if (Find(m) == Find(c)) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        } else if (n == 0) {
            unions(m, c);
        }
    }
}