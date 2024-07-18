#include <iostream>
#include <vector>
using namespace std;

bool visited[101];
vector<vector<int>> node(101);
int a, b, ans = -1;

void dfs(int temp, int depth) {
    if (b == temp) {
        ans = depth;
        return;
    }
    for (int i = 0; i < node[temp].size(); i++) {
        int next = node[temp][i];
        if (!visited[next]) {
            visited[next] = true;
            dfs(next, depth + 1);
            visited[next] = false; // 백트래킹: 다른 경로 탐색을 위해 방문 표시 해제
        }
    }
}

int main() {
    int n;
    cin >> n;
    cin >> a >> b;
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int one, two;
        cin >> one >> two;
        node[one].push_back(two);
        node[two].push_back(one);
    }

    visited[a] = true;
    dfs(a, 0);

    cout << ans << endl;
    return 0;
}
